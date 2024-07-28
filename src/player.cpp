#include <iostream>

#include "player.hpp"
#include "game.hpp"
#include "random.hpp"

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

int Player::HumanTurn()
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

int Player::ComputerTurn(const WinConditions& conditions)
{
        int square{};
        int targetIndex{};

        for( int i {0}; i < 9; ++i)
        {
                if (conditions[i] == 2)
                {
                        square = i;
                }
        }

        switch (square)
        {
                case 1:
                        return 1;
                case 2:
                        return 4;
                case 3:
                        return 7;
                case 4:
                        return 1;
        }

        std::cout << targetIndex << '\n';
        return square;
}

int Player::EmptyCheck(int square)
{
        switch (square)
        {
                case 1:
                case 2:
                case 3:
                {
                        while (!TicTacToe::IsSquareValid(square))
                        {
                                square += 1;
                        }
                }
                case 4:
                case 5:
                case 6:
                {
                        while (!TicTacToe::IsSquareValid(square))
                        {
                                square += 3;
                        }
                }
        }
        return square;
}