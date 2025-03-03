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
    void fixCell(int x, int y);
    bool hasBrokenCells();
    void printMatrix();

  private:
    size_t rows;
    size_t cols;
    int shmFd;
    char* data;

    void initializeSharedMemory();
};
} // namespace FelixRepair

#endif // SHARED_MEMORY_H