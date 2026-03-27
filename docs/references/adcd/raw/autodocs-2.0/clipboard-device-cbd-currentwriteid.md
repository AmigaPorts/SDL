# clipboard.device/CBD_CURRENTWRITEID



NAME

    CBD_CURRENTWRITEID -- Determine the current write identifier.
FUNCTION

    CBD_CURRENTWRITEID fills the io_ClipID with a clip identifier that
    can be compared with that of a post command: if greater than
    the post identifier then the post is obsolete and need never
    be satisfied.
IO REQUEST

```c
    io_Message      mn_ReplyPort set up
    io_Device       preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Unit         preset by [OpenDevice](../Includes_and_Autodocs_2._guide/node0366.html)
    io_Command      CBD_CURRENTWRITEID
```
RESULTS

    io_ClipID       the ClipID of the current write is set
