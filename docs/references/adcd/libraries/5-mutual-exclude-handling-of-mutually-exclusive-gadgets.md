---
title: 5 / / Mutual Exclude / Handling of Mutually Exclusive Gadgets
manual: libraries
chapter: libraries
section: 5-mutual-exclude-handling-of-mutually-exclusive-gadgets
functions: [AddGList, RefreshGList, RemoveGList]
libraries: [intuition.library]
---

# 5 / / Mutual Exclude / Handling of Mutually Exclusive Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Use [RemoveGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) to remove the [boolean](libraries/5-intuition-gadgets-boolean-gadget-type.md) gadget from the window or
requester.  Set or clear the [GFLG_SELECTED](libraries/5-gadget-structure-gadget-flags.md) flag to reflect the displayed
state of the gadget.  Replace the gadget using [AddGList()](libraries/5-about-gadgets-adding-and-removing-gadgets.md) and refresh its
imagery with [RefreshGList()](libraries/5-gadget-refreshing-by-the-program-gadget-refresh-function.md).  Of course, several gadgets may be processed
with a single call to each of these functions.

---

## See Also

- [AddGList — intuition.library](../autodocs/intuition.library.md#addglist)
- [RefreshGList — intuition.library](../autodocs/intuition.library.md#refreshglist)
- [RemoveGList — intuition.library](../autodocs/intuition.library.md#removeglist)
