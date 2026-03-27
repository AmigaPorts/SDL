# 28 / Using Bobs / Adding a Bob


To add a Bob to the system GEL list, use the [AddBob()](../Includes_and_Autodocs_2._guide/node040F.html) routine.  The [Bob](../Libraries_Manual_guide/node0398.html)
and [VSprite](../Libraries_Manual_guide/node0381.html) structures must be correct and cohesive when this call is
made.  See the [makeBob()](../Libraries_Manual_guide/node059C.html#line129) and [makeVSprite()](../Libraries_Manual_guide/node059C.html#line89) routines in the [animtools.c](../Libraries_Manual_guide/node059C.html)
file listed at the end of this chapter for a detailed example of setting
up Bobs and VSprites.  See the [setupGelSys()](../Libraries_Manual_guide/node059C.html#line28) function for a more complete
example of the initialization of the GELs system.

For example:


```c
    struct GelsInfo myGelsInfo = {0};
    struct VSprite dummySpriteA = {0}, dummySpriteB = {0};
    struct Bob myBob = {0};
    struct RastPort rastport = {0};

    /* Done ONCE, for this GelsInfo.  See setupGelSys() at the end of this
    ** chapter for a more complete initialization of the Gel system
    */
    InitGels(&dummySpriteA, &dummySpriteB, &myGelsInfo);

    /* Initialize the Bob members here, then AddBob() */
    AddBob(&myBob, &rastport);
```
