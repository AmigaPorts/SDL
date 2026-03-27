# K / / Changes from the A2000 Bus / Bus Arbitration and Fairness


The Zorro II bus is now arbitrated fairly.  The normal slot-based order of
precedence is given to requesting devices, just as in the A2000
implementation.  As always, once a bus master assumes bus mastership, it
has the bus for as long as it wants the bus (of course, trouble can result
if a device takes the bus over for too long).  Once a master gives up the
bus, it will not be granted it back until all subsequent requests have
been serviced.

Bus arbitration at its best will be slightly slower than in the A2000
implementation, due to the fairness logic, but it is impossible to jam the
arbiter with  [asynchronous](../Hardware_Manual_guide/node02A5.html)  bus requests as in the A2000.  The new style
arbiter also holds off bus grants while hidden local bus cycles are in
progress, so there's no guarantee of a minimum time between bus request
and bus grant specified.

