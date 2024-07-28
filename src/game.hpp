#pragma once

#include <array>

using BoardArray = std::array<std::array<char, 3>, 3>;
using WinConditions = std::array<int, 8>;
using SquareCoords = std::array<int, 2>;

class TicTacToe
{
private:
        static BoardArray m_board;

public:
        BoardArray BoardState();

        enum WinLine
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
        bool isBoardFull();
        static SquareCoords ConvertToCoords(int square);
        static int ConvertToSquare(SquareCoords coords);

public:
        static bool IsSquareValid(int square);
        void PrintBoard() const;
        void UpdateBoard(int square, char side);
        WinConditions TestWinConditions(char side);
        bool DetermineWinner(const WinConditions& conditions);
};

void playGame();