---
title: A Register Summary / INTENA, INTENAR
manual: hardware
chapter: hardware
section: a-register-summary-intena-intenar
functions: []
libraries: []
---

# A Register Summary / INTENA, INTENAR

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
INTENA     09A      W       P    Interrupt enable bits (clear or set bits)
INTENAR    01C      R       P    Interrupt enable bits (read)


```c
                 This register contains interrupt enable bits. The bit
                 assignment for both the request and enable registers
                 is given below.

                 BIT#  FUNCT  LEVEL DESCRIPTION
                 ----  ------ ----- ----------------------------------
                 15    SET/CLR     Set/clear control bit. Determines if
                                   bits written with a 1 get set or
                                   cleared. Bits written with a zero
                                   are always unchanged.
                 14    INTEN       Master interrupt (enable only,
                                     no request)
                 13    EXTER   6   External interrupt
                 12    DSKSYN  5   Disk sync register ( [DSKSYNC](hardware/a-register-summary-dsksync.md) )
                                     matches disk data
                 11    RBF     5   Serial port receive buffer full
                 10    AUD3    4   Audio channel 3 block finished
                 09    AUD2    4   Audio channel 2 block finished
                 08    AUD1    4   Audio channel 1 block finished
                 07    AUD0    4   Audio channel 0 block finished
                 06    BLIT    3   Blitter finished
                 05    VERTB   3   Start of vertical blank
                 04    COPER   3   Copper
                 03    PORTS   2   I/O ports and timers
                 02    SOFT    1   Reserved for software-initiated
                                     interrupt
                 01    DSKBLK  1   Disk block finished
                 00    TBE     1   Serial port transmit buffer empty
```
