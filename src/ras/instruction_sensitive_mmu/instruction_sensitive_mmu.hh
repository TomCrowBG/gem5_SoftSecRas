#ifndef __RAS_INSTRUCTION_SENSITIVE_MMU_INSTRUCTION_SENSITIVE_MMU_HH__
#define __RAS_INSTRUCTION_SENSITIVE_MMU_INSTRUCTION_SENSITIVE_MMU_HH__

#include "arch/generic/mmu.hh"
#include "arch/x86/page_size.hh"
#include "arch/x86/tlb.hh"
#include "params/InstructionSensitiveMMU.hh"

namespace gem5
{

namespace X86ISA
{

class InstructionSensitiveMMU: public BaseMMU
{
  public:
    InstructionSensitiveMMU(const InstructionSensitiveMMUParams& params);

    void
    flushNonGlobal()
    {
        static_cast<TLB*>(itb)->flushNonGlobal();
        static_cast<TLB*>(dtb)->flushNonGlobal();
    }

    Walker*
    getDataWalker()
    {
        return static_cast<TLB*>(dtb)->getWalker();
    }

    TranslationGenPtr
    translateFunctional(Addr start, Addr size, ThreadContext *tc,
            Mode mode, Request::Flags flags) override
    {
        return TranslationGenPtr(new MMUTranslationGen(
                PageBytes, start, size, tc, this, mode, flags));
    }
};

} // namespace X86ISA

} // namespace gem5

#endif // __RAS_INSTRUCTION_SENSITIVE_MMU_INSTRUCTION_SENSITIVE_MMU_HH__
