---
title: 5 / Proportional Gadget Type / Modifying an Existing Gadget
manual: libraries
chapter: libraries
section: 5-proportional-gadget-type-modifying-an-existing-gadget
functions: [NewModifyProp]
libraries: [intuition.library]
---

# 5 / Proportional Gadget Type / Modifying an Existing Gadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To change the flags and the [pot](libraries/5-proportional-gadget-components-the-pot-variables.md) and [body](libraries/5-proportional-gadget-components-the-body-variables.md) variables after the gadget is
displayed, the program can call [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md).


```c
    void NewModifyProp( struct Gadget *gadget, struct Window *window,
                        struct Requester *requester, unsigned long flags,
                        unsigned long horizPot, unsigned long vertPot,
                        unsigned long horizBody, unsigned long vertBody,
                        long numGad );
```
The gadget's internal state will be recalculated and the imagery will be
redisplayed to show the new state.  When numGads (in the prototype above)
is set to all ones, [NewModifyProp()](autodocs-2.0/intuition-library-newmodifyprop.md) will only update those parts of the
imagery that have changed, which is much faster than removing the gadget,
changing values, adding the gadget back and refreshing its imagery.

---

## See Also

- [NewModifyProp — intuition.library](../autodocs/intuition.library.md#newmodifyprop)
