# 2 / Advanced Topics / The Copper and the 680x0


On those occasions when the Copper's instructions do not suffice, you can
interrupt the 680x0 and use its instruction set instead. The 680x0 can
poll for interrupt flags set in the  [INTREQ](../Hardware_Manual_guide/node0164.html#line11)  register by various devices.
To interrupt the 680x0, use the Copper  [MOVE](../Hardware_Manual_guide/node004A.html)  instruction to store a 1
into the following bits of  [INTREQ](../Hardware_Manual_guide/node0164.html#line11) :




```c
               Table 2-1: Interrupting the 680x0


     Bit Number      Name      Function
     ----------      ----      --------
        15          [SET/CLR](../Hardware_Manual_guide/node0166.html)    Set/Clear control bit.  Determines
                               if bits written with a 1 get set
                               or cleared.

         4           [COPEN](../Hardware_Manual_guide/node0057.html)     Coprocessor interrupting 680x0.
```
See Chapter 7, "System Control Hardware," for more information about
 [interrupts](../Hardware_Manual_guide/node0160.html) .

