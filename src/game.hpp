#pragma once

#include <array>

using BoardArray = std::array<std::array<char, 3>, 3>;
using WinConditions = std::array<int, 6>;

class TicTacToe
{
private:
        BoardArray m_board {};

public:
        BoardArray BoardState() const;

private:
        bool isBoardFull();
        static std::array<int, 2> ConvertSquare(int square);

public:
        bool IsValidSquare(int square) const;
        void PrintBoard() const;
        void UpdateBoard(int square, char side);
        std::array<int, 6> TestWinConditions(char side);
        bool DetermineWinner(const WinConditions& conditions);
};

void playGame();