# K / / Basic Zorro III Bus Cycles / Design Goals


For any computer bus, there are two basic possibilities concerning the
fundamental operation of the bus; it's either synchronous or asynchronous.
The difference is simple -- the synchronous bus is ultimately tied to a
clock of some sort, while the asynchronous bus has no defined relationship
to any clock signal.  While Motorola specifies the 68000 bus cycle as an
asynchronous cycle, they're really referring to the fact that most 68000
inputs are internally synchronized with the bus clock, and therefore,
synchronous setup times on the bus do not have to be met to avoid
metastability.

But the  [68000 bus, and the Zorro II bus](../Hardware_Manual_guide/node029B.html)  by extension, are synchronous
buses, based on a single bus clock (called  [E7M](../Hardware_Manual_guide/node029E.html#line28)  on the Zorro II bus).
Most Zorro II signals are asserted relative to an edge of the bus clock,
and most Zorro II inputs are sampled on an edge of the bus clock.  The
minimum Zorro II cycle is four bus clocks long, and every wait state
added, regardless of the method, will result in a single additional bus
clock wait, regardless of the asynchronous appearance of the  [termination](../Hardware_Manual_guide/node0298.html) 
and wait signals on the Zorro II bus.

The Zorro III bus is a fully asynchronous bus, in that all bus events are
driven by strobes, and there is no reference clock.  The choice of an
asynchronous versus a synchronous bus design is governed by the intended
application of the bus.  Synchronous designs are preferred when a CPU and
a memory system (e.g., master and slave) can be very tightly coupled to
each other.  Such designs generally require a tight adherence to  [timing](../Hardware_Manual_guide/node02B6.html) 
based on the specific CPU.  This is optimal for tightly coupled systems,
such the fast memory on the A3000 local bus.  Synchronous designs can also
be easier to do accurately, as the designer can use clock edges for
scheduling events, and there's never any need to waste time in
synchronizers to achieve a reliable design.

The design goals for an expansion bus are considerably different. While a
fast memory circuit on a system motherboard can change for every new and
better design, it's not feasible to require redesign of any significant
number of expansion cards every time an improved motherboard design is
created.  And while a synchronous transfer can be optimal for matched
clocks, it can be very inefficient for mismatched CPU and expansion
clocks, as synchronizer delays must be introduced for any reliable
operation.  The A3000 project started with the need to support CPU systems
at 16MHz and at 25MHz, and it's obvious that the growth of CPU clock speed
will be here for some time to come.  Zorro III cards are based on
asynchronous handshaking between master and slave in both directions. This
means that, as long as masters and slaves manage their own needs, any
slave can work with any master.  But as masters and slaves improve with
technology, bus transfer speeds can automatically increase, without
rendering any slower cards obsolete.  The Zorro III bus attempts to
address the needs of device expansion as much as the needs of memory
expansion.

