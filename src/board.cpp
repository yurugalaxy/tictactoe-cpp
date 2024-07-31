#include <iostream>

#include "board.hpp"
#include "conversion.hpp"
#include "arrayinfo.hpp"

void Board::printBoard()
{
        int count { 1 };
        int row { 1 };
        const int rowTotal { ArrayInfo::rowLength(m_board)};
        const int colTotal { ArrayInfo::colLength(m_board)};

        std::cout << '\n';
        for (auto& arow : m_board)
        {
                int col { 1 };
                for (auto& acol : arow)
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

bool Board::validSquare(const int square, const int side)
{
        const Coordinate coord = Conversion::convert(square);

        if (m_board[coord[0]][coord[1]] > 0)
        {
                std::cout << "That square is taken! Choose another.\n";
                return false;
        }

        updateBoard(coord, side);
        return true;
}

void Board::updateBoard(const Coordinate& coord, const int side)
{
        m_board[coord[0]][coord[1]] = side;
        printBoard();
}