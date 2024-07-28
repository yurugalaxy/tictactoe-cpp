#pragma once

class Player
{
private:
        char m_side{};
        static char currentSide;

public:
        explicit Player(const char side)
                : m_side {side}
        {
        }

        static int TakeTurn();
        char GetSide() const;
};
