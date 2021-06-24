#include "cxxpznn1/core.hpp"

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <random>

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

        int** grid = new int*[this->size];
        for (int i = 0; i < this->size; i++)
        {
            grid[i] = new int[this->size];
        }

        for(int i = 0; i < this->size; i++)
        {
            for(int j = 0; j < this->size; j++)
            {
                grid[i][j] = other.grid[i][j];
            }
        }

        this->grid = grid;
    }

    Grid::~Grid()
    {
        for (int i = 0; i < this->size; i++)
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

        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
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

    // Puzzle

    int** Puzzle::create_initial_grid(unsigned int size)
    {
        int** grid = new int*[size+2];
        for (int i = 0; i < size+2; i++)
        {
            grid[i] = new int[size+2];
        }
    
        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                grid[i][j] = (i-1) * size + j;
            }
        }

        for (int j = 0; j <= size; j++)
        {
            grid[0][j] = -1;
        }
        for (int i = 0; i <= size; i++)
        {
            grid[i][size+1] = -1;
        }
        for (int j = size+1; j >= 1 ; j--)
        {
            grid[size+1][j] = -1;
        }
        for (int i = size+1; i >= 1 ; i--)
        {
            grid[i][0] = -1;
        }

        grid[size][size] = 0;

        return grid;
    }

    Puzzle::Puzzle(unsigned int size)
        : Grid(size+2, create_initial_grid(size))
    {
        this->empty_row = size;
        this->empty_col = size;
    }

    Puzzle::~Puzzle()
    {
    }

    bool Puzzle::movable(Direction::V dir)
    {
        switch(dir)
        {
            case Direction::V::Up:
                if (grid[this->empty_row+1][this->empty_col] > 0)
                {
                    return true;
                }
                break;
            case Direction::V::Right:
                if (grid[this->empty_row][this->empty_col-1] > 0)
                {
                    return true;
                }
                break;
            case Direction::V::Down:
                if (grid[this->empty_row-1][this->empty_col] > 0)
                {
                    return true;
                }
                break;
            case Direction::V::Left:
                if (grid[this->empty_row][this->empty_col+1] > 0)
                {
                    return true;
                }
                break;
            default:
                return false;
        }
        return false;
    }

    void Puzzle::move(Direction::V dir)
    {
        if (!this->movable(dir))
        {
            return;
        }
        else
        {
            int next_empty_row = this->empty_row;
            int next_empty_col = this->empty_col;
            switch(dir)
            {
                case Direction::V::Up:
                    next_empty_row++;
                    break;
                case Direction::V::Right:
                    next_empty_col--;
                    break;
                case Direction::V::Down:
                    next_empty_row--;
                    break;
                case Direction::V::Left:
                    next_empty_col++;
                    break;
                default:
                    break;
            }
            this->grid[this->empty_row][this->empty_col] = this->grid[next_empty_row][next_empty_col];
            this->grid[next_empty_row][next_empty_col] = 0;

            this->empty_row = next_empty_row;
            this->empty_col = next_empty_col;
        }
    }

    std::vector<Direction::V> Puzzle::movable_directions()
    {
        std::vector<Direction::V> dirs = Direction::all_directions();
        std::vector<Direction::V> out(dirs.size());

        std::copy_if(dirs.begin(), dirs.end(), out.begin(),
                     [this](Direction::V dir){ return this->movable(dir); });

        // erase-remove idiom
        out.erase(std::remove(out.begin(), out.end(), Direction::V::Nowhere), out.end());

        return out;
    }

    Direction::V Puzzle::move_random(Direction::V prev_dir)
    {
        std::vector<Direction::V> dirs = this->movable_directions();

        if (prev_dir != Direction::V::Nowhere) {
            Direction::V opps_dir = Direction::opposite_direction(prev_dir);
            // erase-remove idiom
            dirs.erase(std::remove(dirs.begin(), dirs.end(), opps_dir), dirs.end());
        }

        int length = dirs.size();
        std::random_device rnd;
        int i = rnd() % length;

        this->move(dirs[i]);
        return dirs[i];
    }

    void Puzzle::shuffle(unsigned int shuffles)
    {
        Direction::V prev_dir = Direction::V::Nowhere;
        for (int i = 0; i < shuffles; i++)
        {
            prev_dir = move_random(prev_dir);
        }
    }

    bool Puzzle::completed()
    {
        Puzzle target(this->size-2);
        return *this == target;
    }

    Grid Puzzle::as_grid()
    {
        return *this;
    }

    std::ostream &operator<<(std::ostream& out, const Puzzle& pz)
    {
        unsigned int size = pz.size-2;
        int** grid = pz.grid;

        for (int i = 1; i <= size; i++)
        {
            for (int j = 1; j <= size; j++)
            {
                if (grid[i][j] != 0)
                {
                    out << std::setw(3) << grid[i][j];
                }
                else
                {
                    out << std::setw(3) << " ";
                }
            }
            out << std::endl;
        }

        return out;
    }
}
