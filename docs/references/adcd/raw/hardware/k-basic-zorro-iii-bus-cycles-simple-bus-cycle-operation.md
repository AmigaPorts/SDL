# K / / Basic Zorro III Bus Cycles / Simple Bus Cycle Operation


The normal Zorro III bus cycle is quite different than the Zorro II bus in
many respects. Figure K-5 shows the basic cycle.  There is no bus clock
visible on the expansion bus; the standard Zorro II clocks are still
active during Zorro III cycles, but they have no relationship to the Zorro
II bus cycle.  Every bus event is based on a relationship to a particular
bus strobe, and strobes are alternately supplied by master and slave.


           ______      READ CYCLE       ______      WRITE CYCLE       ____
      /FCS       \                     /      \                      /
                  \___________________/        \____________________/

               address     data from slave  address   data from master
                 _|_      ___________|___     _|_      _____|_______
 AD31..AD8 _____/ | \____/        /  |   \___/ | \____/     |       \_____
                \___/    \________\______/   \___/    \_____________/
                 _______________________      _______________________
  SA7..SA2 _____/                       \____/                       \____
  FC2..FC0      \_______________________/    \_______________________/
           __________________________________                         ____
      READ     /                             \                       /
           ___/                               \_____________________/
           ___________                   __________                   ____
    /SLAVE            \                 /          \                 /
                       \_______________/            \_______________/
                         ______________               ______________
       DOE              /              \             /              \
           ____________/                \___________/                \____
           _______________               ______________               ____
/DS3../DS0                \             /              \             /


                           \___________/                \___________/
           _____________________         ____________________         ____
                                \       /                    \       /
    /DTACK                       \_____/                      \_____/


                    Figure K-5: Basic Zorro III Cycles
A Zorro III cycle begins when the bus master simultaneously drives
addressing information on the address bus and memory space codes on the
 [FCn](../Hardware_Manual_guide/node02B4.html#line28)  lines, quickly following that with the assertion of the Full Cycle
Strobe,  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) ; this is called the address phase of the bus.  Any active
slaves will latch the bus address on the falling edge of  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) , and the
bus master will tri-state the addressing information very shortly after
 [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  is asserted. It's necessary only to latch  [A31-A8](../Hardware_Manual_guide/node02B4.html#line13) ; the low order
 [A7-A2](../Hardware_Manual_guide/node02B4.html#line21)  addresses and @" FCn " link K-4-6 28} codes are non-multiplexed.

As quickly as possible after  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  is asserted, a slave device will
respond to the bus address by asserting its  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  line, and possibly
other special-purpose signals.  The  [autoconfiguration](../Hardware_Manual_guide/node02C7.html)  process assigns a
unique address range to each PIC base on its needs, just as on the Zorro
II bus. Only one slave may respond to any given bus address; the bus
controller will generate a  [/BERR](../Hardware_Manual_guide/node02B1.html#line4)  signal if more than one slave responds
to an address, or if a single slave responds to an address reserved for
the local bus (this is called a bus collision, and should never happen in
normal operation). Slaves don't usually respond to CPU memory space or
other reserved memory space types, as indicated by the  [memory space](../Hardware_Manual_guide/node02B4.html#line35)  code
on the  [FCn](../Hardware_Manual_guide/node02B4.html#line28)  lines (see the  [Signal Description](../Hardware_Manual_guide/node02AE.html)  section following this
section for details).

The data phase is the next part of the cycle, and it's started when the
bus master asserts  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  onto the bus, indicating that data operations can
be started.  The strobes are the same for both read and write cycles, but
the data transfer direction is different.

For a read cycle, the bus master drives at least one of the data strobes
 [/DSn](../Hardware_Manual_guide/node02B5.html#line17) , indicating the physical transfer size requested (however, cachable
slaves must always supply all 32 bits of data).  The slave responds by
driving data onto the bus, and then asserting  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) . The bus master
then terminates the cycle by negating  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) , at which point the slave
will negate its  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  line and tri-state its data. The cycle is done
at this point. There are a few actions that modify a cycle  [termination](../Hardware_Manual_guide/node0298.html) ,
those will be covered in later sections.

The write cycle starts out the same way, up until  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  is asserted.  At
this point, it's the master that must drive data onto the bus, and then
assert at least one  [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  line to indicate to the slave that data is
valid and which data bytes are being written.  The slave has the data for
its use until it terminates the cycle by asserting  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) , at which
point the master can negate  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  and tri-state its data at any point.
For maximum bus bandwidth, the slave can latch data on the falling edge of
the logically ORed data strobes; the bus master doesn't sample  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) 
until after the data strobes are asserted, so a slave can actually assert
 [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  any time after  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) .

