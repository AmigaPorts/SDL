# keymap.library/AskKeyMapDefault



NAME

```c
    AskKeyMapDefault -- Ask for a pointer to the current default
                        keymap. (V36)
```
SYNOPSIS

```c
    keyMap = AskKeyMapDefault()

    struct [KeyMap](../Includes_and_Autodocs_2._guide/node003A.html#line22) *AskKeyMapDefault( VOID );
```
FUNCTION

```c
    Return a pointer to the keymap used by the keymap library for
    [MapRawKey](../Includes_and_Autodocs_2._guide/node0315.html) and [MapANSI](../Includes_and_Autodocs_2._guide/node0314.html) when a keymap is not specified.
```
RESULTS

    keyMap - a pointer to a keyMap structure.  This key map is
        guaranteed to be permanently allocated: it will remain in
        memory till the machine is reset.
BUGS

    The keymap.h include file should be in the libraries/ or perhaps
    resources/ directory, but is in the devices/ directory for
    compatability reasons.
SEE ALSO

```c
    [devices/keymap.h](../Includes_and_Autodocs_2._guide/node003A.html), [keymap.library/SetKeyMapDefault()](../Includes_and_Autodocs_2._guide/node0316.html),
    console.device ...KEYMAP functions
```
