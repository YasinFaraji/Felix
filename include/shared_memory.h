#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <cstddef>
#include <fcntl.h>
#include <sys/mman.h>
#include <unistd.h>
#include <utility>

namespace FelixRepair
{
class SharedMemoryManager
{
  public:
    SharedMemoryManager(size_t rows, size_t cols);
    ~SharedMemoryManager();

    void initializeMatrix(size_t brokenCells);
    std::pair<int, int> getBrokenCell();
    void printMatrix();

  private:
    size_t rows_;
    size_t cols_;
    int shmFd_;
    char* data_;

    void initializeSharedMemory();
};
} // namespace FelixRepair

#endif // SHARED_MEMORY_H