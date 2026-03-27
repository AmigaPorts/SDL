# K / Signal Description / Data And Related Control Signals


The data time signals here manage the actual transfer of data between
master and slave for both full and short cycle types.  The burst mode
signals are here too, as they're basically data phase signals even through
they don't only concern the transfer of data.

Data Output Enable (DOE)
   This signal is used by an expansion card to enable the buffers on the
   data bus.  The bus master drives this line is to keep slave PICs from
   driving data on the bus until data time.

Data Bus (D0-D31)
   This is the Zorro III data bus, which is driven by either the master
   or the slave when DOE is asserted by the master (based on  [READ](../Hardware_Manual_guide/node02B4.html#line6) ).
   It's valid for reads when /DTACK is asserted by the slave; on writes
   when at least one of /DSn is asserted by the master, for all cycle
   types.

Data Strobes (/DSn)
   These strobes fall during data time; /DS3 strobes D24-D31, while /DS0
   strobes D0-D7. For write cycles, these lines signal data valid on the
   bus.  At all times, they indicate which bytes in the 32-bit data word
   the bus master is actually interested in.  For cachable reads, all
   four bytes must be returned, regardless of the value of the sizing
   strobes.  For writes, only those bytes corresponding to asserted /DSN
   are written.  Only contiguous byte cycles are supported; e.g.,
   /DS3-0 = 2, 4, 5, 6, or 10 is invalid.

Data Transfer Acknowledge (/DTACK)
   This signal is used to normally terminate a Zorro III cycle.  The
   slave is always responsible for driving this signal.  For a read
   cycle, it asserts /DTACK as soon as it has driven valid data onto the
   data bus.  For a write cycle, it asserts /DTACK as soon as it's done
   with the data.  Latching the data on writes may be a good idea; that
   can allow a slave to end the cycle before it has actually finished
   writing the data to its local memory.

Cache Inhibit (/CINH)
   This line is asserted at the same time as  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  to indicate to the
   bus master that the cycle must not be  [cached](../Hardware_Manual_guide/node02A9.html) .  If a device doesn't
   support caching, it must assert /CINH and actually obey the /DSn byte
   strobes for read cycles.  Conversely, if the device supports caching,
   /CINH is negated and the device returns all four bytes valid on
   reads, regardless of the actual supplied /DSn strobes.

Multiple Cycle Transfers (/MTCR, /MTACK)
   These lines comprise the  [Multiple Transfer Cycle](../Hardware_Manual_guide/node02AA.html)  handshake signals.
   The bus master asserts /MTCR at the start of data time if it's
   capable of supporting  [Multiple Transfer Cycles](../Hardware_Manual_guide/node02AA.html) , and the slave asserts
   /MTACK with  [/SLAVEn](../Hardware_Manual_guide/node02B2.html#line3)  if it's capable of supporting
```c
    [Multiple Transfer Cycles](../Hardware_Manual_guide/node02AA.html) .  If the handshake goes through, /MTCR
```
   strobes in the short address and write data as long as the full cycle
   continues.

