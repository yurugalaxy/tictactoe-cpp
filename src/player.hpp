#pragma once

class Player
{
private:
        char m_side{};
        static char currentSide;

public:
        Player(const char side)
                : m_side {side}
        {
        }

        int TakeTurn();
        char GetSide();
};
