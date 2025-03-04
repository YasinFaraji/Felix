#include "felix.h"

#include <chrono>
#include <iostream>

namespace FelixRepair
{
Felix::Felix(int id, SharedMemoryManager& shm)
    : id(id)
    , shm(shm)
    , process(nullptr)
{
}

void Felix::repair()
{
    while (shm.hasBrokenCells())
    {
        auto [x, y] = shm.getBrokenCell();
        if (x == -1 && y == -1)
        {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        shm.fixCell(x, y);
    }
}
} // namespace FelixRepair