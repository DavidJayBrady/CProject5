#include "CursorDown.hpp"
#include <vector>

#include "NewLine.hpp"

void CursorDown::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    std::vector<std::string>& text = model.giveText();

    if (previousLine == text.size()) {
        throw EditorException{"Already at bottom"};
    }
    else {
        model.setCurrentLine(previousLine+1);
        std::string line = model.giveCurrentLine();
        int lineLength = line.size();
        if (lineLength < previousColumn) {
            model.setCurrentColumn(lineLength+1);
        }
    }
}

void CursorDown::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);
}