---
title: E Connectors And Interfaces / Port Signal Assignments for 8520 CIAS
manual: hardware
chapter: hardware
section: e-connectors-and-interfaces-port-signal-assignments-for
functions: []
libraries: []
---

# E Connectors And Interfaces / Port Signal Assignments for 8520 CIAS

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

CIA-A Address BFEx01  data bits 7-0  (A12*) (int2)
--------------------------------------------------

   PA7..game port 1, pin 6 (fire button*)
   PA6..game port 0, pin 6 (fire button*)
   PA5.. [RDY*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)      disk ready*
   PA4.. [TK0*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)      disk track 00*
   PA3.. [WPRO*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     write protect*
   PA2.. [CHNG*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     disk change*
   PA1..LED*       led light (0=bright)/audio filter control (A500 & A2000)
   PA0..OVL        ROM/RAM overlay bit

   SP... [KDAT](hardware/amiga-hardware-reference-manual-g-keyboard-interface.md)      keyboard data
   CNT.. [KCLK](hardware/amiga-hardware-reference-manual-g-keyboard-interface.md)      keyboard clock
   PB7..P7         data 7
   PB6..P6         data 6
   PB5..P5         data 5     Centronics parallel interface
   PB4..P4         data 4          data
   PB3..P3         data 3
   PB2..P2         data 2
   PB1..P1         data 1
   PB0..P0  data 0

   PC... [drdy*](hardware/e-parallel-interface-specification-pin-assignment-j8.md)                Centronics control
   F.... [ack*](hardware/e-parallel-interface-specification-pin-assignment-j8.md) 


CIA-B Address BFDx00  data bits 15-8   (A13*) (int6)
-----------------------------------------------------

   PA7..com line  [DTR*](hardware/e-serial-interface-specification-pin-assignment-j6.md) , driven output
   PA6..com line  [RTS*](hardware/e-serial-interface-specification-pin-assignment-j6.md) , driven output
   PA5..com line carrier detect*
   PA4..com line  [CTS*](hardware/e-serial-interface-specification-pin-assignment-j6.md) 
   PA3..com line  [DSR*](hardware/e-serial-interface-specification-pin-assignment-j6.md) 
   PA2.. [SEL](hardware/e-parallel-interface-specification-pin-assignment-j8.md)       Centronics control
   PA1.. [POUT](hardware/e-parallel-interface-specification-pin-assignment-j8.md) +--- paper out ------------+
   PA0.. [BUSY](hardware/e-parallel-interface-specification-pin-assignment-j8.md) | +--busy    -------------+ |
              | |                       | |
   SP... [BUSY](hardware/e-parallel-interface-specification-pin-assignment-j8.md) | +- commodore serial bus + |
   CNT.. [POUT](hardware/e-parallel-interface-specification-pin-assignment-j8.md) +----commodore serial bus --+

   PB7.. [MTR*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)      motor
   PB6.. [SEL3*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     select external 3rd drive
   PB5.. [SEL2*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     select external 2nd drive
   PB4.. [SEL1*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     select external 1st drive
   PB3.. [SEL0*](hardware/e-internal-connectors-internal-disk.md)     select internal drive
   PB2.. [SIDE*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     side select*
   PB1.. [DIR](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)       direction
   PB0.. [STEP*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)     step*

   PC...not used
   F.... [INDEX*](hardware/e-external-disk-interface-specification-pin-assignment-j7.md)    disk index pulse*

