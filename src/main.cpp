#include <iostream>

#include "board.hpp"
#include "player.hpp"

int main()
{
        Board board;
        Player playerOne(1, true);
        Player playerTwo(2, true);
        Player* playerPtr { &playerOne };
        bool turnCount { true };

        while (!board.isWinner(playerPtr))
        {
                turnCount = !turnCount;
                playerPtr = turnCount ? &playerOne : &playerTwo;

                bool isValid { false };

                while (!isValid)
                {
                        isValid = board.update(
                                playerPtr,
                                playerPtr->playerTurn());
                }
        }
}
