# 13 Timer Device


The Amiga timer device provides a general interface to the Amiga's
internal clocks.  Through the timer device, time intervals can be
measured, time delays can be effected, system time can be set and
retrieved, and arithmetic operations can be performed on time values.


```c
                  NEW TIMER FEATURES FOR VERSION 2.0

               Feature                 Description
               --------                -----------
               [UNIT_ECLOCK](../Devices_Manual_guide/node00C0.html#line31)             New timer device unit
               [UNIT_WAITUNTIL](../Devices_Manual_guide/node00C0.html#line34)          New timer device unit
               [UNIT_WAITECLOCK](../Devices_Manual_guide/node00C0.html#line40)         New timer device unit
               [ReadEClock()](../Devices_Manual_guide/node00BE.html#line20)            New function
```
   Compatibility Warning:
   ----------------------
   The new features for 2.0 are not backwards compatible.

 [Timer Device Commands and Functions](../Devices_Manual_guide/node00BE.html) 
 [Device Interface](../Devices_Manual_guide/node00BF.html) 
 [System Time](../Devices_Manual_guide/node00C3.html) 
 [Adding a Time Request](../Devices_Manual_guide/node00C4.html) 
 [Using the Time Arithmetic Functions](../Devices_Manual_guide/node00C6.html) 
 [E-Clock Time and Its Relationship to Actual Time](../Devices_Manual_guide/node00C8.html) 
 [Example Timer Program](../Devices_Manual_guide/node0196.html) 
 [Additional Information on the Timer Device](../Devices_Manual_guide/node00C9.html) 

