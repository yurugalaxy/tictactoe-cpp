#include <iostream>

#include "player.hpp"

int Player::TakeTurn()
{
        std::cout << "Choose a square: ";
        int square{};
        std::cin >> square;
        return square;
}

char Player::GetSide()
{
        return m_side;
}
