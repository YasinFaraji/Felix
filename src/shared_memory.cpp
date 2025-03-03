#include "shared_memory.hpp"

#include <iostream>

namespace FelixRepair
{
SharedMemoryManager::SharedMemoryManager(size_t rows, size_t cols)
    : rows(rows)
    , cols(cols)
    , shmFd(-1)
    , data(nullptr)
{
}

SharedMemoryManager::~SharedMemoryManager()
{
}
} // namespace FelixRepair
