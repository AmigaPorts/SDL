# console.device/CD_ASKDEFAULTKEYMAP



NAME

    CD_ASKDEFAULTKEYMAP -- get the current default keymap
FUNCTION

```c
    Fill the io_Data buffer with the current console device
    default keymap, which is used to initialize console unit
    keymaps when opened, and by [RawKeyConvert](../Includes_and_Autodocs_2._guide/node050A.html) with a null
    keyMap parameter.
```
IO REQUEST

```c
    io_Message      mn_ReplyPort set if quick I/O is not possible
    io_Device       preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0509.html)
    io_Unit         preset by the call to [OpenDevice](../Includes_and_Autodocs_2._guide/node0509.html)
    io_Command      CD_ASKDEFAULTKEYMAP
    io_Flags        IOF_QUICK if quick I/O possible, else zero
    io_Length       sizeof(*keyMap)
    io_Data         struct [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) *keyMap
                    pointer to a structure that describes
                    the raw keycode to byte stream conversion.
```
RESULTS

```c
    This function sets the io_Error field in the [IOStdReq](../Includes_and_Autodocs_2._guide/node0094.html#line28), and fills
    the structure pointed to by io_Data with the current device
    default key map.
```
BUGS

SEE ALSO

```c
    [exec/io.h](../Includes_and_Autodocs_2._guide/node0094.html), [devices/keymap.h](../Includes_and_Autodocs_2._guide/node003A.html), [devices/console.h](../Includes_and_Autodocs_2._guide/node0050.html)
```
