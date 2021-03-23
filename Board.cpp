#include <string>
#include <iostream>
#include <vector>
#include "Board.hpp"

using namespace std;

const char defaultChar = '_';

namespace ariel
{
    Board::Board()
    {
        maxCol = 0;
        maxRow = 0;
        v.push_back(vector<char>(1, '_'));
    }

    //fill string with "_" 'length' times
    std::string defaultString(unsigned int length)
    {
        string res;

        for (size_t i = 1; i <= length; i++)
        {
            res += "_";
        }
        return res;
    }

    void Board::post(unsigned int row, unsigned int column, Direction direction, string message)
    {
        if (message.length() == 0)
        {
            return;
        }

        if (direction == Direction::Horizontal) // ->
        {
            if (column + message.length() > maxCol)
            {
                for (unsigned int i = 0; i < v.size(); i++)
                {
                    for (unsigned int j = maxCol; j < (column + message.length()); j++)
                    {
                        v.at(i).push_back('_');
                    }
                }
            }

            maxCol = v.at(0).size() - 1;

            if (row > maxRow)
            {
                for (unsigned int i = maxRow; i < row; i++)
                {
                    v.push_back(vector<char>(v.at(0).size(), '_'));
                }
            }

            maxRow = v.size() - 1;

            for (unsigned int i = 0; i < message.length(); i++)
            {

                v.at(row).at(column + i) = message.at(i);
            }
        }

        if (direction == Direction::Vertical) // |
        {
            if (column > maxCol)
            {
                for (unsigned int i = 0; i < v.size(); i++)
                {
                    for (unsigned int j = maxCol; j < column; j++)
                    {
                        v.at(i).push_back('_');
                    }
                }
            }

            maxCol = v.at(0).size() - 1;

            if (row + message.length() > maxRow)
            {
                for (unsigned int i = maxRow; i < (row + message.length() - 1); i++)
                {
                    v.push_back(vector<char>(v.at(0).size(), '_'));
                }
            }

            maxRow = v.size() - 1;

            for (unsigned int i = 0; i < message.length(); i++)
            {

                v.at(row + i).at(column) = message.at(i);
            }
        }
    }

    string Board::read(unsigned int row, unsigned int column, Direction direction, unsigned int length)
    {
        if (length == 0 || v.empty() || row > maxRow || column > maxCol)
        {
            return defaultString(length);
        }

        unsigned int wordInBoard = 0;
        ;
        string message;

        if (direction == Direction::Horizontal) // ->
        {
            wordInBoard = min(length, (maxCol - column + 1)); //min(length, wordInBoard)
            for (unsigned int i = 0; i < wordInBoard; i++)
            {
                message += v.at(row).at(column + i);
            }
        }

        if (direction == Direction::Vertical) // |
        {
            wordInBoard = min(length, (maxRow - row + 1)); //min(length, wordInBoard)
            for (unsigned int i = 0; i < wordInBoard; i++)
            {
                message += v.at(row + i).at(column);
            }
        }

        message += defaultString(length - wordInBoard); //completes string with "_" times

        return message;
    }

    void Board::show()
    {
        
        for (unsigned int i = 0; i < maxRow+1; i++)
        {
            for (unsigned int j = 0; j < maxCol+1; j++)
            {
                cout << v.at(i).at(j);
            }
            cout << endl;
        }
    }
}