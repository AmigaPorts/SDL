# K / / Changes from the A2000 Bus / Intelligent Cycle Spacing


In order to permit a free intermix of Zorro II and Zorro III cycles, the
bus control logic is capable of making intelligent decisions when spacing
bus cycles.  In somc cases, a Zorro II cycle has some component that would
naturally extend into a following cycle.  The cycle spacing logic detects
such a condition, and refuses to start a new cycle until the current one
is complete, even if this extends beyond the defined bounds of a Zorro II
cycle.

For Zorro II PICs that really follow the Zorro II specifications, this
should have no effect.  However, any Zorro II PIC that holds signals much
beyond the end of a cycle, especially critical signals like  [/SLAVE](../Hardware_Manual_guide/node02A0.html#line3)  and
 [/DTACK](../Hardware_Manual_guide/node02A2.html#line49) , will likely incur additional wait states on the Zorro III bus.
This is not intended as a license for making sloppy expansion card
designs, just an acknowledgement that some Zorro II devices may cause a
conflict with the faster Zorro III bus  [timings](../Hardware_Manual_guide/node0298.html) . The best approach is to
make them work, even with a possible performance penalty.

