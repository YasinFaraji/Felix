#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <cstddef>
#include <sys/mman.h>

namespace FelixRepair
{
class SharedMemoryManager
{
  public:
    SharedMemoryManager(size_t rows, size_t cols);
    ~SharedMemoryManager();

    void initializeMatrix(size_t brokenCells);

  private:
    size_t rows_;
    size_t cols_;
    int shmFd_;
    char* data_;

    void initializeSharedMemory();
};
} // namespace FelixRepair

#endif // SHARED_MEMORY_H