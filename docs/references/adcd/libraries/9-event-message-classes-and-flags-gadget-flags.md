---
title: 9 / / Event Message Classes and Flags / Gadget Flags
manual: libraries
chapter: libraries
section: 9-event-message-classes-and-flags-gadget-flags
functions: []
libraries: []
---

# 9 / / Event Message Classes and Flags / Gadget Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IDCMP_GADGETDOWN

```c
    IDCMP_GADGETDOWN messages are sent when the user selects a gadget
    that was created with the [GACT_IMMEDIATE](libraries/5-gadget-structure-gadget-activation-flags.md) flag set.  The [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)
    structure's [IAddress](libraries/9-using-the-idcmp-intuimessages.md) field will contain a pointer to the selected
    gadget.
```
IDCMP_GADGETUP

```c
    IDCMP_GADGETUP messages are sent when the user selects a gadget that
    was created with the [GACT_RELVERIFY](libraries/5-gadget-structure-gadget-activation-flags.md) flag set.  The [IntuiMessage](libraries/9-using-the-idcmp-intuimessages.md)
    structure's [IAddress](libraries/9-using-the-idcmp-intuimessages.md) field will contain a pointer to the selected
    gadget.
```
IDCMP_CLOSEWINDOW

```c
    IDCMP_CLOSEWINDOW messages are sent when the user selects the
    window's close gadget.  Intuition does not close the window when the
    close gadget is selected.  Rather, an IDCMP_CLOSEWINDOW message is
    sent to the window's IDCMP.  It is up to the application to clean up
    and close the window itself.  If closing a window means losing some
    data (perhaps the spreadsheet the user was working on), it would be
    appropriate for the application to first confirm that the user really
    meant to close the window.
```
