# keymap.library/SetKeyMapDefault



NAME

```c
    SetKeyMapDefault -- Set the current default keymap. (V36)
```
SYNOPSIS

```c
    SetKeyMapDefault(keyMap)

    void SetKeyMapDefault( struct [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) * );
```
FUNCTION

```c
    A pointer to key map specified is cached by the keymap library
    for use by [MapRawKey](../Includes_and_Autodocs_2._guide/node0315.html) and [MapANSI](../Includes_and_Autodocs_2._guide/node0314.html) when a keymap is not specified.
```
INPUTS

    keyMap - a pointer to a keyMap structure.  This key map must be
        permanently allocated: it must remain in memory till the
        machine is reset.  It is appropriate that this keyMap be a
        node on the keymap.resource list.
BUGS

    The keymap.h include file should be in the libraries/ or perhaps
    resources/ directory, but is in the devices/ directory for
    compatability reasons.
SEE ALSO

```c
    [devices/keymap.h](../Includes_and_Autodocs_2._guide/node003A.html), [keymap.library/AskKeyMapDefault()](../Includes_and_Autodocs_2._guide/node0313.html),
    console.device ...KEYMAP functions
```
