# B / gadgetclass / New Methods: GM_GOINACTIVE


This method tells the active gadget to become inactive.  The return value
for this method is not explicitly defined.

GM_GOINACTIVE uses a custom message structure (defined in
<intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line229)>):


```c
    struct gpGoInactive
    {
        ULONG             MethodID;    /* GM_GOINACTIVE */
        struct GadgetInfo *gpgi_GInfo;

    /* V37 field only!  DO NOT attempt to read under V36! */
        ULONG             gpgi_Abort; /* gpgi_Abort=1 if gadget was    */
                                      /* aborted by Intuition and 0 if */
                                      /* gadget went inactive at its   */
                                      /* own request.                  */
    };
```
The gpgi_Abort field contains either a 0 or 1.  If it is 0, the gadget
became inactive at its own request (because the [GM_HANDLEINPUT](../Libraries_Manual_guide/node04F6.html) method
returned something besides [GMR_MEACTIVE](../Libraries_Manual_guide/node04F6.html#line26)).  If gpgi_Abort is 1, Intuition
aborted this active gadget.  Some cases where Intuition aborts a gadget
include: the user clicked in another window or screen, an application
removed the active gadget with [RemoveGList()](../Libraries_Manual_guide/node0133.html#line27), and an application called
[ActivateWindow()](../Libraries_Manual_guide/node010F.html#line19) on a window other than the gadget's window.

If the gadget allocated any resources to cache or precalculate information
in the [GM_GOACTIVE](../Libraries_Manual_guide/node04F5.html) method, it should deallocate those resources in this
method.

