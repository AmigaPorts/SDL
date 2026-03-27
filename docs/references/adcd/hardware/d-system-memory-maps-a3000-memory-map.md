---
title: D System Memory Maps / A3000 Memory Map
manual: hardware
chapter: hardware
section: d-system-memory-maps-a3000-memory-map
functions: []
libraries: []
---

# D System Memory Maps / A3000 Memory Map

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Address Range				Description
-----------------------		-------------------------------
$0000 0000 - $001F FFFF		Amiga  [Chip Memory](hardware/c-new-features-of-the-enhanced-chip-set-new-memory-limits.md) 

$0020 0000 - $009F 0000		 [Zorro II Memory Expansion Space](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md) 

$00A0 0000 - $00B7 FFFF		 [Zorro II I/O Expansion Space](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md) 


$00B8 0000 - $00BE FFFF		Reserved

$00BF 0000 - $00BF FFFF		 [CIA Ports & Timers](hardware/amiga-hardware-reference-manual-f-8520-complex-interface.md) 


$00C0 0000 - $00C7 FFFF		Expansion Memory

$00C8 0000 - $00D7 FFFF		Reserved


$00D8 0000 - $00DB FFFF		Reserved

$00DC 0000 - $00DD FFFF		Memory Mapped Clock

$00DD 0000 - $00DE FFFF		SCSI Control

$00DE 0000 - $00DE FFFF		Motherboard Resources

$00DF 0000 - $00DF FFFF		Amiga  [Chip Registers](hardware/amiga-hardware-reference-manual-a-register-summary.md) 


$00E0 0000 - $00E7 FFFF		Reserved

$00E8 0000 - $0EFF FFFF		 [Zorro II I/O & Configuration](hardware/k-changes-from-a2000-bus-bus-memory-mapping-and-cache.md) 

$00F0 0000 - $00F7 FFFF		Diagnostic ROM (Reserved)

$00F8 0000 - $00FF FFFF		High ROM (512K)


$0100 0000 - $03FF FFFF		Reserved

$0400 0000 - $07FF FFFF         Motherboard Fast RAM

$0800 0000 - $0FFF FFFF 	Coprocessor Slot Expansion

$1000 0000 - $7FFF FFFF		Zorro III Expansion


$8000 0000 - $FEFF FFFF		Reserved

$FF00 0000 - $FF00 FFFF		 [Zorro III Configuration Unit](hardware/k-autoconfig-tm-the-autoconfig-mechanism.md) 

$FF01 0000 - $FFFF FFFF		Reserved


```c
         32-BIT ADDRESS SPACE                HIGH MEMORY
            (4 GIGABYTES)                    (16 MBYTES)
```
 $FFFF FFFF  ____________ _ _ _
```c
            |____________|_     $FFFF FFFF  ____________
            |            | \               |            |
            |            |                 |            |
            |            |   \            /            /
            |            |                \            \
            |            |    |            \            \
            |            |                  \            \
            |            |    |             /            /
            |            |                 |            |
            |  Reserved  |    |            |  Reserved  |
            |            |                 |            |
            |            |    | $FF01 0000 |------------|
            |            |                 |  Zorro III |
            |            |    |            |Config. Unit|
            |            |      $FF00 0000 |____________|
            |            |    |_ _ _
            |            |
            |            |
            |            |     _ _ _         LOW MEMORY
            |            |    |             (256 MBYTES)
```
 $8000 0000 |------------|      $0FFF FFFF  ____________
            |            |    |            |            |
            |            |                 |            |
            |            |    |            | Coprocessor|
            |            |                 |    Slot    |
            |            |    |            |  Expansion |
            |  Zorro III |                 |            |
            |  Expansion |    | $0800 0000 |------------|
            |            |                 | Motherboard|
            |            |   /             |  Fast RAM  |
            |            |      $0700 0000 |------------|
            |            | /               |            |
 $1000 0000 |------------|-                |  Reserved  |
```c
            |            |                 |            |
            |            |      $0100 0000 |------------|- -    - -
            | Low Memory |                 |   24-bit   |   \  /
            |(256 MBytes)|                 |   Address  |    \/ (continued
            |            |                 |   Space    |    /\   below)
```
 $0000 0000 |____________|_ _ _ $0000 0000 |____________|_ _/  \_
```c
                                                                    |

                   _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _|
                  |

                  |
                               _ _ _     HIGH I/O REGISTERS
                  |           |
                                  $DF FFFF  ____________
                 \|/          |            |            |
                                           | Amiga Chips|
       (continued from above) |   $DF 0000 |------------|
                                           | Motherboard|
        24-BIT ADDRESS SPACE  |            |  Resources |
            (16 MBYTES)           $DE 0000 |------------|
```
 $00FF FFFF  ____________     |            |SCSI Control|
            |            |        $DD 0000 |------------|
            |  High ROM  |    |            |   Memory-  |
 $00F8 0000 |------------|                 |   mapped   |
            | Diagnostic |    |            |   clock    |
            |    ROM     |        $DC 0000 |------------|
 $00F0 0000 |------------|    |            |  Reserved  |
            |Zorro II I/O|        $DD 0000 |------------|
            | and config.|   /             |  Reserved  |
 $00E8 0000 |------------|        $DA 0000 |------------|
            |  Reserved  | /               |  Reserved  |
 $00E0 0000 |------------|-       $D9 0000 |------------|
            |  High I/O  |                 |  Reserved  |
            |  registers |        $D8 0000 |____________|
 $00D8 0000 |------------|- - - -
            |            |
            |  Reserved  |
            |            |
 $00C8 0000 |------------|
            | Ranger RAM |
 $00C0 0000 |------------|- - - -
            |   Low I/O  |        $BF FFFF  ____________
            |  registers |                 |            |
 $00B8 0000 |------------|-                | CIA Ports  |
            |            | \               | and Timers |
            |Zorro II I/O|        $BF 0000 |------------|
            | Expansion  |   \             |  Reserved  |
            |            |        $BE 0000 |------------|
 $00A0 0000 |------------|    |            |  Reserved  |
            |            |        $BD 0000 |------------|
            |  Zorro II  |    |            |  Reserved  |
            |   Memory   |        $BC 0000 |------------|
            | Expansion  |    |            |  Reserved  |
            |            |        $BB 0000 |------------|
 $0020 0000 |------------|    |            |  Reserved  |
```c
            |  Standard  |        $BA 0000 |------------|
            |  Chip RAM  |    |            |  Reserved  |
            |   (Up to   |        $B9 0000 |------------|
            |  2 MBytes) |    |            |  Reserved  |
```
 $0000 0000 |____________|        $B8 0000 |____________|

                              |_ _ _


                 Figure D-1: Amiga 3000 Memory Map
