# keyboard.device/KBD_RESETHANDLERDONE



NAME

    KBD_RESETHANDLERDONE -- Indicate that reset handling is done.
FUNCTION

    Indicate that reset cleanup associated with the handler has
    completed.  This command should be issued by all keyboard
    reset handlers so that the reset may proceed.
IO REQUEST

```c
    io_Message      mn_ReplyPort set
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      KBD_RESETHANDLERDONE
    io_Data         a pointer to the handler interrupt structure.
```
NOTES

    The keyboard processor itself performs the hardware reset, and
    will time out and perform the reset even if some reset handlers
    have not indicated yet that the reset may proceed.  This
    timeout is several seconds.
