#include "ras/ras_timing_simple_cpu/ras_timing_simple_cpu.hh"

namespace gem5
{

namespace X86ISA
{

RASTimingSimpleCPU::RASTimingSimpleCPU(
    const RASTimingSimpleCPUParams& params
):
    TimingSimpleCPU(params)
{}


void RASTimingSimpleCPU::RASContainer::pushRAS(Addr returnAddress)
{
    // TODO
}

Addr RASTimingSimpleCPU::RASContainer::popRAS()
{
    // TODO
    return Addr();
}

void RASTimingSimpleCPU::RASContainer::setRAS(Addr returnAddress)
{
    // TODO
    // pass
}

} // namespace X86ISA

} // namespace gem5
