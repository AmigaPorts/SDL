# 13 Timer Device / Using the Time Arithmetic Functions


As indicated above, the time arithmetic functions are accessed in the
timer device structure as if they were a routine library. To use them, you
create an [IORequest](../Includes_and_Autodocs_2._guide/node0094.html#line19) block and open the timer.  In the IORequest block is a
pointer to the device's base address. This address is needed to access
each routine as an offset - for example, _LVOAddTime, _LVOSubTime,
_LVOCmpTime - from that base address.


```c
     [Timer_Arithmetic.c](../Devices_Manual_guide/node0199.html) 
```
 [Why Use Time Arithmetic?](../Devices_Manual_guide/node00C7.html) 

