/* Source: ADCD 2.1
 * Section: gadtools-library-freevisualinfo
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/gadtools-library-freevisualinfo.md
 */

    FreeVisualInfo() returns any memory or other resources that
    were allocated by [GetVisualInfoA()](../Includes_and_Autodocs_2._guide/node03EE.html).  You should only call this function
    once you are done with using the gadgets (i.e. after [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html)),
    but while the screen is still valid (i.e. before [CloseScreen()](../Includes_and_Autodocs_2._guide/node0207.html) or
    [UnlockPubScreen()](../Includes_and_Autodocs_2._guide/node025D.html)).
