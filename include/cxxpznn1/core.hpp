#if !defined(CXXPZNN1_CORE_HPP)
#define CXXPZNN1_CORE_HPP

#include <iostream>
#include <vector>

namespace cxxpznn1
{
    class Grid
    {
        protected:
            unsigned int size = 0;
            int** grid = nullptr;
        public:
            Grid(unsigned int size, int** grid);
            Grid(const Grid& other);
            ~Grid();
            bool operator==(const Grid& grid);
            bool operator!=(const Grid& grid);
    };
}

#endif
