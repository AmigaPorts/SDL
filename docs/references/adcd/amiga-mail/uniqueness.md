---
title: Uniqueness
manual: amiga-mail
chapter: amiga-mail
section: uniqueness
functions: [CxBroker]
libraries: [commodities.library]
---

# Uniqueness

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a commodity opens its broker, it can ask Commodities Exchange not
to launch another broker with the same name (nb_Name).  This
uniqueness feature's purpose is to prevent the user from starting
duplicate commodities.  If a commodity asks, Commodities Exchange will
not only refuse to create a new, similarly named broker, but it will
also notify the original commodity if someone tries to do so.

A commodity tells Commodities Exchange not to allow duplicates by
setting certain bits in the nb_Unique field of the NewBroker structure
it sends to CxBroker():


    NBU_UNIQUE      bit 0
    NBU_NOTIFY      bit 1
Setting the NBU_UNIQUE bit prevents duplicate commodities.  Setting
the NBU_NOTIFY bit tells Commodities Exchange to notify a commodity if
an attempt was made to launch a duplicate.  Such a commodity will
receive a CXM_COMMAND CxMessage with an ID of CXCM D_UNIQUE when
someone tries to duplicate it.  Because the uniqueness feature uses
the name a programmer gives a commodity to differentiate it from other
commodities, it is possible for completely different commodities to
share the same name, preventing th e two from coexisting.  For this
reason, a commodity should not use a name that is likely to be in use
by other commodities (like "filter" or "hotkey").

When HotKey gets a CXCMD_UNIQUE CxMessage, it shuts itself down.
HotKey and all the windowless commodities that come with the 2.0
Workbench shut themselves down when they get a CXCMD_UNIQUE CxMessage.
Because the user will expect all windowless commodit ies to work this
way, all windowless commodities should follow this standard.

When the user tries to launch a duplicate of a system commodity that
has a window, the system commodity moves its window to the front of
the display, as if the user had clicked the "Show" gadget in the
controller program's window.  A windowed commodity should mimic
conventions set by existing windowed system commodities, and move its
window to the front of the display.

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
