#include "board.hpp"
#include "player.hpp"

int main()
{
        Board board;
        Player playerOne(1, true);
        Player playerTwo(2, true);
        Player* activePtr { nullptr };
        bool turnCount { true };

        while (true)
        {
                activePtr = turnCount ? &playerOne : &playerTwo;

                bool isValid { false };

                while (!isValid)
                {
                        isValid = board.validSquare(
                                activePtr->getInput(),
                                activePtr->ID());
                }

                turnCount = !turnCount;
        }
}
