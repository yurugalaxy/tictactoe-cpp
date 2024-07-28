#pragma once

#include <array>

using BoardArray = std::array<std::array<char, 3>, 3>;

class TicTacToe
{
public:
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
        bool DetermineWinner(char side);
};

void playGame();