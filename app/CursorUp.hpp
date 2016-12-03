#ifndef CURSORUP_HPP
#define CURSORUP_HPP

#include <string>
#include "Command.hpp"

class CursorUp : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    int previousColumn;
    int previousLine;
};

#endif // CURSORUP_HPP

