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
    initializeSharedMemory();
}

SharedMemoryManager::~SharedMemoryManager()
{
    if (data)
    {
        munmap(data, rows * cols);
    }
    if (shmFd != -1)
    {
        shm_unlink("/felix_shm");
    }
}

void SharedMemoryManager::initializeSharedMemory()
{
    shmFd = shm_open("/felix_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shmFd, rows * cols);
    data = static_cast<char*>(mmap(0, rows * cols, PROT_READ | PROT_WRITE, MAP_SHARED, shmFd, 0));
    memset(data, '0', rows * cols);
}
} // namespace FelixRepair
