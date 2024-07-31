#pragma once

#include <array>

namespace ArrayInfo
{
        using Array2D = std::array<std::array<int, 3>, 3>;

        int colLength(const Array2D& array) { return array.size(); }
        int rowLength(const Array2D& array) { return array.size(); }
}