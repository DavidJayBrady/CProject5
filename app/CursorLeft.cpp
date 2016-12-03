#include "CursorLeft.hpp"

void CursorLeft::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    if (previousColumn == 1) {
        throw EditorException{"Can not farther left, maybe I should go up a line?"};
    }
    else {
        // later, replace this with an intelligent move
        model.setCurrentColumn(previousColumn - 1);
    }
}

void CursorLeft::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);
}