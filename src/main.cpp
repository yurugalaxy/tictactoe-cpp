#include "board.hpp"
#include "player.hpp"
#include "game.hpp"

int main()
{
        // Board board;
        // Player playerOne(1, true);
        // Player playerTwo(2, true);
        // Player* playerPtr { &playerOne };
        // bool turnCount { false };

        // while (!board.isWinner(playerPtr))
        // {
                // turnCount = !turnCount;
                // playerPtr = turnCount ? &playerOne : &playerTwo;
                //
                // bool isValid { false };
                //
                // while (!isValid)
                // {
                //         isValid = board.update(
                //                 playerPtr,
                //                 playerPtr->playerTurn());
                // }

                // board.update(&playerOne, 2);
        // }

        Game game{};
        Player playerOne{1};

        game.update(playerOne.playerTurn(game, playerOne.ID()));
        game.printBoard();
        game.update(playerOne.playerTurn(game, playerOne.ID()));
        game.printBoard();
}
