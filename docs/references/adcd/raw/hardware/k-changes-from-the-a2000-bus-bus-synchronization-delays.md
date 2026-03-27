# K / / Changes from the A2000 Bus / Bus Synchronization Delays


Due to the  [asynchronous](../Hardware_Manual_guide/node02A5.html)  nature of the local-to-expansion bus interface
for Zorro II cycles, extra wait states may occasionally be added for local
to expansion or expansion to local cycles.  These are generally manifested
as delays between consecutive cycles, since the bus controller is not
going to require extra waiting during the cycle -- things will have
already been synchronized at that point.  The synchronization problems get
more difficult for Zorro II master access to local bus slaves, and as a
result, wait states here are very common.  The actual number of wait
states generated in any case will be based on the particular
implementation.

