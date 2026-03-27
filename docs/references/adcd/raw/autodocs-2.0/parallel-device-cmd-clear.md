# parallel.device/CMD_CLEAR



NAME

    Clear -- clear the parallel port buffer
FUNCTION

```c
    This command just RTS's (no buffer to clear)
```
IO REQUEST

```c
    io_Message      mn_ReplyPort initialized
    io_Device       set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04F2.html)
    io_Unit         set by [OpenDevice](../Includes_and_Autodocs_2._guide/node04F2.html)
    io_Command      CMD_CLEAR (05)
```
