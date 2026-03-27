---
title: 14 / The Workbench Library / Workbench Library Functions
manual: libraries
chapter: libraries
section: 14-the-workbench-library-workbench-library-functions
functions: [AddAppIconA, AddAppMenuItemA, AddAppWindowA]
libraries: [workbench.library]
---

# 14 / The Workbench Library / Workbench Library Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

[AppWindows](libraries/14-workbench-and-icon-library-the-workbench-library.md), [AppIcons](libraries/14-workbench-and-icon-library-the-workbench-library.md) and [AppMenuItems](libraries/14-workbench-and-icon-library-the-workbench-library.md) extend the user's ability to perform
operations with the Workbench iconic interface.  They all provide
graphical methods for passing arguments to a running application. In order
to manage AppWindows, AppIcons and AppMenuItems, the Amiga OS includes
these Workbench library functions:


struct AppIcon     *AddAppIconA( ULONG, ULONG, char *, struct MsgPort *,
```c
                                 struct FileLock *, struct DiskObject *,
                                 struct *TagItem );
```
struct AppMenuItem *AddAppMenuItemA( ULONG, ULONG, char *,
```c
                                     struct MsgPort *, struct *TagItem);
```
struct AppWindow   *AddAppWindowA( ULONG, ULONG, struct Window *,

```c
                                   struct MsgPort *, struct *TagItem);
```
BOOL                RemoveAppIcon(struct AppIcon *);
BOOL                RemoveAppMenuItem(struct AppMenuItem *);
BOOL                RemoveAppWindow(struct AppWindow  *);


The functions [AddAppMenuItemA()](autodocs-2.0/workbench-library-addappmenuitema.md), [AddAppWindowA()](autodocs-2.0/workbench-library-addappwindowa.md) and [AddAppIconA()](autodocs-2.0/workbench-library-addappicona.md) have
alternate entry points using the same function name without the trailing
A.  The alternate functions accept any [TagItem](libraries/37-tags-tag-functions-and-structures.md) arguments on the stack
instead of from an array. See the listings below for examples.

---

## See Also

- [AddAppIconA — workbench.library](../autodocs/workbench.library.md#addappicona)
- [AddAppMenuItemA — workbench.library](../autodocs/workbench.library.md#addappmenuitema)
- [AddAppWindowA — workbench.library](../autodocs/workbench.library.md#addappwindowa)
