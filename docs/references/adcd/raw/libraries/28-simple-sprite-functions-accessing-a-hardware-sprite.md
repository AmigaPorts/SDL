# 28 / / Simple Sprite Functions / Accessing A Hardware Sprite


[GetSprite()](../Includes_and_Autodocs_2._guide/node0449.html) is used to gain exclusive access to one of the eight hardware
sprites.  Once you have gained control of a hardware sprite, it can no
longer be allocated by the GELs system for use as a VSprite.  The call is
made like this:


```c
    struct SimpleSprite *sprite;
    SHORT               number;

    if (-1 == (sprite_num = GetSprite(sprite, number)))
        return_code = RETURN_WARN;  /* did not get the sprite */
```
The inputs to the [GetSprite()](../Includes_and_Autodocs_2._guide/node0449.html) function are a pointer to a [SimpleSprite](../Libraries_Manual_guide/node0379.html#line6)
structure and the number (0-7) of the hardware sprite to be accessed, or
-1 to get the first available sprite.

A value of 0-7 is returned if the request was granted, specifying which
sprite was allocated.  A returned value of -1 means the requested sprite
was not available.  If the call succeeds, the [SimpleSprite](../Libraries_Manual_guide/node0379.html#line6) data structure
will have its sprite number field filled in with the appropriate number.

