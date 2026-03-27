# serial.device/CloseDevice



NAME

    CloseDevice -- close the serial port
SYNOPSIS
```c
    CloseDevice(deviceNode)
                 A1
```
FUNCTION

```c
    This is an exec call that terminates communication with the
    serial device.  Upon closing, the device's input buffer is freed.

    Note that all IORequests MUST be complete before closing.
     If any are pending, your program must [AbortIO()](../Includes_and_Autodocs_2._guide/node04CA.html) then [WaitIO()](../Includes_and_Autodocs_2._guide/node038B.html)
    to complete them.
```
INPUTS

    deviceNode - pointer to the device node, set by Open
SEE ALSO

```c
    [serial.device/OpenDevice](../Includes_and_Autodocs_2._guide/node04D4.html)
```
