---
title: B / gadgetclass / New Methods: GM_GOINACTIVE
manual: libraries
chapter: libraries
section: b-gadgetclass-new-methods-gm-goinactive
functions: [ActivateWindow, RemoveGList]
libraries: [intuition.library]
---

# B / gadgetclass / New Methods: GM_GOINACTIVE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This method tells the active gadget to become inactive.  The return value
for this method is not explicitly defined.

GM_GOINACTIVE uses a custom message structure (defined in
<intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>):


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
became inactive at its own request (because the [GM_HANDLEINPUT](libraries/b-gadgetclass-new-methods-gm-handleinput.md) method
returned something besides [GMR_MEACTIVE](libraries/b-gadgetclass-new-methods-gm-handleinput.md)).  If gpgi_Abort is 1, Intuition
aborted this active gadget.  Some cases where Intuition aborts a gadget
include: the user clicked in another window or screen, an application
removed the active gadget with [RemoveGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md), and an application called
[ActivateWindow()](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md) on a window other than the gadget's window.

If the gadget allocated any resources to cache or precalculate information
in the [GM_GOACTIVE](libraries/b-gadgetclass-new-methods-gm-goactive.md) method, it should deallocate those resources in this
method.

---

## See Also

- [ActivateWindow — intuition.library](../autodocs/intuition.library.md#activatewindow)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
