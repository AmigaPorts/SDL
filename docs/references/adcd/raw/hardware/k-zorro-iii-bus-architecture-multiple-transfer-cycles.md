# K / Zorro III Bus Architecture / Multiple Transfer Cycles


The multiplexed address/data design of the Zorro III bus has some definite
advantages.  It allows Zorro III cards to use the same  [100-pin](../Hardware_Manual_guide/node02C9.html)  connector
as the Zorro II cards, which results in every bus slot being a 32-bit
slot, even if there's an alternate connector in-line with any or all of
the system slots; current alternate connectors include  [Amiga Video](../Hardware_Manual_guide/node02C5.html)  and
 [PC-AT](../Hardware_Manual_guide/node02C4.html)  (now sometimes called ISA, for Industry Standard Architecture, now
that it's basically beyond the control of IBM)  [compatible connectors](../Hardware_Manual_guide/node028E.html#line26) .
This design also makes implementation of the bus controller for a system
such as the A3000 simpler.  And it can result in lower cost for Zorro III
PICs in many cases.

The main disadvantage of the multiplexed bus is that the multiplexing can
waste time.  The address access time is the same for multiplexed and
non-multiplexed buses, but because of the multiplexing time, Zorro III
PICs must wait until data time to assert data, which places a fixed limit
on how soon data can be valid.  The Zorro III Multiple Transfer Cycle is a
special mode designed to allow the bus to approach the speed of a
non-multiplexed design.  This mode is especially effective for high speed
transfers between memory and I/O cards.

As the name implies, the Multiple Transfer Cycle is an extension of the
basic full cycle that results in multiple 32-bit transfers. It starts with
a normal full cycle address phase transaction, where the bus master drives
the 32-bit address and asserts the  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  signal.  A master capable of
supporting a Multiple Transfer Cycle will also assert  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  at the same
time as  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) . The slave latches the address and responds by asserting
its  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  line.  If the slave is capable of multiple transfers, it'll
also assert  [/MTACK](../Hardware_Manual_guide/node02B5.html#line44) , indicating to the bus master that it's capable of
this extended cycle form.  If either  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  or  [/MTACK](../Hardware_Manual_guide/node02B5.html#line44)  is negated for a
cycle, that cycle will be a basic full cycle.

           ______                                                 ________
      /FCS       \                                               /
                  \_____________________________________________/

              address      data from slave    data from master
              ___|__     _____|_______|_________|___________|___
 AD31..AD8 __/   |  \___/   / | \   / | \   /   |   \   /   |   \_________
             \______/   \___\___/___\___/___\_______/___\_______/
           _______________       ___       ___       ___       ___________
     /MTCR                \     /   \     /   \     /   \     /
                           \___/     \___/     \___/     \___/
              _______________________________________________
  SA7..SA2 __/                 \   /     \   /     \   /     \____________
  FC2..FC0   \_________________/___\_____/___\_____/___\_____/
           ________________________________                     __________
      READ                                 \                   /
                                            \_________________/
                        ______________________________________
       DOE             /                                      \
           ___________/                                        \__________
           _______________       ___       ___       ___       ___________
/DS3../DS0                \     /   \     /   \     /   \     /


                           \___/     \___/     \___/     \___/
           ___________                                 ___________________
    /MTACK            \                               /
                       \_____________________________/
           __________________      ____      ____      ____      _________
    /DTACK                   \    /    \    /    \    /    \    /
                              \__/      \__/      \__/      \__/


                   Figure K-6: Multiple Transfer Cycles
Assuming the multiple transfer handshake goes through, the multiple cycle
continues to look similar to the basic cycle into the data phase.  The bus
master asserts  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  (possibly with write data) and the appropriate
 [/DSn](../Hardware_Manual_guide/node02B5.html#line17) , then the slave responds with  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  (possibly with read data at
the same time), just as usual. Following this, however, the cycle's
character changes. Instead of terminating the cycle by negating  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) ,
 [/DSn](../Hardware_Manual_guide/node02B5.html#line17) , and  [DOE](../Hardware_Manual_guide/node02B5.html#line5) , the master negates  [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  and  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44) , but maintains
 [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  and  [DOE](../Hardware_Manual_guide/node02B5.html#line5) . The slave continues to assert  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3) , and the bus
goes into what's called a short cycle.

The short cycle begins with the bus master driving the low order address
lines  [A7-A2](../Hardware_Manual_guide/node02B4.html#line21) ; these are the non-multiplexed addresses and can change
without a new address phase being required (this is essentially a page
mode, fully random accesses on this 256-byte page). The  [READ](../Hardware_Manual_guide/node02B4.html#line6)  line may
also change at this time.  The master will then assert  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  to indicate
to the slave that the short cycle is starting.  For reads, the appropriate
 [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  are asserted simultaneously with  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44) , for writes, data and
 [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  are asserted slightly after  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44) . The slave will supply data for
reads, then assert  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) , and the bus will terminate the short cycle
and start into either another short cycle or a full cycle, depending on
the multiple cycle handshaking that has taken place.

The question of whether a subsequent cycle will be a full cycle or a short
cycle is answered by multiple cycle arbitration.  If the master can't
sustain another short cycle, it will negate  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  and  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  along with
 [/MTCR](../Hardware_Manual_guide/node02B5.html#line44)  at the end of the current short cycle, terminating the full cycle
as well. The master always samples the state of  [/MTACK](../Hardware_Manual_guide/node02B5.html#line44)  on the falling
edge of  [/MTCR](../Hardware_Manual_guide/node02B5.html#line44) .  If a slave can't support additional short cycles, it
negates  [/MTACK](../Hardware_Manual_guide/node02B5.html#line44)  one short cycle ahead of time.  On the following short
cycle, the bus master will see that no more short cycles can be handled by
the slave, and fully terminate the multiple transfer cycle once this last
short cycle is done.

PICs aren't absolutely required to support Multiple Transfer Cycles,
though it is a highly recommended feature, especially for memory boards.
And of course, all PICs must act intelligently about such cycles on the
bus; a card doesn't request or acknowledge any Multiple Transfer Cycle it
can't support.

