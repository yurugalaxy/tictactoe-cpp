#include <iostream>

#include "game.hpp"

void TicTacToe::PrintBoard(const BoardArray board)
{
        std::cout << (board[0][0]?board[0][0]:'1') << " | "
                  << (board[0][1]?board[0][1]:'2') << " | "
                  << (board[0][2]?board[0][2]:'3')
                  << "\n--+---+--\n"
                  << (board[1][0]?board[1][0]:'4') << " | "
                  << (board[1][1]?board[1][1]:'5') << " | "
                  << (board[1][2]?board[1][2]:'6')
                  << "\n--+---+--\n"
                  << (board[2][0]?board[2][0]:'7') << " | "
                  << (board[2][1]?board[2][1]:'8') << " | "
                  << (board[2][2]?board[2][2]:'9')
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

void TicTacToe::UpdateBoard(BoardArray board, const int square, const char side)
{
        const SquareCoords converted = ConvertToCoords(square);
        board[converted[0]][converted[1]] = side;
}

bool TicTacToe::IsBoardFull(BoardArray board)
{
        for (int i {0}; i < 3; ++i)
        {
                for (int j {0}; j < 3; j++)
                {
                        if (!board[i][j])
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

bool TicTacToe::DetermineWinner(const WinConditions conditions)
{

        if (IsBoardFull())
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
