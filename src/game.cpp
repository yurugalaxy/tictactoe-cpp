#include <iostream>

#include "game.hpp"
#include "player.hpp"

BoardArray TicTacToe::BoardState()
{
        return m_board;
}

void TicTacToe::PrintBoard() const
{
        std::cout << (m_board[0][0]?m_board[0][0]:'1') << " | "
                  << (m_board[0][1]?m_board[0][1]:'2') << " | "
                  << (m_board[0][2]?m_board[0][2]:'3')
                  << "\n--+---+--\n"
                  << (m_board[1][0]?m_board[1][0]:'4') << " | "
                  << (m_board[1][1]?m_board[1][1]:'5') << " | "
                  << (m_board[1][2]?m_board[1][2]:'6')
                  << "\n--+---+--\n"
                  << (m_board[2][0]?m_board[2][0]:'7') << " | "
                  << (m_board[2][1]?m_board[2][1]:'8') << " | "
                  << (m_board[2][2]?m_board[2][2]:'9')
                  << '\n';
}

SquareCoords TicTacToe::ConvertToCoords(const int square)
{
        if (square < 4)
                return{0, square - 1};
        if (square < 7)
                return{1, square - 4};
        return {2, square - 7};
}

int TicTacToe::ConvertToSquare(const SquareCoords coords)
{
        switch (coords[0])
        {
                case 0:
                        return coords[1] + 1;
                case 1:
                        return coords[1] + 4;
                case 2:
                        return coords[1] + 7;
                default:
                        return -1;
        }
}

void TicTacToe::UpdateBoard(const int square, const char side)
{
        const SquareCoords converted = ConvertToCoords(square);
        m_board[converted[0]][converted[1]] = side;
}

bool TicTacToe::isBoardFull()
{
        for (int i {0}; i < 3; ++i)
        {
                for (int j {0}; j < 3; j++)
                {
                        if (!m_board[i][j])
                        {
                                return false;
                        }
                }
        }
        return true;
}

bool TicTacToe::IsSquareValid(const int square)
{
        const SquareCoords converted = ConvertToCoords(square);
        if (m_board[converted[0]][converted[1]])
        {
                return false;
        }
        return true;
}

WinConditions TicTacToe::TestWinConditions(const char side)
{
        int inverse{2};
        WinConditions conditions{};

        for (int i {0}; i < 3; ++i)
        {
                if (m_board[0][i] == side)
                        conditions[rowTop] += 1;
                if (m_board[1][i] == side)
                        conditions[rowMid] += 1;
                if (m_board[2][i] == side)
                        conditions[rowBot] += 1;
                if (m_board[i][0] == side)
                        conditions[colLeft] += 1;
                if (m_board[i][1] == side)
                        conditions[colMid] += 1;
                if (m_board[i][2] == side)
                        conditions[colRight] += 1;
                if (m_board[i][i] == side)
                        conditions[diagRight] += 1;
                if (m_board[i][inverse] == side)
                        conditions[diagLeft] += 1;
                --inverse;
        }
        return conditions;
}

bool TicTacToe::DetermineWinner(const WinConditions& conditions)
{

        if (isBoardFull())
        {
                std::cout << "Draw!\n";
                return true;
        }

        for (const int &e : conditions)
        {
                if (e == 3)
                {
                        std::cout << "Win!\n";
                        return true;
                }
        }
        return false;
}

void playGame()
{
        TicTacToe game;

        bool gameOver{};
        bool isCrossTurn{ true };
        char currentPlayer{ 'x' };
        int currentSquare{};
        WinConditions currConditions{};

        while (!gameOver)
        {
                if (isCrossTurn)
                {
                        currentPlayer = 'x';
                        currentSquare = Player::HumanTurn();
                }
                else
                {
                        currentPlayer = 'o';
                        currentSquare = Player::EmptyCheck(Player::ComputerTurn(currConditions));
                        // currentSquare = Player::ComputerTurn(currConditions);
                }

                game.UpdateBoard(currentSquare, currentPlayer);

                currConditions = game.TestWinConditions(currentPlayer);
                gameOver = game.DetermineWinner(currConditions);

                game.PrintBoard();

                isCrossTurn = !isCrossTurn;
        }
}
