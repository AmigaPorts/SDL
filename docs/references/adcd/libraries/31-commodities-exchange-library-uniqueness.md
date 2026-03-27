---
title: 31 Commodities Exchange Library / Uniqueness
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-uniqueness
functions: [CxBroker]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Uniqueness

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

When a commodity opens its [broker](libraries/31-commodities-exchange-library-installing-a-broker-object.md), it can ask Commodities Exchange not to
launch another broker with the same name ([nb_Name](libraries/31-commodities-exchange-library-installing-a-broker-object.md)).  The purpose of the
uniqueness feature is to prevent the user from starting duplicate
commodities.  If a commodity asks, Commodities Exchange will not only
refuse to create a new, similarly named broker, but it will also notify
the original commodity if someone tries to do so.

A commodity tells Commodities Exchange not to allow duplicates by setting
certain bits in the [nb_Unique field](autodocs-2.0/includes-libraries-commodities-h.md) of the [NewBroker](libraries/31-commodities-exchange-library-installing-a-broker-object.md) structure it sends to
[CxBroker()](libraries/31-commodities-exchange-library-installing-a-broker-object.md):


    NBU_UNIQUE      bit 0
    NBU_NOTIFY      bit 1
Setting the NBU_UNIQUE bit prevents duplicate commodities.  Setting the
NBU_NOTIFY bit tells Commodities Exchange to notify a commodity if an
attempt was made to launch a duplicate.  Such a commodity will receive a
[CXM_COMMAND CxMessage](libraries/31-commodities-exchange-library-cxmessages.md) with an ID of [CXCMD_UNIQUE](autodocs-2.0/includes-libraries-commodities-h.md) when someone tries to
duplicate it. Because the uniqueness feature uses the name a programmer
gives a commodity to differentiate it from other commodities, it is
possible for completely different commodities to share the same name,
preventing the two from coexisting.  For this reason, a commodity should
not use a name that is likely to be in use by other commodities (like
"filter" or "hotkey").  Instead, use a name that matches the commodity
name.

When [HotKey.c](libraries/lib-examples-hotkey-c.md) gets a [CXCMD_UNIQUE](autodocs-2.0/includes-libraries-commodities-h.md) [CxMessage](libraries/31-commodities-exchange-library-cxmessages.md), it shuts itself down.
HotKey.c and all the windowless commodities that come with the Release 2
Workbench shut themselves down when they get a CXCMD_UNIQUE CxMessage.
Because the user will expect all windowless commodities to work this way,
all windowless commodities should follow this standard.

When the user tries to launch a duplicate of a system commodity that has a
window, the system commodity moves its window to the front of the display,
as if the user had clicked the "Show" gadget in the controller program's
window.  A windowed commodity should mimic conventions set by existing
windowed system commodities, and move its window to the front of the
display.

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
