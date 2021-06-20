#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#include "cxxpznn1/core.hpp"

BOOST_AUTO_TEST_CASE(test_grid_001)
{
    unsigned int size = 4;

    int** a1 = new int*[size];
    for (int i = 0; i < size; i++)
    {
        a1[i] = new int[size];
    }

    int** a2 = new int*[size];
    for (int i = 0; i < size; i++)
    {
        a2[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a1[i][j] = size * i + j;
            a2[i][j] = size * i + j;
        }
    }

    cxxpznn1::Grid g1(size, a1);
    cxxpznn1::Grid g2(size, a2);
    
    BOOST_CHECK(g1 == g2);
}

BOOST_AUTO_TEST_CASE(test_grid_002)
{
    unsigned int s1 = 3;
    unsigned int s2 = 4;

    int** a1 = new int*[s1];
    for (int i = 0; i < s1; i++)
    {
        a1[i] = new int[s1];
    }

    int** a2 = new int*[s2];
    for (int i = 0; i < s2; i++)
    {
        a2[i] = new int[s2];
    }

    for (int i = 0; i < s1; i++)
    {
        for (int j = 0; j < s1; j++)
        {
            a1[i][j] = s1 * i + j;
        }
    }

    for (int i = 0; i < s2; i++)
    {
        for (int j = 0; j < s2; j++)
        {
            a2[i][j] = s2 * i + j;
        }
    }

    cxxpznn1::Grid g1(s1, a1);
    cxxpznn1::Grid g2(s2, a2);
    
    BOOST_CHECK(g1 != g2);
}

BOOST_AUTO_TEST_CASE(test_grid_003)
{
    unsigned int size = 4;

    int** a1 = new int*[size];
    for (int i = 0; i < size; i++)
    {
        a1[i] = new int[size];
    }

    int** a2 = new int*[size];
    for (int i = 0; i < size; i++)
    {
        a2[i] = new int[size];
    }

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            a1[i][j] = size * 2 * i + j;
            a2[i][j] = size * 3 * i + j;
        }
    }

    cxxpznn1::Grid g1(size, a1);
    cxxpznn1::Grid g2(size, a2);
    
    BOOST_CHECK(g1 != g2);
}
