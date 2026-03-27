# 15 Resources / BattMem Resource


The battery-backed memory (BattMem) preserves a small portion of Amiga
memory while the system is powered off.  Some of the information stored in
this memory is used during the system boot sequence.

The battmem resource provides access to the BattMem.  Four functions allow
you to use the BattMem.


```c
                              BattMemResource Functions
                              -------------------------
     [ObtainBattSemaphore()](../Includes_and_Autodocs_2._guide/node0541.html)    Obtain exclusive access to the BattMem.

     [ReadBattMem()](../Includes_and_Autodocs_2._guide/node0542.html)            Read a bitstring from the BattMem.  You
                              specify the bit position and the number of
                              bits you wish to read.

     [ReleaseBattSemaphore()](../Includes_and_Autodocs_2._guide/node0543.html)   Relinquish exclusive access to the BattMem.

     [WriteBattMem()](../Includes_and_Autodocs_2._guide/node0544.html)           Write a bitstring to the BattMem.  You
                              specify the bit position and the number of
                              bits you wish to write.
```
The system considers BattMem to be a set of bits rather than bytes. This
is done to conserve the limited space available. All bits are reserved,
and applications should not read, or write undefined bits. Writing bits
should be done with extreme caution since the settings will survive
power-down/power-up. You can find the bit definitions in the BattMem
include files resources/[battmembitsamiga.h](../Includes_and_Autodocs_2._guide/node0118.html), resources/[battmembitsamix.h](../Includes_and_Autodocs_2._guide/node011C.html)
and resources/[battmembitsshared.h](../Includes_and_Autodocs_2._guide/node0120.html). They should be consulted before you do
anything with the resource.

   You Don't Need This Resource.
   -----------------------------
   The BattMem resource is basically for system use only.  There is
   generally no reason for applications to use it. It is documented here
   simply for completeness.

Additional information on the battmem resource can be found in the include
files and the Autodocs for the battmem resource.


```c
                        BattMem Resource Information
                --------------------------------------------
                INCLUDES        resources/[battmem.i](../Includes_and_Autodocs_2._guide/node0115.html)
                                resources/[battmembitsamiga.h](../Includes_and_Autodocs_2._guide/node0118.html)
                                resources/[battmembitsamix.h](../Includes_and_Autodocs_2._guide/node011C.html)
                                resources/[battmembitsshared.h](../Includes_and_Autodocs_2._guide/node0120.html)
                AUTODOCS        [battmem.doc](../Includes_and_Autodocs_2._guide/node0540.html)
```
