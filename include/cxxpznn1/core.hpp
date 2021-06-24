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
            virtual ~Grid();
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

    class Puzzle: Grid
    {
        private:
            unsigned int empty_row = 0;
            unsigned int empty_col = 0;
        public:
            static int** create_initial_grid(unsigned int size);
            Puzzle(unsigned int size);
            ~Puzzle();
            unsigned int size_as_puzzle();
            bool movable(Direction::V dir);
            void move(Direction::V dir);
            std::vector<Direction::V> movable_directions();
            Direction::V move_random(Direction::V prev_dir);
            void shuffle(unsigned int shuffles);
            bool completed();
            Grid as_grid();
            friend std::ostream &operator<<(std::ostream& out, const Puzzle& pz);
    };
}

#endif
