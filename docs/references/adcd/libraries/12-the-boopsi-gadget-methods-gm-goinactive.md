---
title: 12 / / The Boopsi Gadget Methods / GM_GOINACTIVE
manual: libraries
chapter: libraries
section: 12-the-boopsi-gadget-methods-gm-goinactive
functions: [RemoveGList]
libraries: [intuition.library]
---

# 12 / / The Boopsi Gadget Methods / GM_GOINACTIVE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

After an active gadget deactivates, Intuition sends it a GM_GOINACTIVE
message (defined in <intuition/[gadgetclass.h](autodocs-2.0/includes-intuition-gadgetclass-h.md)>):


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
inactive on its own power (because the [GM_GOACTIVE](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md) or [GM_HANDLEINPUT](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md)
method returned something besides [GMR_MEACTIVE](libraries/12-the-boopsi-gadget-methods-gm-goactive-gm-handleinput.md)).  If gpgi_Abort is 1,
Intuition aborted this active gadget.  Some instances where Intuition
aborts a gadget include: the user clicked in another window or screen, an
application removed the active gadget with RemoveGList(),  and an
application called [ActiveWindow()](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md) on a window other than the gadget's
window.

---

## See Also

- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
