# 15 Resources / Misc Resource


The misc resource oversees usage of the serial data port, the serial
communication bits, the parallel data and handshake port, and the parallel
communication bits.  Before using serial or parallel port hardware, it
first must be acquired from the misc resource.

The misc resource provides two functions for allocating and freeing the
serial and parallel hardware.


```c
                             Misc Resource Functions
                             ------------------------
     [AllocMiscResource()](../Includes_and_Autodocs_2._guide/node054D.html)     Allocate one of the serial or parallel
                             misc resources.

     [FreeMiscResource()](../Includes_and_Autodocs_2._guide/node054E.html)      Deallocate one of the serial or
                             parallel misc resources.
```
Once you've successfully allocated one of the misc resources, you are free
to write directly to its hardware locations.  Information on the serial
and parallel hardware can be found in the Amiga [Hardware Reference Manual](../Hardware_Manual_guide/node017C.html)
and the hardware/[custom.h](../Includes_and_Autodocs_2._guide/node00CD.html) include file.

The two examples below are assembly and C versions of the same code for
locking the serial misc resources and waiting for CTRL-C to be pressed
before releasing them.


```c
     [Assembly Example Of Allocating Misc Resources](../Devices_Manual_guide/node01A5.html) 
     [C Example Of Allocating Misc Resources](../Devices_Manual_guide/node0111.html) 
```
