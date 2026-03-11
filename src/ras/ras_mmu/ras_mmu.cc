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

RASMMU::~RASMMU()
{
    // Can be empty, just needs to exist
}

void
RASMMU::translateTiming(const RequestPtr &req, ThreadContext *tc,
                         BaseMMU::Translation *translation, BaseMMU::Mode mode)
{
    return getTlb(mode)->translateTiming(req, tc, translation, mode);
}


} // namespace X86ISA

} // namespace gem5
