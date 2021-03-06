#ifndef CURSORRIGHT_HPP
#define CURSORRIGHT_HPP

#include "Command.hpp"

class CursorRight : public Command
{
public:
    virtual void execute(EditorModel&) override;
    virtual void undo(EditorModel&) override;
private:
    int previousColumn;
    int previousLine;
};

#endif // CURSORRIGHT_HPP

