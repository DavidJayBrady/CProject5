#include "BackSpace.hpp"
#include <vector>

#include "NewLine.hpp"

void BackSpace::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    std::vector<std::string>& text = model.giveText();
    std::string& line = text[previousLine - 1];
    // delete a character
    if (previousColumn != 1) {
        charRemoved = line[previousColumn - 2];

        // - 2 because delete left of cursor
        line.erase(line.begin() + previousColumn - 2);

        model.setCurrentColumn(previousColumn - 1);

        removedLine = false;
    }
    // delete a line
    else if (previousColumn == 1 && text.size() > 1)
    {
        text[previousLine-2] += line;

        text.erase(text.begin() + previousLine - 1);

        model.setCurrentColumn(text[previousLine-2].size()+1-line.size());
        model.setCurrentLine(previousLine-1);

        removedLine = true;
    }
    // throw Editor Exception
    else
    {
        throw EditorException{"Already at beginning"};
    }
}

void BackSpace::undo(EditorModel& model)
{
    if (!removedLine) {
        std::vector<std::string> &text = model.giveText();
        std::string &line = text[previousLine - 1];
        line.insert(line.begin() + previousColumn - 2, charRemoved);

        model.setCurrentColumn(previousColumn);
    }
    else {
        // we're here because we need to add line.
        // I've already coded this, no reason to do it again.
        NewLine n = NewLine();
        n.execute(model);
    }
}