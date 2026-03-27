# 28 / / Simple Sprite Functions / Moving A Simple Sprite


[MoveSprite()](../Includes_and_Autodocs_2._guide/node045E.html) repositions a Simple Sprite.  After this function is called,
the Simple Sprite is moved to a new position relative to the upper left
corner of the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4).  It is called as follows:


```c
    struct ViewPort     *vp;
    struct SimpleSprite *sprite;
    SHORT               x, y;

    MoveSprite(vp, sprite, x, y);
```
There are three inputs to [MoveSprite()](../Includes_and_Autodocs_2._guide/node045E.html).  Set the vp argument to the
address of the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4) with which this Simple Sprite interacts or 0 if
this Simple Sprite's position is relative only to the current [View](../Libraries_Manual_guide/node00F1.html#line4).  Set
sprite to the address of your [SimpleSprite](../Libraries_Manual_guide/node0379.html#line6) data structure.  The x and y
arguments sepcify a pixel position to which the Simple Sprite is to be
moved.

