# 28 / Using Bobs / Sorting and Displaying Bobs


As with VSprites, the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list must be sorted before any Bobs can be
displayed.  This is accomplished with the [SortGList()](../Libraries_Manual_guide/node038B.html#line7) function.  For Bobs,
the system uses the position information to decide inter-Bob priorities,
if not explicitly set by using the [Bob.Before](../Libraries_Manual_guide/node03A4.html) and [Bob.After](../Libraries_Manual_guide/node03A4.html) pointers.

Once the [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list has been sorted, the Bobs in the list can be
displayed by calling [DrawGList()](../Libraries_Manual_guide/node038C.html).  This call should then be followed by a
call to [WaitTOF()](../Libraries_Manual_guide/node038C.html) if the application wants to be sure that the Bobs are
rendered before proceeding.  Call these functions as follows:


```c
    struct RastPort myRastPort = {0};  /* Of course, these have to be */
    struct ViewPort myViewPort = {0};  /* initialized...              */

    SortGList(&myRastPort);
    DrawGList(&myRastPort, &myViewPort);/* Draw the elements (Bobs only) */
    WaitTOF();


    Warning:
    --------
    If your [GelsInfo](../Libraries_Manual_guide/node0377.html#line6) list contains VSprites in addition to Bobs, you
    must also call [MrgCop()](../Libraries_Manual_guide/node038C.html) and [LoadView()](../Libraries_Manual_guide/node038C.html) to make all the GELs
    visible.  Or, under Intuition, [RethinkDisplay()](../Libraries_Manual_guide/node00F4.html#line5) must be called to
    make all the GELs visible.
```
