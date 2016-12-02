// BooEditTests.cpp
//
// ICS 45C Fall 2016
// Project #4: People Just Want to Play with Words
//
// Feel free to write unit tests for BooEdit here.  These are not required
// but you might find this to be a useful way to verify that various parts
// of your program are working.  I've provided a couple of examples, so you
// can see roughly what these tests might look like.  See also the comments
// in TestableBooEdit.hpp for more details about how to use it.

#include <vector>
#include <gtest/gtest.h>
#include "TestableBooEdit.hpp"
#include "Command.hpp"
#include "CursorRight.hpp"


TEST(BooEditTests, cursorBeginsOnLine1)
{
    TestableBooEdit edit{};
    edit.editor().run();

    EXPECT_EQ(1, edit.model().cursorLine());
}


TEST(BooEditTests, cursorBeginsOnColumn1)
{
    TestableBooEdit edit{};
    edit.editor().run();

    EXPECT_EQ(1, edit.model().cursorColumn());
}

TEST(BooEditTests, undoTrackerHoldsCommand)
{
    TestableBooEdit edit{Interaction::command(new CursorRight())};
    edit.editor().run();
    EXPECT_EQ(2, edit.model().cursorColumn());
    EXPECT_EQ(1, edit.model().undoTrackerSize());
}

TEST(BooEditTests, undoWorksAndRedoTrackerHoldsCommand)
{
    TestableBooEdit edit{Interaction::command(new CursorRight()), Interaction::undo()};
    edit.editor().run();
    EXPECT_EQ(1, edit.model().cursorColumn());
    EXPECT_EQ(0, edit.model().undoTrackerSize());
    ASSERT_EQ(1, edit.model().redoTrackerSize());
}

TEST(BooEditTests, redoTrackerDecreaseSizeAfterRedo)
{
    TestableBooEdit edit{Interaction::command(new CursorRight()), Interaction::undo(),
                         Interaction::redo()};
    edit.editor().run();
    EXPECT_EQ(0, edit.model().redoTrackerSize());
}
