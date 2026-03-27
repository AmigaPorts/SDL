---
title: 15 / GadTools Gadgets / IDCMP Flags
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-idcmp-flags
functions: [ModifyIDCMP]
libraries: [intuition.library]
---

# 15 / GadTools Gadgets / IDCMP Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The various GadTools gadget types require certain classes of IDCMP
messages in order to work.  Applications specify these IDCMP classes when
the window is opened or later with [ModifyIDCMP()](libraries/9-intuition-input-and-output-methods-function-reference.md) (see "[Intuition Windows](libraries/4-window-attributes-window-attribute-tags.md)"
chapter for more on this).  Each kind of GadTools gadget requires
one or more of these IDCMP classes: [IDCMP_GADGETUP](libraries/9-event-message-classes-and-flags-gadget-flags.md), [IDCMP_GADGETDOWN](libraries/9-event-message-classes-and-flags-gadget-flags.md),
[IDCMP_MOUSEMOVE](libraries/9-event-message-classes-and-flags-mouse-flags.md), [IDCMP_MOUSEBUTTONS](libraries/9-event-message-classes-and-flags-mouse-flags.md) and [IDCMP_INTUITICKS](libraries/9-event-message-classes-and-flags-other-flags.md).  As a
convenience, the IDCMP classes required by each kind of gadget are defined
in <libraries/[gadtools.h](autodocs-2.0/includes-libraries-gadtools-h.md)>.  For example, SLIDERIDCMP is defined to be:


```c
    #define SLIDERIDCMP (IDCMP_GADGETUP | IDCMP_GADGETDOWN |
                                          IDCMP_MOUSEMOVE)


    Always OR the IDCMP Flag Bits.
    ------------------------------
    When specifying the IDCMP classes for a window, never add the
    flags together, always OR the bits together.  Since many of the
    GadTools IDCMP constants have multiple bits set, adding the values
    will not lead to the proper flag combination.
```
If a certain kind of GadTools gadget is used, the window must use all
IDCMP classes required by that kind of gadget.  Do not omit any that are
given for that class, even if the application does require the message
type.

Because of the way GadTools gadgets are implemented, programs that use
them always require notification about window refresh events.  Even if the
application performs no rendering of its own, it may not use the
[WFLG_NOCAREREFRESH](libraries/4-window-attributes-boolean-window-attribute-tags.md) window flag and must always set [IDCMP_REFRESHWINDOW](libraries/9-event-message-classes-and-flags-window-flags.md).
See the section on "[Gadget Refresh Functions](libraries/15-gadtools-gadgets-gadget-refresh-functions.md)" later in this chapter for
more on this.

---

## See Also

- [ModifyIDCMP — intuition.library](../autodocs/intuition.library.md#modifyidcmp)
