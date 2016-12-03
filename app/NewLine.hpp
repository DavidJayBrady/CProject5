#ifndef NEWLINE_HPP
#define NEWLINE_HPP

#include <string>
#include "Command.hpp"

class NewLine : public Command
{
public:
    virtual void execute(EditorModel& model) override;
    virtual void undo(EditorModel& model) override;
private:
    int previousColumn;
    int previousLine;
    std::string lineMoved;
};

#endif // NEWLINE_HPP

