#ifndef DELETELINE_HPP
#define DELETELINE_HPP

#include "Command.hpp"
#include <string>

class DeleteLine : public Command
{
public:
    virtual void execute(EditorModel&) override;
    virtual void undo(EditorModel&) override;
private:
    std::string lineDeleted;
    int previousLine;
    int previousColumn;
    bool simple;
};

#endif // DELETELINE_HPP