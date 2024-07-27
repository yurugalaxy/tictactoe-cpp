#include <iostream>

#include "player.hpp"

void ignoreLine()
{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),  '\n');
}

bool clearFailedExtraction()
{
        if (!std::cin)
        {
                if(std::cin.eof())
                {
                        exit(0);
                }

                std::cin.clear();
                ignoreLine();

                return true;
        }
        return false;
}

int Player::TakeTurn()
{
        while(true)
        {
                std::cout << "Choose a square: ";
                int square{};
                std::cin >> square;

                if (clearFailedExtraction() || square < 1 || square > 9)
                {
                        std::cout << "Invalid input, try again.\n";
                        continue;
                }

                ignoreLine();
                return square;
        }
}

char Player::GetSide()
{
        return m_side;
}
