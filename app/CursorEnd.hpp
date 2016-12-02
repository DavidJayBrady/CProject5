#ifndef CURSOREND_HPP
#define CURSOREND_HPP

#include "Command.hpp"

class CursorEnd : public Command
{
public:
    virtual void execute(EditorModel&) override;
    virtual void undo(EditorModel&) override;
private:
    int previousColumn;
    int previousLine;
};

#endif // CURSOREND_HPP