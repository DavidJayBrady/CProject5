#include "CursorUp.hpp"
#include <vector>

#include "NewLine.hpp"

void CursorUp::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    if (previousLine == 1) {
        throw EditorException{"Already at top"};
    }
    else {
        model.setCurrentLine(previousLine-1);
        std::string line = model.giveCurrentLine();
        int lineLength = line.size();
        if (lineLength < previousColumn) {
            model.setCurrentColumn(lineLength+1);
        }
    }
}

void CursorUp::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);
}