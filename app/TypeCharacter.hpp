#ifndef TYPECHARACTER_HPP
#define TYPECHARACTER_HPP

#include "Command.hpp"

class TypeCharacter : public Command
{
public:
    TypeCharacter(char);
    virtual void execute(EditorModel&) override;
    virtual void undo(EditorModel&) override;
private:
    int column;
    int line;
    char c;
};

#endif //TYPECHARACTER_HPP
