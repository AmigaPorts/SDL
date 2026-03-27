---
title: 6 Intuition Menus / A Menu Example
manual: libraries
chapter: libraries
section: 6-intuition-menus-a-menu-example
functions: []
libraries: []
---

# 6 Intuition Menus / A Menu Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This example shows how to implement menus.  The menu code is simply part
of the processing for Intuition messages as shown in the [IDCMP example](libraries/lib-examples-eventloop-c.md) in
the "Intuition Input and Output Methods" chapter.  The example implements
extended selection for menus, adaptation to fonts of different sizes,
mutual exclusion and checkmarks.

If possible, applications should use the menu layout routines available in
the GadTools library, rather than doing the job themselves as this example
does.  See the "[GadTools Library](libraries/15-gadtools-library-gadtools-menus.md)" chapter for more information.


```c
     [menulayout.c](libraries/lib-examples-menulayout-c.md) 
```
