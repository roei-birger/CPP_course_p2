#include "Board.hpp"
#include "doctest.h"
#include <iostream>
#include <string>

using namespace ariel;
using namespace std;

Board testBoard;

////////// good cases ////////////////////

TEST_CASE("read test board without posts - Horizontal")
{
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 0) == string(""));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 2) == string("__"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 4) == string("____"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 8) == string("________"));
}

TEST_CASE("read test board without posts - Vertical")
{
    CHECK(testBoard.read(0, 0, Direction::Vertical, 0) == string(""));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 1) == string("_"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 2) == string("__"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 4) == string("____"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 8) == string("________"));
}

TEST_CASE("read test board without posts rand pos")
{
    string temp = "";
    for (unsigned int i = 0; i < 100; i++)
    {

        unsigned int x = (unsigned int)rand();
        unsigned int y = (unsigned int)rand();
        unsigned int z = (unsigned int)rand();
        unsigned int w = (unsigned int)rand();
        CHECK(testBoard.read(x, y, Direction::Horizontal, i) == temp);
        CHECK(testBoard.read(z, w, Direction::Vertical, i) == temp);
        temp += "_";
    }
}

TEST_CASE("post - Horizontal")
{
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Horizontal, "?"));
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Horizontal, "post")); //chang (0,0) place
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Horizontal, "post")); //no need to change
    CHECK_NOTHROW(testBoard.post(0, 5, Direction::Horizontal, "roei"));
    CHECK_NOTHROW(testBoard.post(5, 0, Direction::Horizontal, "roei"));
}

TEST_CASE("read after post - Horizontal")
{
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 0) == string(""));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 1) == string("p"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 2) == string("po"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 3) == string("pos"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 4) == string("post"));
    CHECK(testBoard.read(0, 0, Direction::Horizontal, 5) == string("post_"));
    CHECK(testBoard.read(0, 5, Direction::Horizontal, 2) == string("ro"));
    CHECK(testBoard.read(5, 0, Direction::Horizontal, 4) == string("roei"));
}

TEST_CASE("post test board without posts - Vertical")
{
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "!"));    //chang (0,0) place
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "post")); //chang (0,0) place
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "post")); //no need to change
    CHECK_NOTHROW(testBoard.post(0, 10, Direction::Vertical, "roei"));
    CHECK_NOTHROW(testBoard.post(10, 0, Direction::Vertical, "roei"));
}

TEST_CASE("read after post - Vertical")
{
    CHECK(testBoard.read(0, 0, Direction::Vertical, 0) == string(""));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 1) == string("p"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 2) == string("po"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 3) == string("pos"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 4) == string("post"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 5) == string("posr_"));
    CHECK(testBoard.read(0, 10, Direction::Vertical, 2) == string("ro"));
    CHECK(testBoard.read(10, 0, Direction::Vertical, 4) == string("roei"));
}

TEST_CASE("read out of board")
{
    CHECK(testBoard.read(15, 0, Direction::Horizontal, 1) == string("_"));
    CHECK(testBoard.read(0, 15, Direction::Horizontal, 2) == string("__"));
    CHECK(testBoard.read(20, 20, Direction::Horizontal, 3) == string("___"));
    CHECK(testBoard.read(100, 100, Direction::Horizontal, 4) == string("____"));
}

TEST_CASE("post capital letter & other symbols - Vertical")
{
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "!"));    //chang (0,0) place
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "P$ST")); //
    CHECK_NOTHROW(testBoard.post(0, 0, Direction::Vertical, "P$ST")); //no need to change
    CHECK_NOTHROW(testBoard.post(0, 10, Direction::Vertical, "ROE!"));
    CHECK_NOTHROW(testBoard.post(10, 0, Direction::Vertical, "ROE!"));
}

TEST_CASE("read capital letter & other symbols - Vertical")
{
    CHECK(testBoard.read(0, 0, Direction::Vertical, 0) == string(""));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 1) == string("P"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 2) == string("P$"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 3) == string("P$S"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 4) == string("P$ST"));
    CHECK(testBoard.read(0, 0, Direction::Vertical, 5) == string("P$ST_"));
    CHECK(testBoard.read(0, 10, Direction::Vertical, 2) == string("RO"));
    CHECK(testBoard.read(10, 0, Direction::Vertical, 4) == string("ROE!"));
}