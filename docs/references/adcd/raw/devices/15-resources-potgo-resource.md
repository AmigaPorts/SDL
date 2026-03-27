# 15 Resources / Potgo Resource


The potgo resource is used to get control of the hardware POTGO register
connected to the proportional I/O pins on the game controller ports. There
are two registers, POTGO (write-only) and POTINP (read-only). These pins
could also be used for digital I/O.

The potgo resource provides three functions for working with the POTGO
hardware.


```c
                       Potgo Resource Functions
                       ------------------------
     [AllocPotBits()](../Includes_and_Autodocs_2._guide/node053D.html)    Allocate bits in the POTGO register.

     [FreePotBits()](../Includes_and_Autodocs_2._guide/node053E.html)     Free previously allocated bits in the POTGO
                       register.

     [WritePotgo()](../Includes_and_Autodocs_2._guide/node053F.html)      Set and clear bits in the POTGO register.
                       The bits must have been allocated before
                       calling this function.
```
The example program shown below demonstrates how to use the ptogo resource
to track mouse button presses on port 1.


```c
     [Read_Potinp.c](../Devices_Manual_guide/node01A8.html) 
```
Additional programming information on the potgo resource can be found in
the include files and the Autodocs for the potgo resource.


```c
                         Potgo Resource Information
                      ---------------------------------
                      INCLUDES        resources/[potgo.h](../Includes_and_Autodocs_2._guide/node0114.html)
                                      resources/[potgo.i](../Includes_and_Autodocs_2._guide/node0117.html)
                                      utility/[hooks.h](../Includes_and_Autodocs_2._guide/node012D.html)
                                      utility/[hooks.i](../Includes_and_Autodocs_2._guide/node0131.html)

                      AUTODOCS        [potgo.doc](../Includes_and_Autodocs_2._guide/node053C.html)
```
