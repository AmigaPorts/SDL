# K / Zorro II Compatibility / Changes from the A2000 Bus


While much effort has been made to assure that the Zorro II mode of the
A3000 bus is as compatible as possible with the A2000 bus, there are a
few points to consider here.  Primarily, the A3000's Zorro II modes are
driven with a state machine that emulates the  [68000 bus](../Hardware_Manual_guide/node029B.html)  protocol.
This emulation must be based on the published Motorola specifications
detailing 68000 bus behavior. While this has the interesting effect of
changing the Zorro II bus from CPU dependent to CPU independent,
there's some margin for trouble.  Zorro II PICs also designed to these
specifications should have no trouble in the A3000 bus in most cases.
However, anything designed based on observed 68000 behavior rather than
documented 68000 operation is at serious risk of failing in an A3000
bus, as one might expect. There are also actual documented differences,
which are listed below.

 [6800 Bus Interface](../Hardware_Manual_guide/node0292.html)                          [Intelligent Cycle Spacing](../Hardware_Manual_guide/node0297.html) 
 [Bus Memory Mapping and Cache Support](../Hardware_Manual_guide/node0293.html)        [Bus Drive and Termination](../Hardware_Manual_guide/node0298.html) 
 [Bus Synchronization Delays](../Hardware_Manual_guide/node0294.html)                  [DMA Latency and Overlap](../Hardware_Manual_guide/node0299.html) 
 [Zorro II Master Access to Local Slaves](../Hardware_Manual_guide/node0295.html)      [Power Supply Differences](../Hardware_Manual_guide/node029A.html) 
 [Bus Arbitration and Fairness](../Hardware_Manual_guide/node0296.html) 

