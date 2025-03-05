#include <cstdlib>
#include <iostream>
#include <vector>

#include "felix.h"
#include "shared_memory.h"

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

    FelixRepair::SharedMemoryManager shm(rows, cols);
    shm.initializeMatrix(brokenCells);

    std::vector<FelixRepair::Felix> felixes;
    for (size_t i = 0; i < numFelixes; ++i)
    {
        felixes.emplace_back(i, shm);
    }

    for (auto& felix : felixes)
    {
        felix.start();
    }

    for (auto& felix : felixes)
    {
        felix.wait();
    }

    shm.printMatrix();

    return 0;
}
