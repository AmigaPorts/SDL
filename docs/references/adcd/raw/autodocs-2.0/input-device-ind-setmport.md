# input.device/IND_SETMPORT



NAME

    IND_SETMPORT -- Set the current mouse port
FUNCTION

    This command sets the gameport port at which the mouse is
    connected.
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      IND_SETMPORT
    io_Flags        IOB_QUICK set if quick I/O is possible
    io_Length       1
    io_Data         a pointer to a byte that is either 0 or 1,
                    indicating that mouse input should be obtained
                    from either the left or right controller port,
                    respectively.
```
