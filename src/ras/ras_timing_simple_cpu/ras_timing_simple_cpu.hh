#ifndef __RAS_CPU_SIMPLE_TIMING_HH__
#define __RAS_CPU_SIMPLE_TIMING_HH__

#include "cpu/simple/timing.hh"
#include "base/types.hh"

#include "params/RASTimingSimpleCPU.hh"

namespace gem5
{

namespace X86ISA
{

class RASTimingSimpleCPU : public TimingSimpleCPU
{
public:
    RASTimingSimpleCPU(const RASTimingSimpleCPUParams& params);

     // Microarchitectural register container for return address stack
    struct RASContainer {
        Addr sp;
        Addr base;
        Addr limit;

        void pushRAS(Addr returnAddress);
        Addr popRAS();
        void setRAS(Addr returnAddress);
    };
protected:
    std::vector<RASContainer> rasContainers;
};

} // namespace X86ISA

} // namespace gem5

#endif // __RAS_CPU_SIMPLE_TIMING_HH__