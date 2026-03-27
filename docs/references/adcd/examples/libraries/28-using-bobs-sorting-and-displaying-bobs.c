/* Source: ADCD 2.1
 * Section: 28-using-bobs-sorting-and-displaying-bobs
 * Library: libraries
 * ADCD reference: libraries/28-using-bobs-sorting-and-displaying-bobs.md
 */

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
