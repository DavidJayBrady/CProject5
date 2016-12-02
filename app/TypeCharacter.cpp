#include "TypeCharacter.hpp"
#include "BooEditLog.hpp"

#include <vector>

TypeCharacter::TypeCharacter(char c)
{
    this->c = c;
}

void TypeCharacter::execute(EditorModel& model)
{
    line = model.cursorLine();
    column = model.cursorColumn();

    std::vector<std::string>& newText = model.giveText();
    newText[line-1].insert(newText[line-1].begin() + column-1, c);

    model.setCurrentColumn(column+1);
}

void TypeCharacter::undo(EditorModel& model)
{
    std::vector<std::string>& text = model.giveText();
    text[line-1].erase(column-1, 1);

    model.setCurrentColumn(column);
}