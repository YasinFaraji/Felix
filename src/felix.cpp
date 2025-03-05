#include "felix.h"

#include <chrono>
#include <iostream>

namespace FelixRepair
{
Felix::Felix(int id, SharedMemoryManager& shm)
    : id_(id)
    , shm_(shm)
    , process_(nullptr)
{
}

void Felix::start()
{
    process_ = std::make_unique<std::thread>(&Felix::repair, this);
}

void Felix::repair()
{
    while (shm_.hasBrokenCells())
    {
        auto [x, y] = shm_.getBrokenCell();
        if (x == -1 && y == -1)
        {
            break;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
        shm_.fixCell(x, y);
    }
}

void Felix::wait()
{
    if (process_ && process_->joinable())
    {
        process_->join();
    }
}
} // namespace FelixRepair