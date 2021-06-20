#define BOOST_TEST_MAIN
#include <boost/test/included/unit_test.hpp>

#include "cxxpznn1/core.hpp"

BOOST_AUTO_TEST_CASE(test_direction_001)
{
    auto dirs = cxxpznn1::Direction::all_directions();

    BOOST_CHECK(dirs.size() == 4);

    BOOST_CHECK(dirs[0] == cxxpznn1::Direction::V::Up);
    BOOST_CHECK(dirs[1] == cxxpznn1::Direction::V::Right);
    BOOST_CHECK(dirs[2] == cxxpznn1::Direction::V::Down);
    BOOST_CHECK(dirs[3] == cxxpznn1::Direction::V::Left);
}

BOOST_AUTO_TEST_CASE(test_direction_002)
{
    cxxpznn1::Direction::V dir = cxxpznn1::Direction::opposite_direction(cxxpznn1::Direction::V::Up);
    BOOST_CHECK(dir == cxxpznn1::Direction::V::Down);
}

BOOST_AUTO_TEST_CASE(test_direction_003)
{
    cxxpznn1::Direction::V dir = cxxpznn1::Direction::opposite_direction(cxxpznn1::Direction::V::Right);
    BOOST_CHECK(dir == cxxpznn1::Direction::V::Left);
}

BOOST_AUTO_TEST_CASE(test_direction_004)
{
    cxxpznn1::Direction::V dir = cxxpznn1::Direction::opposite_direction(cxxpznn1::Direction::V::Down);
    BOOST_CHECK(dir == cxxpznn1::Direction::V::Up);
}

BOOST_AUTO_TEST_CASE(test_direction_005)
{
    cxxpznn1::Direction::V dir = cxxpznn1::Direction::opposite_direction(cxxpznn1::Direction::V::Left);
    BOOST_CHECK(dir == cxxpznn1::Direction::V::Right);
}

BOOST_AUTO_TEST_CASE(test_direction_006)
{
    cxxpznn1::Direction::V dir = cxxpznn1::Direction::opposite_direction(cxxpznn1::Direction::V::Nowhere);
    BOOST_CHECK(dir == cxxpznn1::Direction::V::Nowhere);
}
