---
title: F / Serial Shift Register (SDR) / Bidirectional Feature
manual: hardware
chapter: hardware
section: f-serial-shift-register-sdr-bidirectional-feature
functions: []
libraries: []
---

# F / Serial Shift Register (SDR) / Bidirectional Feature

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The bidirectional capability of the shift register and CNT clock allows
many 8520s to be connected to a common serial communications bus on
which one 8520 acts as a master, sourcing data and shift clock, while
all other 8520 chips act as slaves.     Both CNT and SP outputs are open
drain to allow such a common bus.  Protocol for master/slave selection
can be transmitted over the serial bus or via dedicated handshake lines.


        REG  NAME       D7   D6   D5   D4   D3   D2   D1   D0
        ---  ----       ---- ---- ---- ---- ---- ---- ---- ----
        C     SDR       S7   S6   S5   S4   S3   S2   S1   S0
