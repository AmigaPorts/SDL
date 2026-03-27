---
title: 9 / / Event Message Classes and Flags / Requester Flags
manual: libraries
chapter: libraries
section: 9-event-message-classes-and-flags-requester-flags
functions: []
libraries: []
---

# 9 / / Event Message Classes and Flags / Requester Flags

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IDCMP_REQSET

    Intuition sends an IDCMP_REQSET message to the window each time a
    requester opens in that window.
IDCMP_REQCLEAR

    Intuition sends an IDCMP_REQCLEAR message to the window each time a
    requester is cleared from that window.
IDCMP_REQVERIFY

```c
    Set this flag to allow the application to ensure it is prepared for
    Intuition to render a requester in the window.  With this flag set,
    Intuition sends the application a message that a requester is
    pending, and then waits for the application to reply before drawing
    the requester in the window.

    If several requesters open in the window, Intuition asks the
    application to verify only the first one.  After that, Intuition
    assumes that all output is being held off until all the requesters
    are gone.

    By setting the IDCMP_REQSET and IDCMP_REQCLEAR flags, the application
    can track how many requesters are open in the window and when the
    last requester is cleared.  Once all of the requesters are cleared
    from the window, it is safe to write to the window until another
    IDCMP_REQVERIFY is received.

    See the "[Verification Functions](libraries/9-idcmp-flags-verification-functions.md)" section below for more discussion on
    using this flag.
```
