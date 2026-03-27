# keyboard.device/KBD_ADDRESETHANDLER



NAME

    KBD_ADDRESETHANDLER -- Add a keyboard reset handler.
FUNCTION

```c
    Add a function to the list of functions called to clean up
    before a hard reset generated at the keyboard.  The reset
    handler is called as:
        ResetHandler(handlerData)
                     a1
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      KBD_ADDRESETHANDLER
    io_Data         a pointer to an interrupt structure.
        is_Data     the handlerData pointer described above
        is_Code     the Handler function address
```
NOTES

```c
    Few of the Amiga keyboard models generate the communication codes
    used to implement this reset processing.  Specifically, only the
    Euro a1000 (rare), and the B2000 keyboard generate them.

    The interrupt structure is kept by the keyboard device until a
    RemResetHandler command is satisfied for it, but the
    KBD_ADDRESETHANDLER command itself is replied immediately.
```
