# ADR-001: Target 68030 Minimum CPU

## Status

Accepted

## Date

2026-03-15

## Context

AmigaOS 3.x runs on a range of Motorola 68k CPUs from the 68000 (A500, A600, A2000) through the 68060 (accelerator cards). The question is what minimum CPU to target for libSDL2.

SDL2 is primarily useful for graphical applications that need a framebuffer, and on AmigaOS 3.x that means RTG (Retargetable Graphics) via CyberGraphX or Picasso96. RTG graphics cards are Zorro II/III peripherals that require a 68020 or higher CPU for bus access. In practice, every Amiga with an RTG card has at least a 68030:

- A1200 with accelerator (68030/68040/68060)
- A2000 with CPU card + Zorro RTG card (68030+)
- A3000 (built-in 68030)
- A4000 (built-in 68030 or 68040)
- PiStorm (emulates 68020+)
- Vampire (68080, 68020-compatible)

Stock A500 and A600 machines have a 68000 and no expansion bus for RTG cards. They could only use SDL2 with a future AGA/OCS backend (Phase 6), which is speculative and not the primary target.

## Decision

**Target 68030 as the minimum CPU.** Compile with `-m68020` (which covers 68020/68030 -- GCC does not distinguish between them for code generation).

This means:
1. 32-bit addressing and full 68020 instruction set are available
2. CAS (Compare-and-Swap) instruction is available in the ISA, though we choose not to use it (see ADR-004)
3. Unaligned word access works (68020+ handles it in hardware, unlike 68000)
4. MUL/DIV are 32-bit

## Consequences

### Positive

- Matches the actual hardware profile of every Amiga that can use RTG graphics
- Enables use of 68020+ instructions for better code generation
- Simplifies alignment concerns (68020+ handles unaligned access)
- Covers all accelerator cards, PiStorm, and Vampire setups

### Negative

- Excludes stock A500, A600, and unexpanded A2000 (68000 CPU, no RTG capability)
- A future AGA/OCS backend (Phase 6) would need to be compiled separately with `-m68000` if 68000 support is desired

### Neutral

- FS-UAE testing uses A4000 emulation (68030/68040), which matches the target
- bebbo-gcc defaults to 68000; we override with `-m68020` in the Makefile
