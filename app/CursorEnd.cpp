#include "CursorEnd.hpp"
#include "EditorException.hpp"
void CursorEnd::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    const std::string currentLine = model.giveCurrentLine();

    if (previousColumn != currentLine.size()+1) {
        model.setCurrentColumn(currentLine.size()+1);
    }
    else if (currentLine.size() != model.lineCount()) {
        // go to next line. NOT IMPLEMENTED
    }
}

void CursorEnd::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);
}