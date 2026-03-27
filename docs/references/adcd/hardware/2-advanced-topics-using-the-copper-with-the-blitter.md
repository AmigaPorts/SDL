---
title: 2 / Advanced Topics / Using the Copper with the Blitter
manual: hardware
chapter: hardware
section: 2-advanced-topics-using-the-copper-with-the-blitter
functions: []
libraries: []
---

# 2 / Advanced Topics / Using the Copper with the Blitter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the Copper is used to start up a sequence of blitter operations, it
must wait for the blitter-finished interrupt before starting another
blitter operation. Changing blitter registers while the blitter is
operating causes unpredictable results. For just this purpose, the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) 
instruction includes an additional control bit, called BFD (for blitter
finished disable). Normally, this bit is a 1 and only the beam counter
comparisons control the  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md) .

When the BFD bit is a 0, the logic of the Copper  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  instruction is
modified. The Copper will  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  until the beam counter comparison is true
and the blitter has finished. The blitter has finished when the
blitter-finished flag is set. This bit should be unset with caution. It
could possibly prevent some screen displays or prevent objects from being
displayed correctly.

For more information about using the blitter, see
 [Chapter 6, Blitter Hardware](hardware/amiga-hardware-reference-manual-6-blitter-hardware.md) .

