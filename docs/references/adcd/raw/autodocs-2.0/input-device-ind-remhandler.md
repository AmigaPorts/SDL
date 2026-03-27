# input.device/IND_REMHANDLER



NAME

    IND_REMHANDLER -- Remove an input handler from the device
FUNCTION

    Remove a function previously added to the list of handler
    functions.
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      IND_REMHANDLER
    io_Data         a pointer to the interrupt structure.
```
NOTES

    This command is not immediate
