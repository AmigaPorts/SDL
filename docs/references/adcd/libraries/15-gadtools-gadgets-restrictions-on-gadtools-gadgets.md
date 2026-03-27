---
title: 15 / GadTools Gadgets / Restrictions on GadTools Gadgets
manual: libraries
chapter: libraries
section: 15-gadtools-gadgets-restrictions-on-gadtools-gadgets
functions: [GT_RefreshWindow, OffGadget, OnGadget]
libraries: [gadtools.library, intuition.library]
---

# 15 / GadTools Gadgets / Restrictions on GadTools Gadgets

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There is a strict set of functions and operations that are permitted on
GadTools gadgets.  Even if a technique is discovered that works for a
particular case, be warned that it cannot be guaranteed and should not be
used.  If the trick concocted only works most of the time, it may
introduce subtle problems in the future.

Never selectively or forcibly refresh gadgets.  The only gadget refresh
that should ever be performed is the initial [GT_RefreshWindow()](libraries/15-gadtools-gadgets-gadget-refresh-functions.md) after a
window is opened with GadTools gadgets attached.  It is also possible to
add gadgets after the window is opened by calling AddGlist() and
RefreshGlist() followed by GT_RefreshWindow().  These refresh functions
should not be called at any other time.

GadTools gadgets may not overlap with each other, with other gadgets or
with other imagery.  Doing this to modify the gadget's appearance is not
supported.

GadTools gadgets may not be selectively added or removed from a window.
This has to do with the number of Intuition gadgets that each call to
[CreateGadget()](libraries/15-gadtools-gadgets-creating-gadgets.md) produces and with refresh constraints.

Never use [OnGadget()](libraries/5-intuition-gadgets-gadget-enabling-and-disabling.md) or [OffGadget()](libraries/5-intuition-gadgets-gadget-enabling-and-disabling.md) or directly modify the [GFLG_DISABLED](libraries/5-gadget-structure-gadget-flags.md)
Flags bit.  The only approved way to disable or enable a gadget is to use
[GT_SetGadgetAttrs()](libraries/15-gadtools-gadgets-modifying-gadgets.md) and the GA_Disabled tag.  Those kinds of GadTools
gadgets that do not support GA_Disabled may not be disabled (for now).

The application should never write into any of the fields of the [Gadget](libraries/5-intuition-gadgets-gadget-structure.md)
structure or any of the structures that hang off it, with the exception
noted earlier for [GENERIC_KIND](libraries/15-the-kinds-of-gadtools-gadgets-generic-gadgets.md) gadgets.  Avoid making assumptions about
the contents of these fields unless they are explicitly programmer fields
([GadgetID](libraries/5-intuition-gadgets-gadget-structure.md) and [UserData](libraries/5-intuition-gadgets-gadget-structure.md), for example) or if they are guaranteed meaningful
([LeftEdge](libraries/5-intuition-gadgets-gadget-structure.md), [TopEdge](libraries/5-intuition-gadgets-gadget-structure.md), [Width](libraries/5-intuition-gadgets-gadget-structure.md), [Height](libraries/5-intuition-gadgets-gadget-structure.md), [Flags](libraries/5-intuition-gadgets-gadget-structure.md)).  On occasion, the program is
specifically invited to read a field, for example the [StringInfo->Buffer](libraries/5-string-gadget-type-stringinfo-structure.md)
field.

GadTools gadgets may not be made relative sized or relative positioned.
This means that the gadget flags [GFLG_RELWIDTH](libraries/5-gadget-structure-gadget-flags.md), [GFLG_RELHEIGHT](libraries/5-gadget-structure-gadget-flags.md),
[GFLG_RELBOTTOM](libraries/5-gadget-structure-gadget-flags.md) and [GFLG_RELRIGHT](libraries/5-gadget-structure-gadget-flags.md) may not be specified.  The activation
type of the gadget may not be modified (for example changing
[GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) to [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md)).  The imagery or the highlighting method
may not be changed.

These restrictions are not imposed without reason; subtle or blatant
problems may arise now or in future versions of GadTools for programs that
violate these guidelines.

---

## See Also

- [GT_RefreshWindow — gadtools.library](../autodocs/gadtools.library.md#gt_refreshwindow)
- [OffGadget — intuition.library](../autodocs/intuition.library.md#offgadget)
- [OnGadget — intuition.library](../autodocs/intuition.library.md#ongadget)
