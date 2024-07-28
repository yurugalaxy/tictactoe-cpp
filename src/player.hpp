#pragma once
#include "game.hpp"

class Player
{
public:
        static int HumanTurn();
        static int ComputerTurn(const WinConditions& conditions);
        static int EmptyCheck(int square);
};
