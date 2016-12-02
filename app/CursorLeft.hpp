#ifndef CURSORLEFT_HPP
#define CURSORLEFT_HPP

#include "Command.hpp"

class CursorLeft : public Command
{
public:
    virtual void execute(EditorModel&) override;
    virtual void undo(EditorModel&) override;
private:
    int previousColumn;
    int previousLine;
};

#endif // CURSORLEFT_HPP