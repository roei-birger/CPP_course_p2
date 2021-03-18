#include <string>
#include <iostream>
#include "Board.hpp"

using namespace std;

const char defaultChar = '_';

namespace ariel
{
    Board::Board()
    {
        maxCol = 0;
        maxRow = 0;
    }

    //fill string with "_" 'length' times
    std::string defaultString(unsigned int length)
    {
        string res;

        for (size_t i = 0; i < length; i++)
        {
            res += "_";
        }
        return res;
    }

    void Board::post(unsigned int row, unsigned int column, Direction direction, string message)
    {
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        if (length == 0)
        {
            return "";
        }
        
        if ((v.empty() || row > maxRow || column > maxCol))
        {
            return defaultString(length);
        }

        return "R";
    }
    void Board::show()
    {
    }

}