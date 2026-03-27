# keyboard.device/KBD_REMRESETHANDLER



NAME

    KBD_REMRESETHANDLER -- Remove a keyboard reset handler.
FUNCTION

```c
    Remove a function previously added to the list of reset
    handler functions with [KBD_ADDRESETHANDLER](../Includes_and_Autodocs_2._guide/node050D.html).
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      KBD_REMRESETHANDLER
    io_Data         a pointer to the handler interrupt structure.
```
