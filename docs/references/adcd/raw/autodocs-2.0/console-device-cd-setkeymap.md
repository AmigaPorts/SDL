# console.device/CD_SETKEYMAP



NAME

    CD_SETKEYMAP -- set the current key map structure for this console
FUNCTION

```c
    Set the current [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) structure used by this console unit to
    the structure pointed to by io_Data.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0509.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0509.html)
    io_Command      CD_SETKEYMAP
    io_Flags        IOF_QUICK if quick I/O possible, else zero
    io_Length       sizeof(*keyMap)
    io_Data         struct [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) *keyMap
                    pointer to a structure that describes
                    the raw keycode to byte stream conversion.
```
RESULTS

```c
    This function sets the io_Error field in the [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28), and fills
    the current key map from the structure pointed to by io_Data.
```
BUGS

SEE ALSO

```c
    [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html), [devices/keymap.h](../Includes_and_Autodocs_2._guide/node003A.html), [devices/console.h](../Includes_and_Autodocs_2._guide/node0050.html)
```
