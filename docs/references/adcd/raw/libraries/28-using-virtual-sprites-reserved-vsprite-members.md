# 28 / Using Virtual Sprites / Reserved VSprite Members


These [VSprite](../Libraries_Manual_guide/node0381.html) structure members are reserved for system use (do not write
to them):


```c
    [NextVSprite and PrevVSprite](../Includes_and_Autodocs_2._guide/node00C3.html#line75) -- These are used as links in the
                                   [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list.

         [DrawPath and ClearPath](../Includes_and_Autodocs_2._guide/node00C3.html#line80) -- These are used for Bobs, not true
                                   VSprites.

                  [OldY and OldX](../Includes_and_Autodocs_2._guide/node00C3.html#line87) -- Previous position holder, the system
                                   uses these for double buffered Bobs,
                                   but application programs can read
                                   them too.
```
The values can be set like this:


```c
    myVSprite.NextVSprite = NULL;
    myVSprite.PrevVSprite = NULL;
    myVSprite.DrawPath  = NULL;
    myVSprite.ClearPath = NULL;
    myVSprite.OldY = 0;
    myVSprite.OldX = 0;
```
