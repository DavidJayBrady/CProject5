#include "CursorRight.hpp"

void CursorRight::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    // later, replace this with an intelligent move forward function
    model.setCurrentColumn(previousColumn + 1);
}

void CursorRight::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);
}