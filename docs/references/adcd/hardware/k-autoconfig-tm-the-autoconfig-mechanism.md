---
title: K / AUTOCONFIG(TM) / The Autoconfig Mechanism
manual: hardware
chapter: hardware
section: k-autoconfig-tm-the-autoconfig-mechanism
functions: []
libraries: []
---

# K / AUTOCONFIG(TM) / The Autoconfig Mechanism

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The AUTOCONFIG mechanism used for the Zorro III bus is an extension of the
original Zorro II configuration mechanism.  The main reason for this is
that the Zorro II mechanism works so well, there was little need to change
anything.  The changes are simply support for new hardware features on the
Zorro III bus.

Amiga autoconfiguration is surprisingly simple.  When an Amiga powers up
or resets, every card in the system goes to its unconfigured state.  At
this point, the most important signals in the system are  [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)  and
 [/CFGOUTn](hardware/k-signal-description-slot-control-signals-2.md) .  As long as a card's  [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)  line is negated, that card sits
quietly and does nothing on the bus (though memory cards should continue
to refresh even through reset, and any local board activities that don't
concern the bus may take place after  [/RESET](hardware/k-signal-description-system-control-signals-2.md)  is negated). As part of the
unconfigured state,  [/CFGOUTn](hardware/k-signal-description-slot-control-signals-2.md)  is negated by the PIC immediately on reset.

The configuration process begins when a card's  [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)  line is asserted,
either by the backplane, if it's the first slot, or via the configuration
chain, if it's a later card.  The configuration chain simply ensures that
only one unconfigured card will see an asserted  [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)  at one time.  An
unconfigured card that sees its  [/CFGINn](hardware/k-signal-description-slot-control-signals-2.md)  line asserted will respond to a
block of memory called configuration space. In this block, the PIC will
assert a set of read-only registers, followed by a set of write-only
registers (the read-only registers are also known as AUTOCONFIG ROM).
Starting at the base of this block, the read registers describe the
device's size, type, and other requirements.  The operating system reads
these, and based on them, decides what should be written to the board.
Some write information is optional, but a board will always be assigned a
base address or be told to shut up.  The act of writing the final bit of
base address, or writing anything to a shutup address, will cause the PIC
to assert its  [/CFGOUTn](hardware/k-signal-description-slot-control-signals-2.md) , enabling the next board in the configuration
chain.

The Zorro II configuration space is the 64K memory block $00E8xxxx, which
of course is driven with 16-bit Zorro II cycles; all Zorro II cards
configure there.  The Zorro III configuration space is the 64K memory
block beginning at $FF00xxxx, which is always driven with 32-bit Zorro III
cycles (PICs need only decode  [A31-A24](hardware/k-signal-description-address-and-related-control-signals.md)  during configuration).  A Zorro III
PIC can configure in Zorro II or Zorro III configuration space, at the
designer's discretion, but not both at once. All read registers physically
return only the top 4 bits of data, on  [D31-D28](hardware/k-signal-description-data-and-related-control-signals.md)  for either bus mode. Write
registers are written to support nybble, byte, and word registers for the
same register, again based on what works best in hardware.  This design
attempts to map into real hardware as simply as possible. Every AUTOCONFIG
register is logically considered to be 8 bits wide; the 8 bits actually
being nybbles from two paired addresses.




```c
           $00E80000
            _______
           |#| | | |           a) Zorro II Style Mapping
           |#|_|_|_|

           | |_______________________________
           |_________________                |
                             |               |
                              _______________________________
                             |   |   |   |   |   |   |   |   |
                     (00|02) | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
                             |___|___|___|___|___|___|___|___|

            _________________________________|               |
           |  _______________________________________________|
           | |
           | |
            _______
           |#| | | |
           |#|_|_|_|

           $00E80002


               $FF000000
            _______________
           |#| | | | | | | |       b) Zorro III Style Mapping
           |#|_|_|_|_|_|_|_|

           | |_______________________________
           |_________________                |
                             |               |
                              _______________________________
                             |   |   |   |   |   |   |   |   |
                    (00|100) | 7 | 6 | 5 | 4 | 3 | 2 | 1 | 0 |
                             |___|___|___|___|___|___|___|___|

            _________________________________|               |
           |  _______________________________________________|
           | |
           | |
            _______________
           |#| | | | | | | |
           |#|_|_|_|_|_|_|_|

               $FF000100


               Figure K-17: Configuration Register Mapping
```
The register mappings for the two different blocks are shown in Figure
K-17. All the bit patterns mentioned in the following sections are logical
values. To avoid ambiguity, all registers are referred to by the number of
the first register in the pair, since the first pair member is the same
for both mapping schemes. In the actual implementation of these registers,
all read registers except for the 00 register are physically complemented;
eg, the logical value of register 3C is always 0, which means in hardware,
the upper nybbles of locations $00E8003C and $00E8003E, or $FF00003C and
$FF00013C, both return all 1s.

