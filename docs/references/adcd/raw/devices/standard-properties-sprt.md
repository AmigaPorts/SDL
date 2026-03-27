# Standard Properties / SPRT


The presence of an "SPRT" chunk indicates that this image is intended as a
sprite.  It's up to the reader program to actually make it a sprite, if
even possible, and to use or overrule the sprite precedence data inside
the SPRT chunk:


```c
    typedef UWORD SpritePrecedence;/* relative precedence,0 is the high */
```
Precedence 0 is the highest, denoting a sprite that is foremost.

Creating a sprite may imply other setup.  E.g., a 2 plane Amiga sprite
would have transparentColor = 0.  Color registers 1, 2, and 3 in the [CMAP](../Devices_Manual_guide/node01B0.html)
would be stored into the correct hardware color registers for the hardware
sprite number used, while CMAP color register 0 would be ignored.

