#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#include "cxxpznn1/core.hpp"

BOOST_AUTO_TEST_CASE(test_puzzle_001)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);

    cxxpznn1::Grid grid = puzzle.as_grid();

    int** g = new int*[size+2];
    for (int i = 0; i < size+2; i++)
    {
        g[i] = new int[size+2];
    }

    for (int i = 0; i < size+2; i++)
    {
        for (int j = 0; j < size+2; j++)
        {
            g[i][j] = -1;
        }
    }

    for (int i = 1; i <= size; i++)
    {
        for (int j = 1; j <= size; j++)
        {
            g[i][j] = size * (i-1) + j;
        }
    }

    g[size][size] = 0;

    cxxpznn1::Grid target(size+2, g);

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_002)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Up);

    cxxpznn1::Grid grid = puzzle.as_grid();

    cxxpznn1::Grid target(size+2, cxxpznn1::Puzzle::create_initial_grid(size));

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_003)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Left);

    cxxpznn1::Grid grid = puzzle.as_grid();

    cxxpznn1::Grid target(size+2, cxxpznn1::Puzzle::create_initial_grid(size));

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_004)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Down);

    cxxpznn1::Grid grid = puzzle.as_grid();

    int** g = cxxpznn1::Puzzle::create_initial_grid(size);
    g[3][4] = 0;
    g[4][4] = 12;
    cxxpznn1::Grid target(size+2, g);

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_005)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Right);

    cxxpznn1::Grid grid = puzzle.as_grid();

    int** g = cxxpznn1::Puzzle::create_initial_grid(size);
    g[4][3] = 0;
    g[4][4] = 15;
    cxxpznn1::Grid target(size+2, g);

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_006)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Down);
    puzzle.move(cxxpznn1::Direction::V::Right);
    puzzle.move(cxxpznn1::Direction::V::Up);
    puzzle.move(cxxpznn1::Direction::V::Left);

    cxxpznn1::Grid grid = puzzle.as_grid();

    int** g = cxxpznn1::Puzzle::create_initial_grid(size);
    g[3][3] = 15;
    g[3][4] = 11;
    g[4][3] = 12;
    g[4][4] = 0;
    cxxpznn1::Grid target(size+2, g);

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_007)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Right);
    puzzle.move(cxxpznn1::Direction::V::Right);
    puzzle.move(cxxpznn1::Direction::V::Right);
    puzzle.move(cxxpznn1::Direction::V::Right);

    cxxpznn1::Grid grid = puzzle.as_grid();

    int** g = cxxpznn1::Puzzle::create_initial_grid(size);
    g[4][1] = 0;
    g[4][2] = 13;
    g[4][3] = 14;
    g[4][4] = 15;
    cxxpznn1::Grid target(size+2, g);

    BOOST_CHECK(grid == target);
}

BOOST_AUTO_TEST_CASE(test_puzzle_008)
{
    unsigned int size = 4;
    cxxpznn1::Puzzle puzzle(size);
    puzzle.move(cxxpznn1::Direction::V::Down);
    puzzle.move(cxxpznn1::Direction::V::Down);
    puzzle.move(cxxpznn1::Direction::V::Down);
    puzzle.move(cxxpznn1::Direction::V::Down);

    cxxpznn1::Grid grid = puzzle.as_grid();

    int** g = cxxpznn1::Puzzle::create_initial_grid(size);
    g[1][4] = 0;
    g[2][4] = 4;
    g[3][4] = 8;
    g[4][4] = 12;
    cxxpznn1::Grid target(size+2, g);

    BOOST_CHECK(grid == target);
}
