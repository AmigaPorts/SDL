# 26 Exec Interrupts / Servicing Interrupts


Interrupts are serviced on the Amiga through the use of interrupt [handlers](../Libraries_Manual_guide/node0309.html)
and [servers](../Libraries_Manual_guide/node030B.html).  An interrupt handler is a system routine that exclusively
handles all processing related to a particular 4703 interrupt.  An
interrupt server is one of possibly many system routines that are invoked
as the result of a single 4703 interrupt.  Interrupt servers provide a
means of interrupt sharing. This concept is useful for general-purpose
interrupts such as vertical blanking.

At system start, Exec designates certain interrupts as handlers and others
as server chains.  The [PORTS](../Libraries_Manual_guide/node0303.html#line79), [COPER](../Libraries_Manual_guide/node0303.html#line81), [VERTB](../Libraries_Manual_guide/node0303.html#line81), [EXTER](../Libraries_Manual_guide/node0303.html#line99), and [NMI](../Libraries_Manual_guide/node0303.html#line103) interrupts are
initialized as server chains.  Therefore, each of these may execute
multiple interrupt routines per each interrupt.  All other interrupts are
designated as handlers and are always used exclusively.

 [Interrupt Data Structure](../Libraries_Manual_guide/node0307.html)    [Interrupt Handlers](../Libraries_Manual_guide/node0309.html) 
 [Environment](../Libraries_Manual_guide/node0308.html)                 [Interrupt Servers](../Libraries_Manual_guide/node030B.html) 

