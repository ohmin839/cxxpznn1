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

    class Direction
    {
        public:
            enum class V
            {
                Up = 1,
                Right = 2,
                Down = -1,
                Left = -2,
                Nowhere = 0,
            };
            static std::vector<Direction::V> all_directions();
            static Direction::V opposite_direction(Direction::V dir);
    };
}

#endif
