---
title: 5 / / Gadget Refreshing by the Program / Gadget Refresh Function
manual: libraries
chapter: libraries
section: 5-gadget-refreshing-by-the-program-gadget-refresh-function
functions: [RefreshGList]
libraries: [intuition.library]
---

# 5 / / Gadget Refreshing by the Program / Gadget Refresh Function

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use the [RefreshGList()](autodocs-2.0/intuition-library-refreshglist.md) function to refresh one or more gadgets in a window
or requester.


```c
    void RefreshGList( struct Gadget *gadgets, struct Window *window,
                       struct Requester *requester, long numGad );
```
This function redraws no more than numGad gadgets, starting with the
specified gadget, in a window or requester.  The application should
refresh any gadgets after adding them.  The function should also be used
after the application has modified the imagery of the gadgets to display
the new imagery.

---

## See Also

- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
