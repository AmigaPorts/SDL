# 1 Introduction to Amiga System Devices / Example Device Programs


The following short programs are examples of how to use a device.  Both
send the serial device command SDCMD_QUERY to the serial device to
determine the status of the serial device lines and registers.  The first
program is for pre-V36 versions of the operating system (before Release 2)
and the second is for V36 and higher.  You may use the pre-V36 version
with V36 and higher, but you may not use the V36 version with older
systems.

The programs differ in the way they create the message port and I/O
request.  The pre-V36 version uses the amiga.lib functions [CreatePort()](../Includes_and_Autodocs_2._guide/node0148.html) to
create the message port and [CreateExtIO()](../Includes_and_Autodocs_2._guide/node0147.html) to create the I/O request; the
V36 version uses the Exec functions [CreateMsgPort()](../Includes_and_Autodocs_2._guide/node0345.html) to create the message
port and [CreateIORequest()](../Includes_and_Autodocs_2._guide/node0344.html) to create the I/O request.  Those are the only
differences.


```c
     [Device Usage Example (Pre-V36)](../Devices_Manual_guide/node015D.html) 
     [Device Usage Example (Kickstart V36 And Up)](../Devices_Manual_guide/node015E.html) 
```
