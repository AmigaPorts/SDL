---
title: 2 Coprocessor Hardware / What is a Copper Instruction?
manual: hardware
chapter: hardware
section: 2-coprocessor-hardware-what-is-a-copper-instruction
functions: []
libraries: []
---

# 2 Coprocessor Hardware / What is a Copper Instruction?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As a coprocessor, the Copper adds its own instruction set to the
instructions already provided by the 680x0 CPU. The Copper has only three
instructions, but you can do a lot with them:

*   [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  for aspecific screen position specified as x and y coordinates.

*   [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  animmediate data value into one of the special-purpose
   registers.

*   [SKIP](hardware/2-advanced-topics-the-skip-instruction.md) . the next instruction if the video beam has already reached
   a specified screen position.

All Copper instructions consist of two 16-bit words in sequential memory
locations. Each time the Copper fetches an instruction, it fetches both
words.

The  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  and  [SKIP](hardware/2-advanced-topics-the-skip-instruction.md) . instructions require two memory cycles and two
instruction words each. Because only the odd memory cycles are requested by
the Copper, four memory cycle times are required per instruction.  The
 [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  instruction requires three memory cycles and six memory cycle
times; it takes one extra memory cycle to wake up.

Although the Copper can directly affect only machine registers, it can also
affect memory indirectly by setting up a blitter operation.  More
information about how to use the Copper in controlling the blitter can be
found in the sections called  [Control Register](hardware/2-using-the-copper-registers-control-register.md)  and
 [Using the Copper with the Blitter](hardware/2-advanced-topics-using-the-copper-with-the-blitter.md) .

The  [WAIT](hardware/2-coprocessor-hardware-the-wait-instruction.md)  and  [MOVE](hardware/2-coprocessor-hardware-the-move-instruction.md)  instructions are described below. The  [SKIP](hardware/2-advanced-topics-the-skip-instruction.md) 
instruction is described in the "Advanced Topics" section.

