#include "NewLine.hpp"
#include <vector>

void NewLine::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();
    std::vector<std::string>& text = model.giveText();

    // Move string by grabbing the stuff after cursor, moving it into
    // next line, and then deleting it from  the previous line.
    std::string& line = text[previousLine-1];
    lineMoved = line.substr(previousColumn-1, line.size()-previousColumn+1);
    line = line.substr(0, previousColumn-1);

    text.push_back(lineMoved);

    model.setCurrentLine(previousLine+1);
    model.setCurrentColumn(1);
}

void NewLine::undo(EditorModel& model)
{
    std::vector<std::string>& text = model.giveText();

    // Wipe the line created from the execute
    text.erase(text.begin() + previousLine);

    // Re-add the text to end of last line.
    text[previousLine-1] += lineMoved;

    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);
}