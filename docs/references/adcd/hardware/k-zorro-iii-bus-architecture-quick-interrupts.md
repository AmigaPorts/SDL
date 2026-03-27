---
title: K / Zorro III Bus Architecture / Quick Interrupts
manual: hardware
chapter: hardware
section: k-zorro-iii-bus-architecture-quick-interrupts
functions: []
libraries: []
---

# K / Zorro III Bus Architecture / Quick Interrupts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

While the Zorro II bus has always supported shared interrupts, the Zorro
III bus supports a mechanism wherein the interrupting PIC can supply its
own vector.  This has the potential to make such vectored interrupts much
faster than conventional Zorro II chained interrupts, arbitrating the
interrupting device in hardware instead of software.

A PIC supporting quick interrupts has on-board  [registers](hardware/k-autoconfig-tm-register-bit-assignments.md)  to store one or
more vector numbers; the numbers are obtained from the OS by the device
driver for the PIC, and the PIC/driver combination must be able to handle
the situation in which no additional vectors are available.  During system
operation, this PIC will interrupt the system in the normal manner, by
asserting one of the bus interrupt lines.  This interrupt will cause an
interrupt vector cycle to take place on the bus.  This cycle arbitrates in
hardware between all PICs asserting that interrupt, and it's a completely
different type of Zorro III cycle, as illustrated in Figure K-8.


              _____     POLL PHASE                 VECTOR PHASE      _____
         /FCS      \                                                /
                    \______________________________________________/
              _______                 _____                          _____
        /MTCR        \               /     \                        /
                      \_____________/       \______________________/
              ____________            _____                          _____
       /SLAVE             \          /     \                        /
                           \________/       \______________________/
                   ____________________
   AD19..AD16 ____/                    \__________________________________
SA3,SA2,/LOCK     \____________________/


                                             ______________________
          DOE                               /                      \
              _____________________________/                        \_____
              _____________________________                          _____
         /DS0                              \                        /
                                            \______________________/

                                                         data from slave
                                              _________________|_____
     SD7..SD0 _______________________________/            /    |     \____
                                             \____________\__________/
              ____________________________________________            ____
       /DTACK                                             \          /
                                                           \________/


                    Figure K-8: Interrupt Vector Cycle
The bus controller will start an interrupt vector cycle in response to an
interrupt asserted by any PIC.  This cycle starts with  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  and  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md) 
asserted, a FC code of 7 (CPU space), a CPU space cycle type, given by
address lines  [A16-A19](hardware/k-signal-description-address-and-related-control-signals.md) , of 15, and the interrupt number, which is on
 [A1-A3](hardware/k-signal-description-address-and-related-control-signals.md)  (A1 is on the  [/LOCK](hardware/k-advanced-mode-support-logic-bus-locking.md)  line, as in Zorro II cycles). The interrupt
numbers 2 and 6 are currently defined, corresponding to  [/INT2 and /INT6](hardware/k-signal-description-system-control-signals-2.md) 
respectively; all others are reserved for future use.  At this point,
called the polling phase, any PIC that has asserted an interrupt and wants
to supply a vector will decode the FC lines, the cycle type, match its
interrupt number against the one on the bus, and assert  [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md)  if a
match occurs. Shortly thereafter, the  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  line is negated, and the
slaves all negate  [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md) . But the cycle doesn't end.

The next step is called the vector phase.  The bus controller asserts one
 [/SLAVEn](hardware/k-signal-description-slot-control-signals-2.md)  back to one of the interrupting PICs, along with  [/MTCR](hardware/k-signal-description-data-and-related-control-signals.md)  and
 [/DS0](hardware/k-signal-description-data-and-related-control-signals.md) , but no addresses are supplied. That PIC will then assert its 8 bit
vector onto the logical  [D0-D7](hardware/k-signal-description-data-and-related-control-signals.md)  (physically AD15-AD8) of the 32-bit data
bus and  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md) , as quickly as possible, thus terminating the cycle. The
speed here is very critical; an automatic autovector timeout will occur
very quickly, as any actual waiting that's required for the quick
interrupt vector is potentially delaying the autovector response for Zorro
II style interrupts.  A PIC stops driving its interrupt when it gets the
response cycle; it must also be possible for this interrupt to be cleared
in software (e.g., the PIC must make choice of vectoring vs. autovectoring
a software issue).

