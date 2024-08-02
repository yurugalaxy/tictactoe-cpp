#pragma once

#include "board.hpp"
#include "player.hpp"

class Game
{
private:
        int m_instance { };

public:
        Game(int instance)
                : m_instance { instance }
        {}
        int instance() { return m_instance; };
        void play();
};