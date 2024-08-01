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
        int m_squareInstance { };

public:

private:

public:
        Board(int x)
                : m_squareInstance { x }
        {
        }
        playBoard board() { return m_board; };
        int instance() { return m_squareInstance; };
        void update(const CoordPlayer& coord);
        void printBoard();
        bool isValid(const Coordinate& coord);
        bool isFull();
        friend CoordPlayer playerTurn(Board& game, int ID);
        friend CoordPlayer computerTurn(Board& game, Player& opponent, int ID);
        friend Coordinate checkHistory(Board& game, WinConditions history);
};
