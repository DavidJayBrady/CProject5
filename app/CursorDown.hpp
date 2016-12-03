#ifndef CURSORDOWN_HPP
#define CURSORDOWN_HPP

#include "Command.hpp"
#include <string>

class CursorDown : public Command
{
public:
    virtual void execute(EditorModel&) override;
    virtual void undo(EditorModel&) override;
private:
    int previousColumn;
    int previousLine;
};

#endif // CURSORDOWN_HPP