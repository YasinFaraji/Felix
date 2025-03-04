#include "felix.h"

#include <iostream>

namespace FelixRepair
{
Felix::Felix(int id, SharedMemoryManager& shm)
    : id(id)
    , shm(shm)
    , process(nullptr)
{
}
} // namespace FelixRepair