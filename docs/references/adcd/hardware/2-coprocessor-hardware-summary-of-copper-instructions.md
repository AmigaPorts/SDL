---
title: 2 Coprocessor Hardware / Summary of Copper Instructions
manual: hardware
chapter: hardware
section: 2-coprocessor-hardware-summary-of-copper-instructions
functions: []
libraries: []
---

# 2 Coprocessor Hardware / Summary of Copper Instructions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The table below shows a summary of the bit positions for each of the
 [Copper instructions](hardware/2-coprocessor-hardware-what-is-a-copper-instruction.md) . See  [Appendix A](hardware/amiga-hardware-reference-manual-a-register-summary.md)  for a summary of all registers.




```c
             Table 2-2: Copper Instruction Summary


                   Move             Wait             Skip
                   ----             ----             ----
     Bit#       IR1    IR2       IR1    IR2       IR1    IR2
     ----       ---    ---       ---    ---       ---    ---
     15         X      RD15      VP7    BFD       VP7    BFD
     14         X      RD14      VP6    VE6       VP6    VE6
     13         X      RD13      VP5    VE5       VP5    VE5
     12         X      RD12      VP4    VE4       VP4    VE4
     11         X      RD11      VP3    VE3       VP3    VE3
     10         X      RD10      VP2    VE2       VP2    VE2
     09         X      RD09      VP1    VE1       VP1    VE1
     08         DA8    RD08      VP0    VE0       VP0    VE0
     07         DA7    RD07      HP8    HE8       HP8    HE8
     06         DA6    RD06      HP7    HE7       HP7    HE7
     05         DA5    RD05      HP6    HE6       HP6    HE6
     04         DA4    RD04      HP5    HE5       HP5    HE5
     03         DA3    RD03      HP4    HE4       HP4    HE4
     02         DA2    RD02      HP3    HE3       HP3    HE3
     01         DA1    RD01      HP2    HE2       HP2    HE2
     00         0      RD00      1      0         1      1


     X = don't care, but should be a 0 for upward compatibility
     IR1 = first instruction word
     IR2 = second instruction word
     DA = destination address
     RD = RAM data to be moved to destination register
     VP =  [vertical beam position](hardware/2-the-wait-instruction-vertical-beam-position.md)  bit
     HP =  [horizontal beam position](hardware/2-the-wait-instruction-horizontal-beam-position.md)  bit
     VE = enable comparison (mask bit)
     HE = enable comparison (mask bit)
     BFD =  [blitter-finished disable](hardware/2-advanced-topics-using-the-copper-with-the-blitter.md) 
```
   ECS Copper.
   -----------
   For information relating to the Copper in the Enhanced Chip
   Set (ECS), see  [Appendix C](hardware/amiga-hardware-reference-manual-c-enhanced-chip-set.md) .

