# 12 / / The Boopsi Gadget Methods / GM_GOINACTIVE


After an active gadget deactivates, Intuition sends it a GM_GOINACTIVE
message (defined in <intuition/[gadgetclass.h](../Includes_and_Autodocs_2._guide/node00D3.html#line161)>):


```c
    struct gpGoInactive
    {
        ULONG             MethodID;    /* GM_GOINACTIVE */
        struct GadgetInfo *gpgi_GInfo;

        /* V37 field only!  DO NOT attempt to read under V36!          */
        ULONG             gpgi_Abort; /* gpgi_Abort=1 if gadget was    */
                                      /* aborted by Intuition          */
                                      /* and 0 if gadget went inactive */
                                      /* at its own request.           */
    };
```
The gpgi_Abort field contains either a 0 or 1.  If 0, the gadget became
inactive on its own power (because the [GM_GOACTIVE](../Libraries_Manual_guide/node021C.html) or [GM_HANDLEINPUT](../Libraries_Manual_guide/node021C.html#line26)
method returned something besides [GMR_MEACTIVE](../Libraries_Manual_guide/node021C.html#line67)).  If gpgi_Abort is 1,
Intuition aborted this active gadget.  Some instances where Intuition
aborts a gadget include: the user clicked in another window or screen, an
application removed the active gadget with RemoveGList(),  and an
application called [ActiveWindow()](../Libraries_Manual_guide/node010F.html#line19) on a window other than the gadget's
window.

