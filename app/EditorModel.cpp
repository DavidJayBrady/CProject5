// EditorModel.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Love to Play with Words
//
// Implementation of the EditorModel class

#include <vector>
#include <string>
#include "EditorModel.hpp"
#include "Command.hpp"
#include "EditorException.hpp"
#include "BooEditLog.hpp"


EditorModel::EditorModel()
{
    currentColumn = 1;
    currentLine = 1;

    errorMessage = "";
    undoTracker = std::vector<Command*>();

    text = std::vector<std::string>();
    text.push_back("First Line of BooEdit!");
}


int EditorModel::cursorLine() const
{
    return currentLine;
}


int EditorModel::cursorColumn() const
{
    return currentColumn;
}


int EditorModel::lineCount() const
{
    return text.size();
}


const std::string& EditorModel::line(int lineNumber) const
{
    return text[lineNumber-1];
}


const std::string& EditorModel::currentErrorMessage() const
{
    return errorMessage;
}


void EditorModel::setErrorMessage(const std::string& errorMessage)
{
    this->errorMessage = errorMessage;
}


void EditorModel::clearErrorMessage()
{
    errorMessage.clear();
}

void EditorModel::undoLastCommand()
{
    if (undoTracker.size() > 0) {
        Command* c = undoTracker.back();
        undoTracker.pop_back();
        c->undo(*this);
        redoTracker.push_back(c);
    }
}

void EditorModel::redoLastUndo()
{
    if (redoTracker.size() > 0) {
        Command* c = redoTracker.back();
        redoTracker.pop_back();
        c->execute(*this);
        delete c;
    }
}

void EditorModel::setCurrentColumn(int n)
{
    currentColumn = n;
}


void EditorModel::setCurrentLine(int n)
{
    currentLine = n;
}


void EditorModel::addToUndoTracker(Command* c)
{
    undoTracker.push_back(c);
}


unsigned int EditorModel::undoTrackerSize()
{
    return undoTracker.size();
}


unsigned int EditorModel::redoTrackerSize()
{
    return redoTracker.size();
}


std::vector<std::string>& EditorModel::giveText()
{
    return text;
}