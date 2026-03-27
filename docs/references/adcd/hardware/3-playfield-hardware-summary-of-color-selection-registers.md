---
title: 3 Playfield Hardware / Summary of Color Selection Registers
manual: hardware
chapter: hardware
section: 3-playfield-hardware-summary-of-color-selection-registers
functions: []
libraries: []
---

# 3 Playfield Hardware / Summary of Color Selection Registers

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section contains summaries of the playfield color selection registers
including color register contents, example colors, and the differences in
color selection in high resolution and low resolution modes. The Amiga has
32 color registers and each one has 4 bits of red, 4 bits of green, and 4
bits of blue information.  Table 3-15 shows the bit assignments of each
color register.  All color registers are write-only.




```c
              Color Register Bits           Contents
              -------------------           --------
                   15 - 12           Unused (set these to 0)
                   11 -  8                  Red data
                    7 -  4                 Green data
                    3 -  0                  Blue data

                 Table 3-15: Color Register Contents
```
 [Some Sample Color Register Contents](hardware/3-color-selection-registers-some-sample-color-register.md) 
 [Color Selection in Low Resolution Mode](hardware/3-color-selection-registers-color-selection-in-low.md) 
 [Color Selection in High Resolution Mode](hardware/3-color-selection-color-selection-in-high-resolution-mode.md) 
 [Color Selection in Hold-And-Modify Mode](hardware/3-color-selection-color-selection-in-hold-and-modify-mode.md) 
 [Color Selection in Extra Half Brite (EHB) Mode](hardware/3-color-selection-color-selection-in-extra-half-brite-ehb.md) 

