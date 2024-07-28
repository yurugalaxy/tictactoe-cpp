#include <iostream>

#include "game.hpp"

#include "player.hpp"

BoardArray TicTacToe::BoardState() const
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

std::array<int, 2> TicTacToe::ConvertSquare(const int square)
{
        switch (square)
        {
                case 1:
                        return {0,0};
                case 2:
                        return {0,1};
                case 3:
                        return {0,2};
                case 4:
                        return {1,0};
                case 5:
                        return {1,1};
                case 6:
                        return {1,2};
                case 7:
                        return {2,0};
                case 8:
                        return {2,1};
                case 9:
                        return {2,2};
                default:
                        return {3,3};
        }
}

void TicTacToe::UpdateBoard(const int square, const char side)
{
        std::array <int, 2> converted {};
        converted = ConvertSquare(square);
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

bool TicTacToe::DetermineWinner(const char side)
{
        if (isBoardFull())
        {
                std::cout << "Draw!\n";
                return true;
        }
        const std::array arr {side, side, side};
        int inverse{2};
        std::array<int, 6> winCond{};

        for (int i {0}; i < 3; ++i)
        {
                if (m_board[i] == arr)
                        winCond[0] = 3;
                if (m_board[i][0] == side)
                        winCond[1] += 1;
                if (m_board[i][1] == side)
                        winCond[2] += 1;
                if (m_board[i][2] == side)
                        winCond[3] += 1;
                if (m_board[i][i] == side)
                        winCond[4] += 1;
                if (m_board[i][inverse] == side)
                        winCond[5] += 1;
                --inverse;
        }

        for (const int &e : winCond)
        {
                if (e == 3)
                {
                        std::cout << side << " wins!\n";
                        return true;
                }
        }
        return false;
}

void playGame()
{
        TicTacToe game;
        Player playerOne('x');
        Player playerTwo('o');

        bool gameOver{};
        char currentPlayer{ 'x' };

        while (!gameOver)
        {
                if (currentPlayer == 'x')
                {
                        game.UpdateBoard(playerOne.TakeTurn(), currentPlayer);
                        gameOver = game.DetermineWinner(currentPlayer);
                        currentPlayer = 'o';
                } else
                {
                        game.UpdateBoard(playerTwo.TakeTurn(), currentPlayer);
                        gameOver = game.DetermineWinner(currentPlayer);
                        currentPlayer = 'x';
                }
                game.PrintBoard();
        }
}
