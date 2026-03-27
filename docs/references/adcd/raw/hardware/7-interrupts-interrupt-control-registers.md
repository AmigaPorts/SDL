# 7 / Interrupts / Interrupt Control Registers


There are two interrupt registers, interrupt enable (mask) and interrupt
request (status). Each register has both a read and a write address.  The
names of the interrupt addresses are:


```c
    [INTENA](../Hardware_Manual_guide/node0036.html) 
      Interrupt0 enable (mask) - write only. Sets or clears specific
      bits of INTENA.

    [INTENAR](../Hardware_Manual_guide/node0036.html) 
      Interrupt enable (mask) read - read only. Reads contents of INTENA.

    [INTREQ](../Hardware_Manual_guide/node0037.html) 
      Interrupt request (status) - write only. Used by the processor
      to force a certain kind of interrupt to be processed (software
      interrupt). Also used to clear interrupt request flags once the
      interrupt process is completed.

    [INTREQR](../Hardware_Manual_guide/node0037.html) 
      Interrupt request (status) read - read only. Contains the bits
      that define which items are requesting interrupt service.

      The bit positions in the interrupt request register correspond
      directly to those same positions in the interrupt enable
      register. The only difference between the read-only and the
      write-only addresses shown above is that  [bit 15](../Hardware_Manual_guide/node0166.html)  has no meaning
      in the read-only addresses.
```
