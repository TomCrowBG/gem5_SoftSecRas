#include "ras/ras_mmu/ras_mmu.hh"

namespace gem5
{

namespace X86ISA
{

RASMMU::RASMMU(
    const RASMMUParams& params
):
    BaseMMU(params)
{
    // pass
}

} // namespace X86ISA

} // namespace gem5
