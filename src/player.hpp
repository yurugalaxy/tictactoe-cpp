#pragma once

#include <array>

#include "board.hpp"

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
        int m_playerID {};
        bool m_human {};
        WinConditions m_history {};
        int m_lastSquare {};

public:
        Player(int ID, bool human)
                : m_playerID { ID}
                , m_human { human }
        {
        }
        int ID() { return m_playerID; };
        WinConditions history() { return m_history; };
        void moveSquare(int square) { m_lastSquare = square; };
        int squareToPlay() { return m_lastSquare; };
        CoordPlayer playerTurn(Board& game, int ID);
        CoordPlayer computerTurn(Board& game, Player& opponent, int ID);
        Coordinate checkHistory(Board& game, WinConditions history);
        void addHistory(int square);
        bool isWinner();
        bool isHuman() { return m_human; };
};
