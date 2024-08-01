#include "board.hpp"
#include "player.hpp"
#include "game.hpp"

int main()
{

        Game game{};
        Player playerOne { 1, false };
        Player playerTwo { 2, false };
        Player* playerPtr { &playerOne };
        Player* opponentPtr { &playerTwo };
        bool win { false };
        bool currPlayer { false };

        while (true)
        {
                if (playerPtr->isHuman())
                        game.update(
                                playerPtr->playerTurn(
                                game, playerPtr->ID()));
                else
                        game.update(
                                playerPtr->computerTurn(
                                game, *opponentPtr, playerPtr->ID()));
                game.printBoard();

                if (playerPtr->isWinner())
                        break;

                if (game.isFull())
                        break;

                playerPtr = currPlayer ? &playerOne : &playerTwo;
                opponentPtr = currPlayer ? &playerTwo : &playerOne;
                currPlayer = !currPlayer;
        }
}
