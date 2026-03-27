<!-- Converted from Motorola M68000 Family Programmer's Reference Manual (1992) -->
# M68000 Family Programmer's Reference Manual

Converted from the official Motorola M68000 Family Programmer's Reference Manual (1992), 646 pages.

## Contents

| File | Section | Description |
|------|---------|-------------|
| [01-introduction.md](01-introduction.md) | Section 1 | Programming model — registers, data formats, organization |
| [02-addressing-modes.md](02-addressing-modes.md) | Section 2 | All addressing modes with effective address encoding |
| [03-instruction-set-overview.md](03-instruction-set-overview.md) | Section 3 | Instruction categories, notation, condition code computation |
| [04-integer-instructions-a.md](04-integer-instructions-a.md) | Section 4 (A-B) | ABCD through BFTST |
| [04-integer-instructions-b.md](04-integer-instructions-b.md) | Section 4 (B-E) | BKPT through EOR |
| [04-integer-instructions-c.md](04-integer-instructions-c.md) | Section 4 (E-N) | EORI through NOT |
| [04-integer-instructions-d.md](04-integer-instructions-d.md) | Section 4 (O-U) | OR through UNLK |
| [05-floating-point.md](05-floating-point.md) | Section 5 | FPU instruction reference (MC68881/MC68882/MC68040) |
| [06-supervisor.md](06-supervisor.md) | Section 6 | Privileged instructions — MMU, cache, exception handling |
| [07-cpu32.md](07-cpu32.md) | Section 7 | CPU32-specific instructions (BGND, LPSTOP, TBLS, etc.) |
| [08-instruction-format.md](08-instruction-format.md) | Section 8 | Binary encoding format and opcode map |
| [appendix-a-processor-summary.md](appendix-a-processor-summary.md) | Appendix A | Instruction × processor availability matrix |
| [appendix-b-exception-frames.md](appendix-b-exception-frames.md) | Appendix B | Exception vector assignments and stack frame formats |

## Quick Reference

**For the perf-optimizer agent:** Section 4 (integer instructions) has timing data per instruction per CPU variant. The four part files cover the full A-Z instruction set.

**For the hardware-expert agent:** Section 1 (programming model), Section 2 (addressing modes), and Appendix B (exception frames) are the key references.

**For the debug-agent:** Appendix B (exception frames) and Section 6 (supervisor instructions) help decode crash data.

## Source

Motorola M68000 Family Programmer's Reference Manual (Includes CPU32 Instructions), Motorola Inc., 1992. ISBN not listed — document number M68000PM/AD REV.1.
