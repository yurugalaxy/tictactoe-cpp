#pragma once

class Player
{
private:
        int m_playerID {};
        bool m_human {};

public:
        Player(int ID, bool human)
                : m_playerID { ID },
                  m_human { human }
        {}

        int getInput();
        int ID() { return m_playerID; };

};