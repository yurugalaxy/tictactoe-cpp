#pragma once

#include <array>

using BoardArray = std::array<std::array<char, 3>, 3>;
using WinConditions = std::array<int, 8>;
using SquareCoords = std::array<int, 2>;

class TicTacToe
{
private:
        BoardArray m_board;

public:
        enum WinningLine
        {
                rowTop,
                rowMid,
                rowBot,
                colLeft,
                colMid,
                colRight,
                diagRight,
                diagLeft
        };

private:
        bool IsBoardFull(BoardArray board);
        SquareCoords ConvertToCoords(int square);
        int ConvertToSquare(SquareCoords coords);

public:
        BoardArray BoardState(){ return m_board; };
        bool IsSquareValid(int square);
        void PrintBoard(BoardArray board);
        void UpdateBoard(BoardArray board, int square, char side);
        WinConditions TestWinConditions(char side);
        bool DetermineWinner(WinConditions conditions);
};
