---
title: 6 / Setting Up Menus / Intercepting Normal Menu Operations
manual: libraries
chapter: libraries
section: 6-setting-up-menus-intercepting-normal-menu-operations
functions: [ClearMenuStrip]
libraries: [intuition.library]
---

# 6 / Setting Up Menus / Intercepting Normal Menu Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[IDCMP_MENUVERIFY](libraries/9-event-message-classes-and-flags-menu-flags.md) gives the program the opportunity to react before menu
operations take place and, optionally, to cancel menu operations. Menus
may be completely disabled by removing the menu strip with a call to
[ClearMenuStrip()](libraries/6-setting-up-menus-submitting-and-removing-menu-strips.md).

 [A Warning on the MENUSTATE Flag](libraries/6-intercepting-menu-operations-a-warning-on-the-menustate.md)    [Shortcuts and IDCMP_MENUVERIFY](libraries/6-intercepting-menu-operations-shortcuts-and-idcmp.md) 
 [Menu Verify](libraries/6-intercepting-normal-menu-operations-menu-verify.md)                        [IDCMP_MENUVERIFY and Deadlock](libraries/6-intercepting-menu-operations-idcmp-menuverify-and-deadlock.md) 

---

## See Also

- [ClearMenuStrip — intuition.library](../autodocs/intuition.library.md#clearmenustrip)
