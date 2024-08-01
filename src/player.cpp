#include "player.hpp"
#include "game.hpp"

#include "conversion.hpp"
#include "validation.hpp"

CoordPlayer Player::playerTurn(Game& game, int ID)
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
        return { coord[0], coord[1], ID};
        }
}
