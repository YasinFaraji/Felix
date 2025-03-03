#include <cstdlib>
#include <iostream>

int main(int argc, char* argv[])
{
    size_t rows = 10, cols = 10, numFelixes = 5, brokenCells = 15;
    if (argc == 5)
    {
        rows = std::stoi(argv[1]);
        cols = std::stoi(argv[2]);
        numFelixes = std::stoi(argv[3]);
        brokenCells = std::stoi(argv[4]);
    }

    return 0;
}
