# K / / Signal Description / DMA Control Signals


There are various signals on the expansion bus that coordinate the
arbitration of bus masters.  Native Zorro III bus masters use some of the
same  [logical signals](../Hardware_Manual_guide/node02B1.html) , but their arbitration protocol is considerably
different.

PIC is DMA Owner (/OWN)
   This signal is asserted by an expansion bus DMA device when it
   becomes bus master. This output is to be treated as a wired-OR output
   between all expansion slots, any of which may have a PIC signaling
   bus mastership.  Thus, this should be driven with an  [open-collector](../Hardware_Manual_guide/node02BE.html) 
   or similar output by any PIC using it.  This signal is the main basis
   for data direction calculations between the local and expansion
   busses, and is pulled up by a backplane resistor.

Slot Specific Bus Arbitration (/BRn, /BGn)
   These are the slot-specific /BRn and /BGn signals, where "n" refers
   to the expansion slot number. The bus request from each board is
   taken in by the bus controller and ultimately used to take over the
   system from 680x0 on the local bus.  The bus controller eventually
   returns one bus grant to the winner among all requesting PICs.  From
   the point of view of the individual PIC, the protocol is very similar
   to that of the 68000 arbitration mechanism.  The PIC asserts /BRn on
   the rising edge of  [7M](../Hardware_Manual_guide/node029E.html#line28) ; some time later, /BGn is returned on the
   falling edge of  [7M](../Hardware_Manual_guide/node029E.html#line28) .  The PIC waits for all bus activity to finish,
   asserts /OWN followed by /BGACK, then negates /BRn, assuming bus
   mastership. It retains mastership until it negates /BGACK followed by
   /OWN.

         ___     ___     ___     ___     ___     ___     ___     ___     _
    C7M |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |   |
        |   |___|   |___|   |___|\  |___|   |___|\  |___|   |___|   |___|
                                  \               |
        ________                   \           ___|_______________________
    /BR         |                   |         |   |
                |___________________|_________|  /
                                    |           /
        _________________________   |          /  ________________________
    /BG                          |<-+         +->|
                                 |_______________|

         _________________________________________________________________
Signals |                           |           |                 |
        |___________________________|           |_________________|

        _________________________________                               __
   /OWN                                  |                             |
                                         |_____________________________|

        _____________________________________                        _____
 /BGACK                                      |                      |


                                             |______________________|


                   Figure K-4: Zorro II Bus Arbitration
Bus Grant Acknowledge (/BGACK)
   Any Zorro II PIC that receives a bus grant asserts this signal as
   long as it maintains bus mastery.  This signal may never be asserted
   until the bus grant has been received,  [/AS](../Hardware_Manual_guide/node02A2.html#line18)  is negated,  [/DTACK](../Hardware_Manual_guide/node02A2.html#line49) 
   is negated, and /BGACK itself is negated, indicating that all other
   potential bus masters have relinquished the bus.  This output is
   driven as a wired-OR output, so all PICs must drive it with an
```c
    [open collector](../Hardware_Manual_guide/node02BE.html)  or equivalent device, and a passive pullup is supplied
```
   by the backplane.

Bus Want/Clear (/GBG) := ( [/BCLR](../Hardware_Manual_guide/node02B3.html#line27) ) for Zorro III
   This signal is asserted by the bus controller to indicate that a PIC
   wants to master the bus. A bus master assumes that the host CPU wants
   the bus, and that any time wasted as master is stealing time from the
   CPU.  To avoid such waste, a master should use  [cache](../Hardware_Manual_guide/node02A9.html)  or FIFO to grab
   slow-coming data, and then transfer it all at once.    [/BCLR](../Hardware_Manual_guide/node02B3.html#line27)  is
   asserted to indicate that additionally, another PIC wants the bus,
   and the current bus master should get off as soon as possible.  This
   signal is equivalent to /GBG on the A2000 bus.

