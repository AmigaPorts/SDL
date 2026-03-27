# K Zorro Expansion Bus / Zorro II Compatibility


The A3000 bus is a rather extensive superset of the A2000 bus design.  The
compatibility is based on distinct bus modes, rather than a simple
extension to the existing bus mechanisms. Through the use of an integrated
bus controller (the  [Fat Buster chip](../Hardware_Manual_guide/node02CA.html#line7) ), the expansion bus configures itself
differently for the 16-bit A2000-compatible Zorro II modes than the 32-bit
Zorro III modes.  As a result, while there are still only  [100 pins](../Hardware_Manual_guide/node02C9.html)  on the
expansion bus, some pins change function considerably depending on the bus
activity that's currently in progress.  While the Zorro II modes of the
Zorro III bus are as compatible as possible with the Zorro II bus
specification (especially the A2000 implementation of this specification),
there are some small differences between the two expansion buses.

Aside from these differences, in general, it's important to understand the
Zorro II bus in order to understand the Zorro III bus.  The general
features of the A3000 bus, like  [autoconfiguration](../Hardware_Manual_guide/node029B.html#line30) , the master-slave bus
architecture, and the physical attributes come from the Zorro II expansion
bus.  Other features of the Zorro III bus address shortcomings of the
Zorro II architecture, but Zorro II has a hand in how some of these
shortcomings are solved under Zorro III.  Those with a full understanding
of the Zorro II bus will mainly be concerned with the possible bus
incompatibilities listed here.

 [Changes from the A2000 Bus](../Hardware_Manual_guide/node0291.html)      [Signal Description](../Hardware_Manual_guide/node029C.html) 
 [Zorro II Bus Architecture](../Hardware_Manual_guide/node029B.html) 

