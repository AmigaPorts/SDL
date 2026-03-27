# graphics.library/MoveSprite



NAME

    MoveSprite -- Move sprite to a point relative to top of viewport.
SYNOPSIS

```c
    MoveSprite(vp, sprite, x, y)
               A0  A1      D0 D1

    void MoveSprite(struct [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) *,struct [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) *, WORD, WORD);
```
FUNCTION

    Move sprite image to new place on display.
INPUTS

```c
    vp - pointer to [ViewPort](../Includes_and_Autodocs_2._guide/node00B8.html#line40) structure
         if vp = 0, sprite is positioned relative to [View](../Includes_and_Autodocs_2._guide/node00B8.html#line57).
    sprite - pointer to [SimpleSprite](../Includes_and_Autodocs_2._guide/node00C5.html#line20) structure
    (x,y)  - new position relative to top of viewport or view.
```
RESULTS

    Calculate the hardware information for the sprite and
    place it in the posctldata array. During next video display
    the sprite will appear in new position.
BUGS

    Sprites really appear one pixel to the left of the position you
    specify.  This bug affects the apparent display position of the sprite
    on the screen, but does not affect the numeric position relative to
    the viewport or view.
SEE ALSO

```c
    [FreeSprite()](../Includes_and_Autodocs_2._guide/node0443.html)  [ChangeSprite()](../Includes_and_Autodocs_2._guide/node0427.html)  [GetSprite()](../Includes_and_Autodocs_2._guide/node0449.html)  [graphics/sprite.h](../Includes_and_Autodocs_2._guide/node00C5.html)
```
