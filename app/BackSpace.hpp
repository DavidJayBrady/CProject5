#ifndef BACKSPACE_HPP
#define BACKSPACE_HPP

#include <string>
#include "Command.hpp"

class BackSpace : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    int previousColumn;
    int previousLine;
    char charRemoved;
    bool removedLine;
};

#endif // BACKSPACE_HPP

