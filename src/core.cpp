#include "cxxpznn1/core.hpp"

namespace cxxpznn1
{
    // Grid

    Grid::Grid(unsigned int size, int** grid)
    {
        this->size = size;
        this->grid = grid;
    }

    Grid::Grid(const Grid& other)
    {
        this->size = other.size;

        int** grid = new int*[size];
        for (int i = 0; i < size; i++)
        {
            grid[i] = new int[size];
        }

        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                grid[i][j] = other.grid[i][j];
            }
        }

        this->grid = grid;
    }

    Grid::~Grid()
    {
        for (int i = 0; i < size; i++)
        {
            delete [] grid[i];
        }
        delete [] grid;
    }
    
    bool Grid::operator==(const Grid& other)
    {
        if (this->size != other.size)
        {
            return false;
        }

        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                if (this->grid[i][j] != other.grid[i][j])
                {
                    return false;
                }
            }
        }
        return true;
    }

    bool Grid::operator!=(const Grid& other)
    {
        return !(*this == other);
    }

    // Direction
    
    std::vector<Direction::V> Direction::all_directions()
    {
        std::vector<Direction::V> dirs;

        dirs.push_back(Direction::V::Up);
        dirs.push_back(Direction::V::Right);
        dirs.push_back(Direction::V::Down);
        dirs.push_back(Direction::V::Left);

        return dirs;
    }
    
    Direction::V Direction::opposite_direction(Direction::V dir)
    {
        return (Direction::V)(-(int)dir);
    }
}
