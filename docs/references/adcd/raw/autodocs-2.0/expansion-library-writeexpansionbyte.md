# expansion.library/WriteExpansionByte



NAME

    WriteExpansionByte - write a byte nybble by nybble.
SYNOPSIS

```c
    WriteExpansionByte( board, offset, byte )
                        A0     D0      D1
```
FUNCTION

```c
    (Not typically called by user code)

    WriteExpansionByte writes a byte to a new-style expansion
    board.  These boards have their writeable data organized
    as a series of nybbles in memory.  This routine writes
    two nybbles in a very careful manner to work with all
    types of new expansion boards.

    To make certain types of board less expensive, an expansion
    board's write registers may be organized as either a
    byte-wide or nybble-wide register.  If it is nybble-wide
    then it must latch the less significant nybble until the
    more significant nybble is written.  This allows the
    following algorithm to work with either type of board:

            write the low order nybble to bits D15-D12 of
                    byte (offset*4)+2

            write the entire byte to bits D15-D8 of
                    byte (offset*4)

    The offset is a byte offset into a [ExpansionRom](../Includes_and_Autodocs_2._guide/node00F6.html#line47) structure.
    The actual memory address read will be four times larger.
    The macros EROFFSET and ECOFFSET are provided to help get
    these offsets from C.
```
INPUTS

    board - a pointer to the base of a new style expansion board.
    offset - a logical offset from the configdev base
    byte - the byte of data to be written to the expansion board.
EXAMPLES

```c
    WriteExpansionByte( cd->BoardAddr, ECOFFSET( ec_Shutup ),  0 );
    WriteExpansionByte( cd->BoardAddr, ECOFFSET( ec_Interrupt ), 1 );
```
SEE ALSO

```c
    [ReadExpansionByte](../Includes_and_Autodocs_2._guide/node03BA.html), [ReadExpansionRom](../Includes_and_Autodocs_2._guide/node03BB.html)
```
