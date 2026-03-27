# expansion.library/ConfigBoard



NAME

    ConfigBoard - configure a board
SYNOPSIS

```c
    error = ConfigBoard( board, configDev )
    D0                   A0     A1
```
FUNCTION

```c
    This routine configures an expansion board.  The board
    will generally live at E_EXPANSIONBASE, but the base is
    passed as a parameter to allow future compatibility.
    The configDev parameter must be a valid configDev that
    has already had [ReadExpansionRom()](../Includes_and_Autodocs_2._guide/node03BB.html) called on it.

    ConfigBoard will allocate expansion memory and place
    the board at its new address.  It will update configDev
    accordingly.  If there is not enough expansion memory
    for this board then an error will be returned.
```
INPUTS

```c
    board - the current address that the expansion board is
            responding.
    configDev - an initialized [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure, returned
            by [AllocConfigDev](../Includes_and_Autodocs_2._guide/node03B1.html).
```
RESULTS

```c
    error - non-zero if there was a problem configuring this board
            (Can return EE_OK or EE_NOEXPANSION)
```
SEE ALSO

```c
    [FreeConfigDev](../Includes_and_Autodocs_2._guide/node03B5.html)
```
