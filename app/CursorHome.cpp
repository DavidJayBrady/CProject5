#include "CursorHome.hpp"

void CursorHome::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    model.setCurrentColumn(1);
}

void CursorHome::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
}

