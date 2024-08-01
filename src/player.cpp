#include "player.hpp"
#include "board.hpp"

#include "conversion.hpp"
#include "validation.hpp"
#include "arrayinfo.hpp"
#include "random.hpp"

CoordPlayer Player::playerTurn(Board& game, int ID)
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
        Coordinate coord = Conversion::convert(square);
                if (!game.isValid(coord))
                {
                        std::cout << "That square is taken! Choose another.\n";
                        continue;
                }

        addHistory(square);
        moveSquare(square);
        return { coord[0], coord[1], ID};
        }
}

CoordPlayer Player::computerTurn(Board& game, Player& opponent, int ID)
{
        Coordinate coord { Random::get(0, 2), Random::get(0, 2)};
        int randCorner { 0 };

        // Try to take a random corner
        randCorner = Random::get(0, 3);
        switch (randCorner)
        {
                case 0:
                {
                        if (game.isValid({0, 0}))
                                coord = {0, 0};
                        break;
                }
                case 1:
                {
                        if (game.isValid({0, 2}))
                                coord = {0, 2};
                        break;
                }
                case 2:
                {
                        if (game.isValid({2, 0}))
                                coord = {2, 0};
                        break;
                }
                case 3:
                {
                        if (game.isValid({2, 2}))
                                coord = {2, 2};
                        break;
                }
        }

        //No corners, take a random square
        while (!game.isValid(coord))
        {
                coord = {Random::get(0, 2), Random::get(0, 2)};
        }

        //Overwrite if there's a block opportunity
        checkHistory(game, opponent.history());

        //Overwrite if we're about to win
        checkHistory(game, history());

        int square { Conversion::convert(coord)};

        addHistory(square);
        moveSquare(square);
        return {coord[0], coord[1], ID};
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

bool Player::isWinner()
{
        for (const int &e : history())
        {
                if (e == 3)
                {
                        std::cout << "Player " << ID()
                                  << " wins!!" << '\n';
                        return true;
                }
        }

        return false;
}

Coordinate Player::checkHistory(Board& game, WinConditions history)
{
        Coordinate coord {};

        for (int i { 0 }; i < history.size(); ++i)
        {
                if (history[i] == 2)
                {
                        switch (i)
                        {
                                case 0:
                                {
                                        if (game.isValid({0, 0}))
                                        {
                                                coord = {0, 0};
                                                break;
                                        }

                                        if (game.isValid({0, 1}))
                                        {
                                                coord = {0, 1};
                                                break;
                                        }

                                        if (game.isValid({0, 2}))
                                        {
                                                coord = {0, 2};
                                                break;
                                        }
                                }
                                case 1:
                                {
                                        if (game.isValid({1, 0}))
                                        {
                                                coord = {1, 0};
                                                break;
                                        }

                                        if (game.isValid({1, 1}))
                                        {
                                                coord = {1, 1};
                                                break;
                                        }

                                        if (game.isValid({1, 2}))
                                        {
                                                coord = {1, 2};
                                                break;
                                        }
                                }
                                case 2:
                                {
                                        if (game.isValid({2, 0}))
                                        {
                                                coord = {2, 0};
                                                break;
                                        }

                                        if (game.isValid({2, 1}))
                                        {
                                                coord = {2, 1};
                                                break;
                                        }

                                        if (game.isValid({2, 2}))
                                        {
                                                coord = {2, 2};
                                                break;
                                        }
                                }
                                case 3:
                                {
                                        if (game.isValid({0, 0}))
                                        {
                                                coord = {0, 0};
                                                break;
                                        }

                                        if (game.isValid({1, 0}))
                                        {
                                                coord = {1, 0};
                                                break;
                                        }

                                        if (game.isValid({2, 0}))
                                        {
                                                coord = {2, 0};
                                                break;
                                        }
                                }
                                case 4:
                                {
                                        if (game.isValid({0, 1}))
                                        {
                                                coord = {0, 1};
                                                break;
                                        }

                                        if (game.isValid({1, 1}))
                                        {
                                                coord = {1, 1};
                                                break;
                                        }

                                        if (game.isValid({2, 1}))
                                        {
                                                coord = {2, 1};
                                                break;
                                        }
                                }
                                case 5:
                                {
                                        if (game.isValid({0, 2}))
                                        {
                                                coord = {0, 2};
                                                break;
                                        }

                                        if (game.isValid({1, 2}))
                                        {
                                                coord = {1, 2};
                                                break;
                                        }

                                        if (game.isValid({2, 2}))
                                        {
                                                coord = {2, 2};
                                                break;
                                        }
                                }
                                case 6:
                                {
                                        if (game.isValid({0, 0}))
                                        {
                                                coord = {0, 0};
                                                break;
                                        }

                                        if (game.isValid({1, 1}))
                                        {
                                                coord = {1, 1};
                                                break;
                                        }

                                        if (game.isValid({2, 2}))
                                        {
                                                coord = {2, 2};
                                                break;
                                        }
                                }
                                case 7:
                                {
                                        if (game.isValid({0, 2}))
                                        {
                                                coord = {0, 2};
                                                break;
                                        }

                                        if (game.isValid({1, 1}))
                                        {
                                                coord = {1, 1};
                                                break;
                                        }

                                        if (game.isValid({2, 0}))
                                        {
                                                coord = {2, 0};
                                                break;
                                        }
                                }
                        }
                }
        }
        return coord;
}