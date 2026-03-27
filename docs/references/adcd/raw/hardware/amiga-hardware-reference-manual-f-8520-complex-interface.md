# Amiga® Hardware Reference Manual: F 8520 Complex Interface Adapters


This appendix contains information about the 8520 Complex Interface
Adapter (CIA) chips which handle the serial, parallel, keyboard and other
Amiga I/O activities. Each Amiga system contains two 8520 Complex
Interface Adapter (CIA) chips. Each chip has 16 general purpose
input/output pins, plus a serial shift register, three timers, an output
pulse pin and an edge detection input. In the Amiga system various tasks
are assigned to the chip's capabilities as follows:


CIAA Address Map
---------------------------------------------------------------------------
 Byte    Register                  Data bits
Address    Name     7     6     5     4     3     2     1    0
---------------------------------------------------------------------------
BFE001    pra     /FIR1 /FIR0  /RDY /TK0  /WPRO /CHNG /LED  OVL
BFE101    prb     Parallel port
BFE201    ddra    Direction for port A (BFE001);1=output (set to 0x03)
BFE301    ddrb    Direction for port B (BFE101);1=output (can be in or out)
BFE401    talo    CIAA timer A low byte (.715909 Mhz NTSC; .709379 Mhz PAL)
BFE501    tahi    CIAA timer A high byte
BFE601    tblo    CIAA timer B low byte (.715909 Mhz NTSC; .709379 Mhz PAL)
BFE701    tbhi    CIAA timer B high byte
BFE801    todlo   50/60 Hz event counter bits 7-0 (VSync or line tick)
BFE901    todmid  50/60 Hz event counter bits 15-8
BFEA01    todhi   50/60 Hz event counter bits 23-16
BFEB01            not used
BFEC01    sdr     CIAA serial data register (connected to keyboard)
BFED01    icr     CIAA interrupt control register
BFEE01    cra     CIAA control register A
BFEF01    crb     CIAA control register B

Note:  CIAA can generate interrupt INT2.


CIAB Address Map
---------------------------------------------------------------------------
 Byte     Register                   Data bits
Address     Name     7     6     5     4     3     2     1     0
---------------------------------------------------------------------------
BFD000    pra     /DTR  /RTS  /CD   /CTS  /DSR   SEL   POUT  BUSY
BFD100    prb     /MTR  /SEL3 /SEL2 /SEL1 /SEL0 /SIDE  DIR  /STEP
BFD200    ddra    Direction for Port A (BFD000);1 = output (set to 0xFF)
BFD300    ddrb    Direction for Port B (BFD100);1 = output (set to 0xFF)
BFD400    talo    CIAB timer A low byte (.715909 Mhz NTSC; .709379 Mhz PAL)
BFD500    tahi    CIAB timer A high byte
BFD600    tblo    CIAB timer B low byte (.715909 Mhz NTSC; .709379 Mhz PAL)
BFD700    tbhi    CIAB timer B high byte
BFD800    todlo   Horizontal sync event counter bits 7-0
BFD900    todmid  Horizontal sync event counter bits 15-8
BFDA00    todhi   Horizontal sync event counter bits 23-16
BFDB00            not used
BFDC00    sdr     CIAB serial data register (unused)
BFDD00    icr     CIAB interrupt control register
BFDE00    cra     CIAB Control register A
BFDF00    crb     CIAB Control register B

Note:  CIAB can generate INT6.


 [Chip Register Map](../Hardware_Manual_guide/node012F.html)                    [Interrupt Control Register (ICR)](../Hardware_Manual_guide/node0142.html) 
 [Register Functional Description](../Hardware_Manual_guide/node0130.html)      [Control Registers](../Hardware_Manual_guide/node0145.html) 
 [Time of Day Clock](../Hardware_Manual_guide/node013C.html)                    [Port Signal Assignments](../Hardware_Manual_guide/node014A.html) 
 [Serial Shift Register (SDR)](../Hardware_Manual_guide/node013E.html)          [Hardware Connection Details](../Hardware_Manual_guide/node014B.html) 

