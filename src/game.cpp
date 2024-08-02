#include "game.hpp"

void Game::play()
{
        Board board;
        Player playerOne { 1, true };
        Player playerTwo { 2, true };
        Player* playerPtr { &playerOne };
        Player* opponentPtr { &playerTwo };
        bool win { false };
        bool currPlayer { false };

        while (true)
        {
                if (playerPtr->isHuman())
                        board.update(
                                playerPtr->playerTurn(
                                board, playerPtr->ID()));
                else
                        board.update(
                                playerPtr->computerTurn(
                                board, *opponentPtr, playerPtr->ID()));
                board.printBoard();

                if (playerPtr->isWinner())
                        break;

                if (board.isFull())
                        break;

                playerPtr = currPlayer ? &playerOne : &playerTwo;
                opponentPtr = currPlayer ? &playerTwo : &playerOne;
                currPlayer = !currPlayer;

        }
}