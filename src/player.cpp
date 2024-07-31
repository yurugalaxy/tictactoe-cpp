#include <iostream>

#include "player.hpp"
#include "validation.hpp"

int Player::playerTurn()
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

int ComputerTurn()
{
        using Array2D = std::array<std::array<int, 3>, 3>;
        return 0;
}

void Player::addHistory(const int square)
{
        if (square < 4)
                m_history[rowTop] += 1;

        if (square > 3 && square < 7)
                m_history[rowMid] += 1;

        if (square > 6)
                m_history[rowBot] += 1;

        if (square == 1 || square == 4 || square == 7)
                m_history[colLeft] += 1;

        if (square == 2 || square == 5 || square == 8)
                m_history[colMid] += 1;

        if (square == 3 || square == 6 || square == 9)
                m_history[colRight] += 1;

        if (square == 1 || square == 5 || square == 9)
                m_history[diagRight] += 1;

        if (square == 3 || square == 5 || square == 7)
                m_history[diagLeft] += 1;
}