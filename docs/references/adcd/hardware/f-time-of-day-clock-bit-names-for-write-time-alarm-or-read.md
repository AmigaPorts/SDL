---
title: F / Time of Day Clock / Bit Names for Write Time/Alarm or Read Time
manual: hardware
chapter: hardware
section: f-time-of-day-clock-bit-names-for-write-time-alarm-or-read
functions: []
libraries: []
---

# F / Time of Day Clock / Bit Names for Write Time/Alarm or Read Time

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
        REG  NAME
        ---  ----
         8   [LSB Event](hardware/f-8520-complex-interface-adapters-chip-register-map.md)    E7   E6   E5   E4   E3   E2   E1   E0
         9   [Event 8-15](hardware/f-8520-complex-interface-adapters-chip-register-map.md)   E15  E14  E13  E12  E11  E10  E9   E8
         A   [MSB Event](hardware/f-8520-complex-interface-adapters-chip-register-map.md)    E23  E22  E21  E20  E19  E18  E17  E16

        WRITE
        CRB7 = 0
        CRB7 = 1 ALARM
```
