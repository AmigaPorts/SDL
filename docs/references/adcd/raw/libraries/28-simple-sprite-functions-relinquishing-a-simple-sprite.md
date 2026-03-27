# 28 / / Simple Sprite Functions / Relinquishing A Simple Sprite


The [FreeSprite()](../Includes_and_Autodocs_2._guide/node0443.html) function returns a hardware sprite allocated with
[GetSprite()](../Libraries_Manual_guide/node037A.html) to the system so that GELs or other tasks can use it.  After
you call FreeSprite(), the GELs system can use it to allocate VSprites.
The syntax of this function is:


```c
    WORD sprite_number;

    FreeSprite(sprite_number);
```
The sprite_number argument is the number (0-7) of the sprite to be
returned to the system.

