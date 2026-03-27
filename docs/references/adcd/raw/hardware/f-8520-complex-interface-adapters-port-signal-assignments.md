# F 8520 Complex Interface Adapters / Port Signal Assignments


This part specifies how various signals relate to the available ports of
the 8520.  This information enables the programmer to relate the port
addresses to the outside-world items (or internal control signals) which
are to be affected.  This part is primarily for the use of the systems
programmer and should generally not be used by applications programmers.
Systems software normally is configured to handle the setting of
particular signals, no matter how the physical connections may change.

   Warning:
   --------
   In a multitasking operating system, many different tasks may be
   competing for the use of the system resources.  Applications
   programmers should follow the established rules for resource access
   in order to assure compatibility of their software with the system.

CIA-A  Address BFEr01  data bits 7-0  (A12*) (INT2)

PA7..game port 1, pin 6 (fire button*)
PA6..game port 0, pin 6 (fire button*)
PA5.. [RDY*](../Hardware_Manual_guide/node01AA.html#line14)      disk ready*
PA4.. [TK0*](../Hardware_Manual_guide/node01AA.html#line8)      disk track 00*
PA3.. [WPRO*](../Hardware_Manual_guide/node01AA.html#line22)     write protect*
PA2.. [CHNG*](../Hardware_Manual_guide/node01AA.html#line70)     disk change*
PA1..LED*       led light (0=bright)
PA0..OVL        memory overlay bit
SP... [KDAT](../Hardware_Manual_guide/node0172.html)      keyboard data
CNT.. [KCLK](../Hardware_Manual_guide/node0172.html)      keyboard clock
PB7..P7         data 7
PB6..P6         data 6
PB5..P5         data 5     Centronics parallel interface
PB4..P4         data 4          data
PB3..P3         data 3
PB2..P2         data 2
PB1..P1         data 1
PB0..P0         data 0
PC... [drdy*](../Hardware_Manual_guide/node0102.html)                Centronics control
F.... [ack*](../Hardware_Manual_guide/node0102.html#line17) 


CIA-B  Address BFDr00  data bits 15-8   (A13*) (INT6)

PA7..com line  [DTR*](../Hardware_Manual_guide/node0106.html#line21) , driven output
PA6..com line  [RTS*](../Hardware_Manual_guide/node0106.html) , driven output
PA5..com line carrier detect*
PA4..com line  [CTS*](../Hardware_Manual_guide/node0106.html) 
PA3..com line  [DSR*](../Hardware_Manual_guide/node0106.html#line21) 
PA2.. [SEL](../Hardware_Manual_guide/node0102.html#line31)       centronics control
PA1.. [POUT](../Hardware_Manual_guide/node0102.html#line28)      paper out ---+
PA0.. [BUSY](../Hardware_Manual_guide/node0102.html#line25)      busy    ---+ |
                           | |
SP... [BUSY](../Hardware_Manual_guide/node0102.html#line25)      commodore -+ |
CNT.. [POUT](../Hardware_Manual_guide/node0102.html#line28)      commodore ---+

PB7.. [MTR*](../Hardware_Manual_guide/node0110.html#line12)      motor
PB6.. [SEL3*](../Hardware_Manual_guide/node0110.html#line38)     select external 3rd drive
PB5.. [SEL2*](../Hardware_Manual_guide/node0110.html#line16)     select external 2nd drive
PB4.. [SEL1*](../Hardware_Manual_guide/node0110.html#line39)     select external 1st drive
PB3.. [SEL0*](../Hardware_Manual_guide/node0114.html)     select internal drive
PB2.. [SIDE*](../Hardware_Manual_guide/node0110.html#line28)     side select*
PB1.. [DIR](../Hardware_Manual_guide/node0110.html#line36)       direction
PB0.. [STEP*](../Hardware_Manual_guide/node0110.html#line34)     step*   (3.0 milliseconds minimum)

PC...not used
F.... [INDEX*](../Hardware_Manual_guide/node0110.html#line40)    disk index*


```c
     [8520_timing.asm](../Hardware_Manual_guide/node02E1.html) 
```
