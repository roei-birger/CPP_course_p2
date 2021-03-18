#pragma once //for once compiling

#include <string>
#include <iostream>
#include <vector>
#include "Direction.hpp"

namespace ariel
{
    class Board
    {
    private:
        /* data */
        std::vector<int> v;
    public:
        Board();

        void post(unsigned int row, int column, Direction direction, std::string message);

        std::string read(unsigned int row, unsigned int column, Direction direction,unsigned int length);

        void show();

        ~Board(){}
    };

    // Board::Board(/* args */)
    // {
    // }

    // Board::~Board()
    // {
    // }

}