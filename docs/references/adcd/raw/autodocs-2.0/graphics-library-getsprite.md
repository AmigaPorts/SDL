# graphics.library/GetSprite



NAME

    GetSprite -- Attempt to get a sprite for the simple sprite
                                     manager.
SYNOPSIS

```c
    Sprite_Number = GetSprite( sprite, pick )
        d0                      a0      d0

    SHORT GetSprite( struct [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) *, SHORT );
```
FUNCTION

    Attempt to allocate one of the eight sprites for private use
    with the simple sprite manager. This must be done before using
    further calls to the simple sprite machine. If the programmer
    wants to use 15 color sprites, they must allocate both sprites
    and set the 'SPRITE_ATTACHED' bit in the odd sprite's posctldata
    array.
INPUTS

```c
    sprite - ptr to programmers [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure.
    pick - number in the range of 0-7 or
      -1 if programmer just wants the next one.
```
RESULTS

```c
    If pick is 0-7 attempt to allocate the sprite. If the sprite
    is already allocated then return -1.
    If pick -1 allocate the next sprite starting search at 0.
    If no sprites are available return -1 and fill -1 in num entry
    of [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure.
    If the sprite is available for allocation, mark it allocated
    and fill in the 'num' entry of the [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure.
    If successful return the sprite number.
```
BUGS

SEE ALSO

```c
    [FreeSprite()](../Includes_and_Autodocs_2._guide/node0443.html) [ChangeSprite()](../Includes_and_Autodocs_2._guide/node0427.html) [MoveSprite()](../Includes_and_Autodocs_2._guide/node045E.html) GetSprite() [graphics/sprite.h](../Includes_and_Autodocs_2._guide/node00C5.html)
```
