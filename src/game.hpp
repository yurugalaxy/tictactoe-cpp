#pragma once

#include "board.hpp"
#include "player.hpp"

class Game
{
private:
        int m_instance {};

public:
        Board board {};
        int instance() { return m_instance; }
        Player playerOne {1, true};
        Player playerTwo { 2, true };
        Player* playerPtr { &playerOne };
        Player* opponentPtr { &playerTwo };
        bool currPlayer { false };
        bool win { false };

        explicit Game(int instance)
                : m_instance { instance }
{
}
        int play();
};