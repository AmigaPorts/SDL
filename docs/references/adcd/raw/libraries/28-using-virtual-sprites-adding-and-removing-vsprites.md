# 28 / Using Virtual Sprites / Adding and Removing VSprites


Once a true VSprite has been set up and initialized, the obvious next step
is to give it to the system by adding it to the GEL list. The VSprite may
then be manipulated as needed.  Before the program ends, the VSprite
should be removed from the GELs list by calling [RemVSprite()](../Includes_and_Autodocs_2._guide/node0471.html). A typical
calling sequence could be performed like so:


```c
    struct VSprite  myVSprite = {0};
    struct RastPort myRastPort = {0};

    AddVSprite(&myVSprite, &myRastPort);

    /* Manipulate the VSprite as needed here */

    RemVSprite(&myVSprite);
```
The &myVSprite argument is a fully initialized [VSprite](../Libraries_Manual_guide/node0381.html) structure and
&myRastPort is the [RastPort](../Libraries_Manual_guide/node034A.html) with which this VSprite is to be associated.
Note that you will probably not like the results if you try to
[RemVSprite()](../Includes_and_Autodocs_2._guide/node0471.html) a VSprite that has not been added to the system with
[AddVSprite()](../Includes_and_Autodocs_2._guide/node0411.html).  See the Amiga ROM Kernel Reference Manual: Includes and
Autodocs for additional information on these functions.

