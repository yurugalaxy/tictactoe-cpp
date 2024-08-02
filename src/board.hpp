#pragma once

#include <array>

class Player;

using playBoard = std::array<std::array<int, 3>, 3>;
using Coordinate = std::array<int, 2>;
using CoordPlayer = std::array<int, 3>;
using WinConditions = std::array<int, 8>;

class Board
{

private:
        playBoard m_board{};
        int m_currentPlayer { 1 };

public:

private:

public:
        playBoard board() { return m_board; };
        void update(const CoordPlayer& coord);
        void printBoard();
        bool isValid(const Coordinate& coord);
        bool isFull();
        friend CoordPlayer playerTurn(Board& game, int ID);
        friend CoordPlayer computerTurn(Board& game, Player& opponent, int ID);
        friend Coordinate checkHistory(Board& game, WinConditions history);
};
