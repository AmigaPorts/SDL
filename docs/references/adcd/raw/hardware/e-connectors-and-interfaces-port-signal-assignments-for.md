# E Connectors And Interfaces / Port Signal Assignments for 8520 CIAS


CIA-A Address BFEx01  data bits 7-0  (A12*) (int2)
--------------------------------------------------

   PA7..game port 1, pin 6 (fire button*)
   PA6..game port 0, pin 6 (fire button*)
   PA5.. [RDY*](../Hardware_Manual_guide/node0110.html)      disk ready*
   PA4.. [TK0*](../Hardware_Manual_guide/node0110.html#line30)      disk track 00*
   PA3.. [WPRO*](../Hardware_Manual_guide/node0110.html#line29)     write protect*
   PA2.. [CHNG*](../Hardware_Manual_guide/node0110.html#line20)     disk change*
   PA1..LED*       led light (0=bright)/audio filter control (A500 & A2000)
   PA0..OVL        ROM/RAM overlay bit

   SP... [KDAT](../Hardware_Manual_guide/node0172.html)      keyboard data
   CNT.. [KCLK](../Hardware_Manual_guide/node0172.html)      keyboard clock
   PB7..P7         data 7
   PB6..P6         data 6
   PB5..P5         data 5     Centronics parallel interface
   PB4..P4         data 4          data
   PB3..P3         data 3
   PB2..P2         data 2
   PB1..P1         data 1
   PB0..P0  data 0

   PC... [drdy*](../Hardware_Manual_guide/node0102.html)                Centronics control
   F.... [ack*](../Hardware_Manual_guide/node0102.html#line17) 


CIA-B Address BFDx00  data bits 15-8   (A13*) (int6)
-----------------------------------------------------

   PA7..com line  [DTR*](../Hardware_Manual_guide/node0106.html#line21) , driven output
   PA6..com line  [RTS*](../Hardware_Manual_guide/node0106.html) , driven output
   PA5..com line carrier detect*
   PA4..com line  [CTS*](../Hardware_Manual_guide/node0106.html) 
   PA3..com line  [DSR*](../Hardware_Manual_guide/node0106.html#line21) 
   PA2.. [SEL](../Hardware_Manual_guide/node0102.html#line31)       Centronics control
   PA1.. [POUT](../Hardware_Manual_guide/node0102.html#line28) +--- paper out ------------+
   PA0.. [BUSY](../Hardware_Manual_guide/node0102.html#line25) | +--busy    -------------+ |
              | |                       | |
   SP... [BUSY](../Hardware_Manual_guide/node0102.html#line25) | +- commodore serial bus + |
   CNT.. [POUT](../Hardware_Manual_guide/node0102.html#line28) +----commodore serial bus --+

   PB7.. [MTR*](../Hardware_Manual_guide/node0110.html#line12)      motor
   PB6.. [SEL3*](../Hardware_Manual_guide/node0110.html#line38)     select external 3rd drive
   PB5.. [SEL2*](../Hardware_Manual_guide/node0110.html#line16)     select external 2nd drive
   PB4.. [SEL1*](../Hardware_Manual_guide/node0110.html#line39)     select external 1st drive
   PB3.. [SEL0*](../Hardware_Manual_guide/node0114.html)     select internal drive
   PB2.. [SIDE*](../Hardware_Manual_guide/node0110.html#line28)     side select*
   PB1.. [DIR](../Hardware_Manual_guide/node0110.html#line36)       direction
   PB0.. [STEP*](../Hardware_Manual_guide/node0110.html#line34)     step*

   PC...not used
   F.... [INDEX*](../Hardware_Manual_guide/node0110.html#line40)    disk index pulse*

