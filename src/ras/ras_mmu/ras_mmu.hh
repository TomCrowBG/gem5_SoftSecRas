#ifndef __RAS_INSTRUCTION_SENSITIVE_MMU_INSTRUCTION_SENSITIVE_MMU_HH__
#define __RAS_INSTRUCTION_SENSITIVE_MMU_INSTRUCTION_SENSITIVE_MMU_HH__

#include "arch/generic/mmu.hh"
#include "arch/x86/page_size.hh"
#include "arch/x86/tlb.hh"
#include "params/RASMMU.hh"

namespace gem5
{

namespace X86ISA
{

class RASMMU: public BaseMMU
{
  public:
    RASMMU(const RASMMUParams& params);
    virtual ~RASMMU();

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

    virtual void
    translateTiming(const RequestPtr &req, ThreadContext *tc,
                    Translation *translation, Mode mode);
};

} // namespace X86ISA

} // namespace gem5

#endif // __RAS_INSTRUCTION_SENSITIVE_MMU_INSTRUCTION_SENSITIVE_MMU_HH__
