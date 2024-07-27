#include <iostream>

#include "game.hpp"

void TicTacToe::PrintBoard()
{
        std::cout << m_board[1] << " | " << m_board[2] << " | " << m_board[3]
                  << "\n--+---+--\n"
                  << m_board[4] << " | " << m_board[5] << " | " << m_board[6]
                  << "\n--+---+--\n"
                  << m_board[7] << " | " << m_board[8] << " | " << m_board[9]
                  << '\n';
}

void TicTacToe::UpdateBoard(const int square, const char side)
{
        m_board[square] = side;
}

bool TicTacToe::DetermineWinner(const char side)
{
        if ((m_board[1] == side && m_board[2] == side && m_board[3] == side)
         || (m_board[4] == side && m_board[5] == side && m_board[6] == side)
         || (m_board[7] == side && m_board[8] == side && m_board[9] == side)
         || (m_board[1] == side && m_board[4] == side && m_board[7] == side)
         || (m_board[2] == side && m_board[5] == side && m_board[8] == side)
         || (m_board[3] == side && m_board[6] == side && m_board[9] == side)
         || (m_board[1] == side && m_board[5] == side && m_board[9] == side)
         || (m_board[3] == side && m_board[5] == side && m_board[7] == side)
           )
        {
                std::cout << "Win!\n";
                return true;
        }
        return false;
}