# serial.device/CloseDevice



   NAME

       CloseDevice -- close the serial port
   SYNOPSIS
```c
       CloseDevice(deviceNode)
                    A1
```
   FUNCTION
       This is an exec call that terminates communication with the
       serial device.  Upon closing, the device's input buffer is freed.

       Note that all IORequests MUST be complete before closing.
	If any are pending, your program must [AbortIO()](../Includes_and_Autodocs_3._guide/node0556.html) then [WaitIO()](../Includes_and_Autodocs_3._guide/node0247.html)

       to complete them.
   INPUTS

```c
       deviceNode - pointer to the device node, set by [Open](../Includes_and_Autodocs_3._guide/node0196.html)
```
   SEE ALSO

```c
       [serial.device/OpenDevice()](../Includes_and_Autodocs_3._guide/node0560.html)
```
