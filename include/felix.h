#ifndef FELIX_H
#define FELIX_H

#include <memory>
#include <thread>

#include "shared_memory.h"

namespace FelixRepair
{
class Felix
{
  private:
    int id;
    SharedMemoryManager& shm;
    std::unique_ptr<std::thread> process;
};
} // namespace FelixRepair

#endif // FELIX_H