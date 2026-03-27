---
title: 21 / Processor and Cache Control / Condition Code Register
manual: libraries
chapter: libraries
section: 21-processor-and-cache-control-condition-code-register
functions: [GetCC]
libraries: [exec.library]
---

# 21 / Processor and Cache Control / Condition Code Register

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

On the MC68000 a copy of the processor condition codes can be obtained
with the MOVE SR,<ea> instruction.  On MC68010 processors and up however,
the instruction MOVE CCR,<ea> must be used.  Using the specific MC68000
instruction on later processors will cause a 680x0 exception since it is a
privileged instruction on those processors.  The [GetCC()](autodocs-2.0/exec-library-getcc.md) function provides
a processor independent way of obtaining a copy of the condition codes.
For all processors there are 5 bits which can indicate the result of an
integer or a system control instruction:


    X - extend    N - negative    Z - zero    V - overflow    C - carry
The X bit is used for multiprecision calculations. If used, it is copy of
the carry bit.  The other bits state the result of a processor operation.

---

## See Also

- [GetCC — exec.library](../autodocs/exec.library.md#getcc)
