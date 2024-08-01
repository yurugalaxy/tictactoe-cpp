#include <iostream>

#include "game.hpp"
#include "arrayinfo.hpp"

void Game::update(const CoordPlayer& coord)
{
        std::cout << coord[0] << coord[1] << coord[2] << '\n';
        m_board[coord[0]][coord[1]] = coord[2];
}

void Game::printBoard()
{
        int count { 1 };
        int row { 1 };
        const int rowTotal { ArrayInfo::rowLength(m_board)};
        const int colTotal { ArrayInfo::colLength(m_board)};

        std::cout << '\n';
        for (auto& arow : m_board)
        {
                int col { 1 };
                for (const auto& acol : arow)
                {
                        switch (acol)
                        {
                        case 1:
                                { std::cout << 'x'; break; }
                        case 2:
                                { std::cout << 'o'; break; }
                        default:
                                std::cout << count;
                        }
                        if (col < colTotal)
                                std::cout << " | ";
                        ++col;
                        ++count;
                }
                if (row < rowTotal)
                        std::cout << "\n--+---+--\n";
                ++row;
        }
        std::cout << "\n\n";
}

bool Game::isValid(const Coordinate& coord)
{
        if (m_board[coord[0]][coord[1]] > 0)
                return false;

        return true;
}
