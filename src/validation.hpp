#pragma once

#include <iostream>
#include <limits>

namespace Validation
{
inline void ignoreLine()
{
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

inline bool clearFailedExtraction()
{
        if (!std::cin)
        {
                if (std::cin.eof())
                {
                        exit(0);
                }

                std::cin.clear();
                ignoreLine();

                return true;
        }
        return false;
}
}