# 27 / / The RastPort Structure / Initializing a RastPort Structure


Once you have a [BitMap](../Libraries_Manual_guide/node032B.html#line74) set up, you can declare and initialize the [RastPort](../Libraries_Manual_guide/node034A.html)
and then link the BitMap into it.  Here is a sample initialization
sequence:


```c
    struct BitMap bitMap = {0};
    struct RastPort rastPort = {0};

    /* Initialize the RastPort and link the BitMap to it. */
    InitRastPort(&rastPort);
    rastPort.BitMap = &bitMap;


    Initialize, Then Link.
    ----------------------
    You cannot link the bitmap in until after the [RastPort](../Libraries_Manual_guide/node034A.html) has been
    initialized.
```
