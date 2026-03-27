# 13 Timer Device / System Time


The Amiga has a system time feature provided for the convenience of the
developer.  It is a monotonically increasing time base which should be the
same as real time. The timer device provides two commands to use with the
system time.  In addition,  there are utility functions in utility.library
which are very useful with system time.   See the "[Utility Library](../Libraries_Manual_guide/node0495.html)"
chapter of the  Amiga ROM Kernel Reference Manual: Libraries for more
information.

The command [TR_SETSYSTIME](../Includes_and_Autodocs_2._guide/node04FF.html) sets the system's idea of what time it is. The
system starts out at time "zero" so it is safe to set it forward to the
"real" time. However, care should be taken when setting the time
backwards.

The command [TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html) is used to get the system time. The timer device
does not interpret system time to any physical value. By convention, it
tells how many seconds have passed since midnight, January 1, 1978.  Your
program must calculate the time from this value.

The function [GetSysTime()](../Includes_and_Autodocs_2._guide/node04FA.html) can also be used to get the system time. It
returns the same value as [TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html), but uses less overhead.

Whenever someone asks what time it is using [TR_GETSYSTIME](../Includes_and_Autodocs_2._guide/node04FE.html), the return
value of the system time is guaranteed to be unique and unrepeating so
that it can be used by applications as a unique identifier.

   System time at boot time.
   -------------------------
   The timer device sets system time to zero at boot time. AmigaDOS will
   then reset the system time to the value specified on the boot disk.
   If the AmigaDOS C:SetClock command is given, this also resets system
   time.

Here is a program that can be used to determine the system time.
The command is executed by the timer device and, on return, the caller can
find the data in his request block.


```c
     [Get_Systime.c](../Devices_Manual_guide/node0197.html) 
```
