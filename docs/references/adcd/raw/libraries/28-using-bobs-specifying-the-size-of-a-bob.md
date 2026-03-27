# 28 / Using Bobs / Specifying the Size of a Bob


Bobs do not have the 16-pixel width limit that applies to VSprites.  To
specify the overall size of a Bob, use the [Height and Width](../Includes_and_Autodocs_2._guide/node00C3.html#line102) members of the
root [VSprite](../Libraries_Manual_guide/node0381.html) structure.  Specify the Width as the number of 16-bit words
it takes to fully contain the object.  The number of lines is still
specified with the Height member in the VSprite data structure.

As an example, suppose the Bob is 24 pixels wide and 20 lines tall.  Use
statements like the following to specify the size:


```c
    myVSprite.Height = 20;  /* 20 lines tall. */
    myVSprite.Width  = 2;   /* 24 bits fit into two words. */
```
Because Bobs are drawn into the background playfield, the pixels of the
Bob are the same size as the background pixels, and share the color
palette of the [ViewPort](../Libraries_Manual_guide/node00F1.html#line4).

