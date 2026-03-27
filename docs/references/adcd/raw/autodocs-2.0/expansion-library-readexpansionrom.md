# expansion.library/ReadExpansionRom



NAME

    ReadExpansionRom - read a boards configuration rom space
SYNOPSIS

```c
    error = ReadExpansionRom( board, configDev )
    D0                        A0     A1
```
FUNCTION

```c
    (Not typically called by user code)

    ReadExpansionRom reads a the rom portion of an expansion
    device in to cd_Rom portion of a [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure.
    This routine knows how to detect whether or not there is
    actually a board there,

    In addition, the Rom portion of a new style expansion board
    is encoded in ones-complement format (except for the first
    two nybbles -- the er_Type field).  ReadExpansionRom knows
    about this and un-complements the appropriate fields.
```
INPUTS

```c
    board - a pointer to the base of a new style expansion board.
    configDev - the [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) structure that will be read in.
    offset - a logical offset from the configdev base
```
RESULTS

    error - If the board address does not contain a valid new style
            expansion board, then error will be non-zero.
EXAMPLES


```c
    configDev = AllocConfigDev();
    if( ! configDev ) panic();

    error = ReadExpansionBoard( board, configDev );
    if( ! error ) {
            configDev->cd_BoardAddr = board;
            ConfigBoard( configDev );
    }
```
SEE ALSO

```c
    [ReadExpansionByte](../Includes_and_Autodocs_2._guide/node03BA.html), [WriteExpansionByte](../Includes_and_Autodocs_2._guide/node03BF.html)
```
