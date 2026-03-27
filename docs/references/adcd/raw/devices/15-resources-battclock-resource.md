# 15 Resources / BattClock Resource


The battery-backed clock (BattClock) keeps Amiga time while the system is
powered off.  The time from the BattClock is loaded into the Amiga system
clock as part of the boot sequence.

The battclock resource provides access to the BattClock.  Three functions
allow you to read the BattClock value, reset it and set it to a value you
desire.


```c
                           BattClock Resource Functions
                           ----------------------------
     [ReadBattClock()](../Includes_and_Autodocs_2._guide/node0532.html)       Read the time from the BattClock and
                           returns it as the number of seconds since
                           12:00 AM, January 1, 1978.

     [ResetBattClock()](../Includes_and_Autodocs_2._guide/node0533.html)      Reset the BattClock to 12:00 AM, January 1,
                           1978.

     [WriteBattClock()](../Includes_and_Autodocs_2._guide/node0534.html)      Set the BattClock to the number of seconds
                           you pass it relative to 12:00 AM, January
                           1, 1978.
```
The utility.library contains time functions which convert the number of
seconds since 12:00 AM, January 1, 1978 to a date and time we can
understand, and vice versa.  You will find these functions useful when
dealing with the BattClock.  The example program below uses the
[Amiga2Date()](../Includes_and_Autodocs_2._guide/node03CF.html) utility function to convert  the value returned by
[ReadBattClock()](../Includes_and_Autodocs_2._guide/node0532.html).  See the "[Utility Library](../Libraries_Manual_guide/node0495.html)" chapter of the Amiga ROM
Kernel Reference Manual: Libraries for a discussion of the utility.library
and the Amiga ROM Kernel Reference Manual: [Includes and Autodocs](../Includes_and_Autodocs_2._guide/node03CD.html) for a
listing of its functions.

   So, You Want to Be A Time Lord?
   -------------------------------
   This resource will allow you to set the BattClock to any value you
   desire. Keep in mind that this time will endure a reboot and could
   adversely affect your system.


```c
     [Read_BattClock.c](../Devices_Manual_guide/node01A1.html) 
```
Additional programming information on the battclock resource can be found
in the include files and the Autodocs for the battclock resource and the
utility library.

