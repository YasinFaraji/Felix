#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#include <cstddef>

namespace FelixRepair
{
class SharedMemoryManager
{
  private:
    size_t rows_;
    size_t cols_;
    int shmFd_;
    char* data_;
};
} // namespace FelixRepair

#endif // SHARED_MEMORY_H