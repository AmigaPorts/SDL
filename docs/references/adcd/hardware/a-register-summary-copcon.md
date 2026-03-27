---
title: A Register Summary / COPCON
manual: hardware
chapter: hardware
section: a-register-summary-copcon
functions: []
libraries: []
---

# A Register Summary / COPCON

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
COPCON     02E      W      A( [E](hardware/c-ecs-hardware-and-graphics-library-interpretational.md) ) Copper control register


                 This is a 1-bit register that when set true, allows
                 the Copper to access the blitter hardware. This
                 bit is cleared by power-on reset, so that the Copper
                 cannot access the blitter hardware. See Appendix C
                 for ECS operation.

                 BIT#    NAME      FUNCTION
                 ----    -------   ------------------
                  01     CDANG     Copper danger mode. Allows Copper
                                   access to blitter if true.
