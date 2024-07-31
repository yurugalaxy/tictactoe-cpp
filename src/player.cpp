#include <iostream>

#include "player.hpp"
#include "validation.hpp"

int Player::getInput()
{
        while (true)
        {
        std::cout << "Enter a square to take: ";
        int square {};
        std::cin >> square;

        if (square < 0 || square > 9)
        {
                std::cout << "Please enter a valid square.\n";
                continue;
        }

        if (Validation::clearFailedExtraction())
        {
                std::cout << "Invalid input, try again.\n";
                continue;
        }

        Validation::ignoreLine();
        return square;
        }
}