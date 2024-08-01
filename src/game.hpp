#pragma once

#include <array>

using Board = std::array<std::array<int, 3>, 3>;
using Coordinate = std::array<int, 2>;
using CoordPlayer = std::array<int, 3>;

class Game
{

private:
        Board m_board{};
        int m_currentPlayer { 1 };

public:

private:

public:
        void update(const CoordPlayer& coord);
        void printBoard();
        bool isValid(const Coordinate& coord);
        friend CoordPlayer playerTurn(Game& game, int ID);
};
