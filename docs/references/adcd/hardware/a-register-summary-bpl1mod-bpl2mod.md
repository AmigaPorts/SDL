---
title: A Register Summary / BPL1MOD, BPL2MOD
manual: hardware
chapter: hardware
section: a-register-summary-bpl1mod-bpl2mod
functions: []
libraries: []
---

# A Register Summary / BPL1MOD, BPL2MOD

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BPL1MOD    108      W       A     Bitplane modulo (odd planes)
BPL2MOD    10A      W       A     Bitplane modulo (even planes)


                 These registers contain the modulos for the odd
                 and even bitplanes.  A modulo is a number that is
                 automatically added to the address at the end of
                 each line, so that the address then points to the
                 start of the next line.
                 Since they have separate modulos, the odd and even
                 bitplanes may have sizes that are different from
                 each other, as well as different from the display
                 window size.
