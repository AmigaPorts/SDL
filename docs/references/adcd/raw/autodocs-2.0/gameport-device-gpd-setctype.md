# gameport.device/GPD_SETCTYPE



NAME

    GPD_SETCTYPE -- Set the current game port controller type
FUNCTION

    This command sets the type of device at the game port, so that
    the signals at the port may be properly interpreted.  The port
    can also be turned off, so that no reports are generated.

    This command always executes immediately.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      GPD_SETCTYPE
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       1
    io_Data         the address of the byte variable describing
                    the controller type, as per the equates in
                    the gameport include file
```
