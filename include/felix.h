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

    void start();
    void wait();

  private:
    int id_;
    SharedMemoryManager& shm_;
    std::unique_ptr<std::thread> process_;

    void repair();
};
} // namespace FelixRepair

#endif // FELIX_H