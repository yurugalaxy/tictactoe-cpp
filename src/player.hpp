#pragma once

#include <array>

#include "game.hpp"

using Coordinate = std::array<int, 2>;
using WinConditions = std::array<int, 8>;
using CoordPlayer = std::array<int, 3>;

class Player
{

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
        int m_playerID{};
        bool m_human{};
        WinConditions m_history{};

public:
        Player(int ID)
                : m_playerID { ID}
        {
        }
        int ID() { return m_playerID; };
        CoordPlayer playerTurn(Game& game, int ID);
};
