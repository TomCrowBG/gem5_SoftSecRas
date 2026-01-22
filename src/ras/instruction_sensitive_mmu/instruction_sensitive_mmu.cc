#include "ras/instruction_sensitive_mmu/instruction_sensitive_mmu.hh"

namespace gem5
{

namespace X86ISA
{

InstructionSensitiveMMU::InstructionSensitiveMMU(
    const InstructionSensitiveMMUParams& params
):
    BaseMMU(params)
{
    // pass
}

} // namespace X86ISA

} // namespace gem5
