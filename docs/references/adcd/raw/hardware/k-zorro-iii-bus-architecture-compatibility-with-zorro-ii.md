# K / Zorro III Bus Architecture / Compatibility With Zorro II Devices


As detailed in the  [Zorro II Compatibility](../Hardware_Manual_guide/node0290.html)  section, the Zorro III bus
supports a bus cycle mode very similar to the  [68000-based Zorro II bus](../Hardware_Manual_guide/node029B.html) ,
and is expected to be compatible with all properly designed Zorro II PICs.
As shown in  [Figure K-1](../Hardware_Manual_guide/node028F.html#line35) , Zorro II and Zorro III expansion spaces are
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
asserts  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  after asserting the full 32-bit address onto the address
bus. The bus decoder maps the bus address  [asynchronously](../Hardware_Manual_guide/node02A5.html)  and quickly, so
that by the time  [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  is asserted, the memory space is determined.  A
Zorro II space access will cause  [A8-A23](../Hardware_Manual_guide/node02A2.html#line13)  to remain asserted, rather than
being tri-stated along with  [A24-A31](../Hardware_Manual_guide/node02A2.html#line13) , as the Zorro III cycle normally
does. The bus controller synchs the  [asynchronous](../Hardware_Manual_guide/node02A5.html)   [/FCS](../Hardware_Manual_guide/node02B4.html#line73)  on the falling
edge of CDAC, then drives  [/CCS](../Hardware_Manual_guide/node02B4.html#line53)  (the  [/AS](../Hardware_Manual_guide/node02A2.html#line18)  equivalent) out on the rising
edge of  [7M](../Hardware_Manual_guide/node02B0.html#line23) , based on that synched  [/FCS](../Hardware_Manual_guide/node02B4.html#line73) . For a read cycle,  [/DS3](../Hardware_Manual_guide/node02B5.html#line17) 
and/or  [/DS2](../Hardware_Manual_guide/node02B5.html#line17)  (the  [/UDS](../Hardware_Manual_guide/node02A2.html#line37)  and  [/LDS](../Hardware_Manual_guide/node02A2.html#line37)  replacements, respectively) would be
asserted along with  [/CCS](../Hardware_Manual_guide/node02B4.html#line53) ; write cycles see those lines asserted on the
next rising edge of  [7M](../Hardware_Manual_guide/node02B0.html#line23) , at S4 time. The  [DOE](../Hardware_Manual_guide/node02B5.html#line5)  line is also asserted at
the start of S4.

The bus controller starts to sample  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  on the falling edge of  [7M](../Hardware_Manual_guide/node02B0.html#line23) 
between S4 and S5, adding wait states until  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  is encountered. As
per Zorro II specs, the PIC need not create a  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  unless it needs
that level of control; there are Zorro II signals to delay the
controller-generated  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) , or take it over when necessary.  The
controller will drive its automatic  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  at the start of S4, leaving
plenty of time for the sampling to come at S5.  Once a  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27)  is
encountered, cycle  [termination](../Hardware_Manual_guide/node02C2.html)  begins.  The controller latches data on
the falling  [7M](../Hardware_Manual_guide/node02B0.html#line23)  edge between S6 and S7, and also negates  [/CCS](../Hardware_Manual_guide/node02B4.html#line53)  and the
 [/DSn](../Hardware_Manual_guide/node02B5.html#line17)  at this time. Shortly thereafter, the controller negates  [/DTACK](../Hardware_Manual_guide/node02B5.html#line27) 
(when controlling it),  [DOE](../Hardware_Manual_guide/node02B5.html#line5) , and tri-states the data bus, getting ready
for the next cycle.

