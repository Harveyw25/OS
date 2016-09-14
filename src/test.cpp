#define CATCH_CONFIG_MAIN
#include "catch.hpp"
#include "Command.h"
#include "CommandList.h"
#include "CommandTable.h"

TEST_CASE("Command is created")
{
    Command c("TEST", 0);
    CHECK(c.getCode() == 0);
    CHECK(c.getName() == "TEST");
}

TEST_CASE("Command can set its name")
{
    Command c("TEST", 0);
    CHECK(c.getName() == "TEST");
    c.setName("NEWTEST");
    CHECK(c.getName() == "NEWTEST");
}

TEST_CASE("CommandList can add a valid command")
{
    CommandList c;
    c.addCommand("ver");
    CHECK(c.getList().size() == 1);
}

TEST_CASE("CommandList does not add an invalid command")
{
    CommandList c;
    c.addCommand("v");
    CHECK(c.getList().size() == 0);
}

TEST_CASE("CommandList returns 1 on exit")
{
    CommandList c;
    CHECK(c.addCommand("exit") == 0);
}

TEST_CASE("CommandTable is created")
{
    CommandTable t;
    CHECK(t.getCommandCode("ver") == 1);
}
