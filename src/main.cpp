#include <iostream>

#include "game.hpp"

static std::array<int, 8> s_overWinCond {};

void addOverHistory(const int square)
{
        enum WinningLine
        {
        rowTop,
        rowMid,
        rowBot,
        colLeft,
        colMid,
        colRight,
        diagRight,
        diagLeft
        };

        if (square < 4)
                s_overWinCond[rowTop] += 1;

        if (square > 3 && square < 7)
                s_overWinCond[rowMid] += 1;

        if (square > 6)
                s_overWinCond[rowBot] += 1;

        if (square == 1 || square == 4 || square == 7)
                s_overWinCond[colLeft] += 1;

        if (square == 2 || square == 5 || square == 8)
                s_overWinCond[colMid] += 1;

        if (square == 3 || square == 6 || square == 9)
                s_overWinCond[colRight] += 1;

        if (square == 1 || square == 5 || square == 9)
                s_overWinCond[diagRight] += 1;

        if (square == 3 || square == 5 || square == 7)
                s_overWinCond[diagLeft] += 1;

        for (int e : s_overWinCond)
        {
                std::cout << e << ' ';
        }
}

bool overWinner()
{
        for (const int &e : s_overWinCond)
        {
                if (e == 3)
                {
                        std::cout << "Player "
                                  << " wins!!" << '\n';
                        return true;
                }
        }

        return false;
}

int main()
{
        Game game1 { 1 };
        Game game2 { 2 };
        Game game3 { 3 };
        Game game4 { 4 };
        Game game5 { 5 };
        Game game6 { 6 };
        Game game7 { 7 };
        Game game8 { 8 };
        Game game9 { 9 };
        Game* currPtr { &game1 };
        int next { 1 };
        int overPlayer { false };
        std::array<int, 2> winLocation {};

        while (true)
                {

                switch (next)
                {
                        case 1:
                                currPtr = &game1;
                                break;
                        case 2:
                                currPtr = &game2;
                                break;
                        case 3:
                                currPtr = &game3;
                                break;
                        case 4:
                                currPtr = &game4;
                                break;
                        case 5:
                                currPtr = &game5;
                                break;
                        case 6:
                                currPtr = &game6;
                                break;
                        case 7:
                                currPtr = &game7;
                                break;
                        case 8:
                                currPtr = &game8;
                                break;
                        case 9:
                                currPtr = &game9;
                                break;
                }

                std::cout << '\n' << "Square " << next << ": \n";

                overPlayer = !overPlayer;

                currPtr->playerPtr =
                        overPlayer ? &currPtr->playerOne : &currPtr->playerTwo;

                currPtr->opponentPtr =
                        overPlayer ? &currPtr->playerTwo : &currPtr->playerOne;

                currPtr->board.printBoard();
                next = currPtr->play();

                int winSquare { currPtr->instance() };
                bool win { currPtr->playerPtr->isWinner() };

                if (win)
                        addOverHistory(winSquare);

                if(overWinner())
                        std::cout << "Win!\n";


                currPtr->playerPtr =
                        overPlayer ? &currPtr->playerOne : &currPtr->playerTwo;

                currPtr->opponentPtr =
                        overPlayer ? &currPtr->playerTwo : &currPtr->playerOne;

                currPtr->currPlayer =
                        overPlayer;
        }
}
