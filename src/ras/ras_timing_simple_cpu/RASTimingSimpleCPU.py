from m5.objects.TimingSimpleCPU import TimingSimpleCPU
from m5.params import *


class RASTimingSimpleCPU(TimingSimpleCPU):
    type = "RASTimingSimpleCPU"
    cxx_header = "ras/ras_timing_simple_cpu/ras_timing_simple_cpu.hh"
    cxx_class = "gem5::X86ISA::RASTimingSimpleCPU"

    shadow_stack_size = Param.Int(4096, "Shadow stack size in bytes") # Preferably a size that is a multiple of a memory page (4096 byte)