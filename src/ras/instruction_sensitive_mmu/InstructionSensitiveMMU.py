from m5.objects.BaseMMU import BaseMMU
from m5.objects.X86TLB import X86TLB


class InstructionSensitiveMMU(BaseMMU):
    type = "InstructionSensitiveMMU"
    cxx_header = "ras/instruction_sensitive_mmu/instruction_sensitive_mmu.hh"
    cxx_class = "gem5::X86ISA::InstructionSensitiveMMU"
    itb = X86TLB(entry_type="instruction")
    dtb = X86TLB(entry_type="data")

    @classmethod
    def walkerPorts(cls):
        return ["mmu.itb.walker.port", "mmu.dtb.walker.port"]

    def connectWalkerPorts(self, iport, dport):
        self.itb.walker.port = iport
        self.dtb.walker.port = dport
