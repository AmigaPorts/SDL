---
title: 15 / / Functions for GadTools Menus / Freeing Menus
manual: libraries
chapter: libraries
section: 15-functions-for-gadtools-menus-freeing-menus
functions: [FreeMenus]
libraries: [gadtools.library]
---

# 15 / / Functions for GadTools Menus / Freeing Menus

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The [FreeMenus()](autodocs-2.0/gadtools-library-freemenus.md) function frees all the memory allocated by the
corresponding call to [CreateMenus()](libraries/15-functions-for-gadtools-menus-creating-menus.md).


```c
    void FreeMenus( struct Menu *menu );
```
Its one argument is the [Menu](libraries/6-menu-data-structures-menu-structure.md) or [MenuItem](libraries/6-menu-data-structures-menuitem-structure.md) pointer that was returned by
[CreateMenus()](libraries/15-functions-for-gadtools-menus-creating-menus.md).  It is safe to call [FreeMenus()](autodocs-2.0/gadtools-library-freemenus.md) with a NULL parameter,  the
function will then return immediately.

---

## See Also

- [FreeMenus — gadtools.library](../autodocs/gadtools.library.md#freemenus)
