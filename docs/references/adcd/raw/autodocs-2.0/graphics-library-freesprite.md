# graphics.library/FreeSprite



NAME

    FreeSprite -- Return sprite for use by others and virtual
                                      sprite machine.
SYNOPSIS

```c
    FreeSprite( pick )
                d0

    void FreeSprite( WORD );
```
FUNCTION

    Mark sprite as available for others to use.
    These sprite routines are provided to ease sharing of sprite
    hardware and to handle simple cases of sprite usage and
    movement.  It is assumed the programs that use these routines
    do want to be good citizens in their hearts. ie: they will
    not FreeSprite unless they actually own the sprite.
    The Virtual Sprite machine may ignore the simple sprite machine.
INPUTS

    pick - number in range of 0-7
RESULTS

```c
    sprite made available for subsequent callers of [GetSprite](../Includes_and_Autodocs_2._guide/node0449.html)
    as well as use by Virtual Sprite Machine.
```
BUGS

SEE ALSO

```c
    [GetSprite()](../Includes_and_Autodocs_2._guide/node0449.html) [ChangeSprite()](../Includes_and_Autodocs_2._guide/node0427.html) [MoveSprite()](../Includes_and_Autodocs_2._guide/node045E.html) [graphics/sprite.h](../Includes_and_Autodocs_2._guide/node00C5.html)
```
