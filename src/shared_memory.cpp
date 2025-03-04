#include "shared_memory.h"

#include <cstring>
#include <iostream>
#include <random>

namespace FelixRepair
{
SharedMemoryManager::SharedMemoryManager(size_t rows, size_t cols)
    : rows_(rows)
    , cols_(cols)
    , shmFd_(-1)
    , data_(nullptr)
{
    initializeSharedMemory();
}

SharedMemoryManager::~SharedMemoryManager()
{
    if (data_)
    {
        munmap(data_, rows_ * cols_);
    }
    if (shmFd_ != -1)
    {
        shm_unlink("/felix_shm");
    }
}

void SharedMemoryManager::initializeSharedMemory()
{
    shmFd_ = shm_open("/felix_shm", O_CREAT | O_RDWR, 0666);
    ftruncate(shmFd_, rows_ * cols_);
    data_ = static_cast<char*>(mmap(0, rows_ * cols_, PROT_READ | PROT_WRITE, MAP_SHARED, shmFd_, 0));
    memset(data_, '0', rows_ * cols_);
}

void SharedMemoryManager::initializeMatrix(size_t brokenCells)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, rows_ * cols_ - 1);
    for (size_t i = 0; i < brokenCells; ++i)
    {
        data_[dis(gen)] = 'X';
    }
}

std::pair<int, int> SharedMemoryManager::getBrokenCell()
{
    for (size_t i = 0; i < rows_ * cols_; ++i)
    {
        if (data_[i] == 'X')
        {
            data_[i] = 'I';
            return { i / cols_, i % cols_ };
        }
    }
    return { -1, -1 };
}

void SharedMemoryManager::fixCell(int x, int y)
{
    data_[x * cols_ + y] = 'F';
}

bool SharedMemoryManager::hasBrokenCells()
{
    for (size_t i = 0; i < rows_ * cols_; ++i)
    {
        if (data_[i] == 'X')
        {
            return true;
        }
    }
    return false;
}

void SharedMemoryManager::printMatrix()
{
    for (size_t i = 0; i < rows_; ++i)
    {
        for (size_t j = 0; j < cols_; ++j)
        {
            std::cout << data_[i * cols_ + j] << ' ';
        }
        std::cout << '\n';
    }
}
} // namespace FelixRepair
