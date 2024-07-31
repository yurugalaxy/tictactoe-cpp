#include <iostream>

#include "board.hpp"
#include "player.hpp"

int main()
{
        Board board;
        Player playerOne(1, true);
        Player playerTwo(2, true);
        Player* playerPtr { nullptr };
        bool turnCount { true };

        while (true)
        {
                playerPtr = turnCount ? &playerOne : &playerTwo;

                bool isValid { false };

                while (!isValid)
                {
                        isValid = board.update(
                                playerPtr,
                                playerPtr->getInput());
                }

                if (board.isWinner(playerPtr))
                {
                        std::cout << "Player " << playerPtr->ID() << " wins!" << "!\n";
                        break;
                }

                turnCount = !turnCount;
        }
}
