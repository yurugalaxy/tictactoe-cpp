#pragma once

#include <array>

class Player
{
        using WinConditions = std::array<int, 8>;
        using Coordinate = std::array<int, 2>;

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
        WinConditions m_history{};

public:
        Player(int ID, bool human)
                : m_playerID { ID },
                  m_human { human }
        {}

        int getInput();
        int ID() { return m_playerID; };
        WinConditions history(){ return m_history; };
        void addHistory(const int square);
};