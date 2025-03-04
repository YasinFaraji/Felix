#ifndef FELIX_H
#define FELIX_H

#include <memory>
#include <thread>

#include "shared_memory.h"

namespace FelixRepair
{
class Felix
{
  public:
    Felix(int id, SharedMemoryManager& shm);

  private:
    int id;
    SharedMemoryManager& shm;
    std::unique_ptr<std::thread> process;

    void repair();
};
} // namespace FelixRepair

#endif // FELIX_H