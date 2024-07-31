#pragma once

#include <array>

#include "player.hpp"

class Board
{
        using Array2D = std::array<std::array<int, 3>, 3>;
        using Coordinate = std::array<int, 2>;
        using WinConditions = std::array<int, 8>;

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
        Array2D m_board{};

private:
        Array2D getBoard() { return m_board; };
        void printBoard();

public:
        bool update(Player* playerPtr, const int square);
        bool isWinner(Player* playerPtr);
        bool isFull();
        bool validSquare(const Coordinate& coord);
        friend void Player::addHistory(const int square);
        friend WinConditions Player::history();
        friend int Player::ID();
};
