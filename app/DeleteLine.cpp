#include "DeleteLine.hpp"
#include <vector>

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
    }
    else
    {
        if (previousLine == text.size()) {
            model.setCurrentLine(model.cursorLine() - 1);
        }
        else if (previousLine < text.size()) {
            if (text[previousLine].size() < previousColumn) {
                model.setCurrentColumn(text[previousLine].size()+1);
            }
        }
        lineDeleted = text[previousLine-1];
        text.erase(text.begin() + previousLine - 1);
    }
}

void DeleteLine::undo(EditorModel& model)
{
    model.setCurrentColumn(previousColumn);
    model.setCurrentLine(previousLine);

    std::vector<std::string>& text = model.giveText();
    // there was only one line
    if (text.size() == 1)
    {
        text[0] += lineDeleted;
    }
    // re-doing first line but there was another line
    else if (text.size() != 1)
    {
        text.insert(text.begin(), lineDeleted);
    }

}