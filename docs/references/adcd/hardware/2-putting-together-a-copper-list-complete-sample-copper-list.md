---
title: 2 / Putting Together a Copper List / Complete Sample Copper List
manual: hardware
chapter: hardware
section: 2-putting-together-a-copper-list-complete-sample-copper-list
functions: [AllocMem]
libraries: [exec.library]
---

# 2 / Putting Together a Copper List / Complete Sample Copper List

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following example shows a complete Copper list. This list is for two
bitplanes -- one at $21000 and one at $25000. At the top of the screen,
the  [color registers](hardware/3-bitplanes-and-color-the-color-table.md)  are loaded with the following values:


          Register        Color
          --------        -----
          COLOR00         white
          COLOR01         red
          COLOR02         green
          COLOR03         blue
At line 150 on the screen, the  [color registers](hardware/3-bitplanes-and-color-the-color-table.md)  are reloaded:


          Register        Color
          --------        -----
          COLOR00         black
          COLOR01         yellow
          COLOR02         cyan
          COLOR03         magenta
The complete Copper list follows.

;
; Notes: 1. Copper lists must be in Chip RAM.
;        2. Bitplane addresses used in the example are arbitrary.
;        3. Destination register addresses in Copper move instructions
;           are offsets from the base address of the custom chips.
;        4. As always, hardware manual examples assume that your
;           application has taken full control of the hardware, and is not
;           conflicting with operating system use of the same hardware.
;        5. Many of the examples just pick memory addresses to be used.
;           Normally you would need to allocate the required type of
;           memory from the system with AllocMem()
;        6. As stated earlier, the code examples are mainly to help
;           clarify the way the hardware works.
;        7. The following INCLUDE files are required by all example code
;           in this chapter.
;

        INCLUDE "exec/types.i"
        INCLUDE "hardware/custom.i"
        INCLUDE "hardware/dmabits.i"
        INCLUDE "hardware/hw_examples.i"
COPPERLIST:
;
;  Set up pointers to two bitplanes
;
```c
        DC.W    BPL1PTH,$0002   ;Move $0002 into register $0E0 (BPL1PTH)
        DC.W    BPL1PTL,$1000   ;Move $1000 into register $0E2 (BPL1PTL)
        DC.W    BPL2PTH,$0002   ;Move $0002 into register $0E4 (BPL2PTH)
        DC.W    BPL2PTL,$5000   ;Move $5000 into register $0E6 (BPL2PTL)
```
;
;  Load color registers
;
```c
        DC.W    COLOR00,$0FFF   ;Move white into register $180 (COLOR00)
        DC.W    COLOR01,$0F00   ;Move red into register   $182 (COLOR01)
        DC.W    COLOR02,$00F0   ;Move green into register $184 (COLOR02)
        DC.W    COLOR03,$000F   ;Move blue into register  $186 (COLOR03)
```
;
;   Specify 2 Lores bitplanes
;
```c
        DC.W    BPLCON0,$2200   ;2 lores planes, coloron
```
;
;  Wait for line 150
;
```c
        DC.W    $9601,$FF00     ;Wait for line 150, ignore horiz. position
```
;
;  Change color registers mid-display
;
```c
        DC.W    COLOR00,$0000  ;Move black into register $0180 (COLOR00)
        DC.W    COLOR01,$0FF0  ;Move yellow into register $0182 (COLOR01)
        DC.W    COLOR02,$00FF  ;Move cyan into register $0184 (COLOR02)
        DC.W    COLOR03,$0F0F  ;Move magenta into register $0186 (COLOR03)
```
;
; End Copper list by waiting for the impossible
;

```c
        DC.W    $FFFF,$FFFE    ;Wait for line 255, H = 254 (never happens)
```
For more information about  [color registers](hardware/3-bitplanes-and-color-the-color-table.md) , see Chapter 3, "Playfield
Hardware."

---

## See Also

- [AllocMem — exec.library](../autodocs/exec.library.md#allocmem)
