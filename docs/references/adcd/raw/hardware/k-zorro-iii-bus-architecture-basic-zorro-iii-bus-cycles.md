# K / Zorro III Bus Architecture / Basic Zorro III Bus Cycles


The basic Zorro III bus cycle is a  [multiplexed](../Hardware_Manual_guide/node02AA.html)  address/data cycle which
supplies a full 32 bits worth of address and data per simple cycle.  The
cycle is a fully  [asynchronous](../Hardware_Manual_guide/node02A5.html)  cycle.  The bus master for a given cycle
supplies strobes to indicate when address is valid, write data is valid,
and read data may be driven.  In return, the bus slave for a cycle
supplies a strobe to indicate that it is responding to a bus address, and
a strobe to indicate that it is done with the bus data for a write cycle,
or has supplied valid bus data for a read cycle.  The minimum theoretical
bus speed is governed only by setup and hold time requirements for the
various bus signals.  Actual bus speeds are always a function of the bus
master and bus slave active for a given cycle.  This is considerably
different than the Zorro II bus, and for several good reasons, which are
explained below.

 [Design Goals](../Hardware_Manual_guide/node02A5.html)      [Simple Bus Cycle Operation](../Hardware_Manual_guide/node02A6.html) 

