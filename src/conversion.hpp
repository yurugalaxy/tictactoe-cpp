#pragma once

#include <array>

namespace Conversion
{
        using Coordinate = std::array<int, 2>;

        inline Coordinate convert(const int square)
        {
                if (square < 4)
                        return{0, square - 1};
                if (square < 7)
                        return{1, square - 4};
                return {2, square - 7};
        }

        inline int convert(const Coordinate& coord)
        {
                switch (coord[0])
                {
                case 0:
                        return coord[1] + 1;
                case 1:
                        return coord[1] + 4;
                case 2:
                        return coord[1] + 7;
                default:
                        return -1;
        }
        }
}