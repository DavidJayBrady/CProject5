#include "DeleteLine.hpp"


void DeleteLine::execute(EditorModel& model)
{
    previousColumn = model.cursorColumn();
    previousLine = model.cursorLine();

    std::vector<std::string>& text = model.giveText();

    if (text.size() == 1)
    {
        lineDeleted = text[0];
        text[0] = "";
        model.setCurrentColumn(1);
        simple = true;
    }
    else
    {
        if (previousLine == text.size()) {
            model.setCurrentLine(model.cursorLine() - 1);
            if (previousLine > 1) {
                if (text[previousLine-2].size() < previousColumn) {
                    model.setCurrentColumn(text[previousLine-2].size()+1);
                }
            }
        }
        else if (previousLine < text.size()) {
            if (text[previousLine].size() < previousColumn) {
                model.setCurrentColumn(text[previousLine].size()+1);
            }
        }
        lineDeleted = text[previousLine-1];
        text.erase(text.begin() + previousLine - 1);
        simple = false;
    }
}

void DeleteLine::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);

    std::vector<std::string>& text = model.giveText();
    if (simple)
    {
        text[0] += lineDeleted;
    }
    else
    {
        text.insert(text.begin() + previousLine-1, lineDeleted);
    }
}