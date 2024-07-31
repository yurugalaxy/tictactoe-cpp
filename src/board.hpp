#pragma once

#include <array>

class Board
{
        using Array2D = std::array<std::array<int, 3>, 3>;
        using Coordinate = std::array<int, 2>;

private:
        Array2D m_board{};

private:
        Array2D getBoard() { return m_board; };
        void updateBoard(const Coordinate& coord, const int side);
        void printBoard();

public:
        bool validSquare(const int square, const int side);
};
