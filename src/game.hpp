#pragma once

#include <array>

class TicTacToe
{
public:
        std::array<char, 10> m_board
        { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9'};

public:
        void PrintBoard();
        void UpdateBoard(int square, char side);
        bool DetermineWinner(char side);
};
