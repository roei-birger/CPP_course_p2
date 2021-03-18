#pragma once //for once compiling

#include <string>
#include <iostream>
#include <vector>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
        std::vector<std::vector<char>> v;
        unsigned int maxCol;
        unsigned int maxRow;

    public:
        Board();

        void post(unsigned int row,unsigned int column, Direction direction, std::string message);

        std::string read(unsigned int row, unsigned int column, Direction direction, unsigned int length);

        void show();

        ~Board() {}
    };
}