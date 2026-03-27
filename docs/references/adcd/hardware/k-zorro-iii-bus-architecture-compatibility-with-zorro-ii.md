---
title: K / Zorro III Bus Architecture / Compatibility With Zorro II Devices
manual: hardware
chapter: hardware
section: k-zorro-iii-bus-architecture-compatibility-with-zorro-ii
functions: []
libraries: []
---

# K / Zorro III Bus Architecture / Compatibility With Zorro II Devices

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

As detailed in the  [Zorro II Compatibility](hardware/k-zorro-expansion-bus-zorro-ii-compatibility.md)  section, the Zorro III bus
supports a bus cycle mode very similar to the  [68000-based Zorro II bus](hardware/k-zorro-ii-compatibility-zorro-ii-bus-architecture.md) ,
and is expected to be compatible with all properly designed Zorro II PICs.
As shown in  [Figure K-1](hardware/k-general-the-zorro-iii-rationale.md) , Zorro II and Zorro III expansion spaces are
geographically mapped on the Zorro III bus. The mapping logic resides on
the bus, and operates on the bus address presented for any cycle.  Every
cycle starts out assuming a Zorro III cycle, but the mapping logic will
inscribe a Zorro II cycle within the Zorro III cycle if the address range
is right. Figure K-9 details the bus action for this mode.


           _____        READ CYCLE       ___       WRITE CYCLE        __
      /FCS      \                       /   \                        /
                 \_____________________/     \______________________/

                    /FCS sample edge
           __    __ /  __    __    __    __    __    __    __    __    _
      CDAC   |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |  |
             |__|  |__|  |__|  |__|  |__|  |__|  |__|  |__|  |__|  |__|

            /DTACK sample edge        data latch edge
           _    __    __    __\   __ /  __    __    __    __    __    __
        7M  |  |30|  |32|  |34|  |36|  |  |  |30|  |32|  |34|  |36|  |
            |__|  |__|  |__|  |__|  |__|  |__|  |__|  |__|  |__|  |__|
                   31    33    35    37          31    33    35    37
           __________                 ____________                 _____
      /CCS           \               /            \               /
                      \_____________/              \_____________/

              address   data from slave   address    data from master
                _|_     ____________|__     _|_      _______|________
AD31..AD24 ____/ | \___/         /  |  \___/ | \____/       |        \__
               \___/   \_________\_____/   \___/    \________________/
                ______________________      _________________________
 AD23..AD8 ____/                      \____/                         \__
  SA7..SA2     \______________________/    \_________________________/
           ________________________________                           __
      READ    /                            \                         /
           __/                              \_______________________/
           _____________             _________________              ____
    /SLAVE              \           /                 \            /
                         \_________/                   \__________/
                              _______                        _______
       DOE                   /       \                      /       \
           _________________/         \____________________/         \__
           __________               _______________________        _____
 /DS3,/DS2           \             /                       \      /


                      \___________/                         \____/
           ___________________        _______________________        ___
    /DTACK                    \      /                       \      /
                               \____/                         \____/


                   Figure K-9 Zorro II Within Zorro III
The cycle starts out with the usual address phase activity; the bus master
asserts  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  after asserting the full 32-bit address onto the address
bus. The bus decoder maps the bus address  [asynchronously](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)  and quickly, so
that by the time  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  is asserted, the memory space is determined.  A
Zorro II space access will cause  [A8-A23](hardware/k-signal-description-addressing-and-control-signals.md)  to remain asserted, rather than
being tri-stated along with  [A24-A31](hardware/k-signal-description-addressing-and-control-signals.md) , as the Zorro III cycle normally
does. The bus controller synchs the  [asynchronous](hardware/k-basic-zorro-iii-bus-cycles-design-goals.md)   [/FCS](hardware/k-signal-description-address-and-related-control-signals.md)  on the falling
edge of CDAC, then drives  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)  (the  [/AS](hardware/k-signal-description-addressing-and-control-signals.md)  equivalent) out on the rising
edge of  [7M](hardware/k-signal-description-clock-signals-2.md) , based on that synched  [/FCS](hardware/k-signal-description-address-and-related-control-signals.md) . For a read cycle,  [/DS3](hardware/k-signal-description-data-and-related-control-signals.md) 
and/or  [/DS2](hardware/k-signal-description-data-and-related-control-signals.md)  (the  [/UDS](hardware/k-signal-description-addressing-and-control-signals.md)  and  [/LDS](hardware/k-signal-description-addressing-and-control-signals.md)  replacements, respectively) would be
asserted along with  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md) ; write cycles see those lines asserted on the
next rising edge of  [7M](hardware/k-signal-description-clock-signals-2.md) , at S4 time. The  [DOE](hardware/k-signal-description-data-and-related-control-signals.md)  line is also asserted at
the start of S4.

The bus controller starts to sample  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  on the falling edge of  [7M](hardware/k-signal-description-clock-signals-2.md) 
between S4 and S5, adding wait states until  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  is encountered. As
per Zorro II specs, the PIC need not create a  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  unless it needs
that level of control; there are Zorro II signals to delay the
controller-generated  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md) , or take it over when necessary.  The
controller will drive its automatic  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  at the start of S4, leaving
plenty of time for the sampling to come at S5.  Once a  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md)  is
encountered, cycle  [termination](hardware/k-zorro-expansion-bus-mechanical-specifications.md)  begins.  The controller latches data on
the falling  [7M](hardware/k-signal-description-clock-signals-2.md)  edge between S6 and S7, and also negates  [/CCS](hardware/k-signal-description-address-and-related-control-signals.md)  and the
 [/DSn](hardware/k-signal-description-data-and-related-control-signals.md)  at this time. Shortly thereafter, the controller negates  [/DTACK](hardware/k-signal-description-data-and-related-control-signals.md) 
(when controlling it),  [DOE](hardware/k-signal-description-data-and-related-control-signals.md) , and tri-states the data bus, getting ready
for the next cycle.

