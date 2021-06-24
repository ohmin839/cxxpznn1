#include <iostream>
#include <boost/program_options.hpp>

#include "cxxpznn1/core.hpp"

namespace po = boost::program_options;

int main(int argc, char *argv[])
{
    // options config
    unsigned int opt;
    po::options_description desc("Allowed options");
    desc.add_options()
        ("size", po::value<unsigned int>(&opt)->default_value(4), "size of puzzle")
        ("shuffles", po::value<unsigned int>(&opt)->default_value(80), "count of shuffles")
        ;

    po::variables_map vm;
    po::store(po::parse_command_line(argc, argv, desc), vm);
    po::notify(vm);

    // options parsing
    unsigned int size;
    unsigned int shuffles;
    if (vm.count("size"))
    {
        size = vm["size"].as<unsigned int>();
    }
    if (vm.count("shuffles"))
    {
        shuffles = vm["shuffles"].as<unsigned int>();
    }

    // start game
    cxxpznn1::Puzzle pz(size);
    pz.shuffle(shuffles);

    unsigned int steps = 0;
    std::cout << pz << std::endl;

    while (true)
    {
        std::string key;
        std::getline(std::cin, key);

        if (key == "w")
        {
            pz.move(cxxpznn1::Direction::V::Up);
        }
        else if (key == "d")
        {
            pz.move(cxxpznn1::Direction::V::Right);
        }
        else if (key == "s")
        {
            pz.move(cxxpznn1::Direction::V::Down);
        }
        else if (key == "a")
        {
            pz.move(cxxpznn1::Direction::V::Left);
        }
        else if (key == "q")
        {
            std::cout << "Aborted." << std::endl;
            break;
        }
        else
        {
            continue;
        }

        std::cout << pz << std::endl;
        steps++;

        if (pz.completed())
        {
            std::cout << "Completed!!(" << steps << " steps)" << std::endl;
            break;
        }
    }

    return 0;
}
