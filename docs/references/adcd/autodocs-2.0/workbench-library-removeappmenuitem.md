---
title: workbench.library/RemoveAppMenuItem
manual: autodocs-2.0
chapter: autodocs-2.0
section: workbench-library-removeappmenuitem
functions: [AddAppMenuItemA]
libraries: [workbench.library]
---

# workbench.library/RemoveAppMenuItem

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemoveAppMenuItem - remove a menuitem from workbench's list      (V36)
                        of appmenuitems.
```
SYNOPSIS

```c
    error = RemoveAppMenuItem(AppMenuItem)
     D0                            A0
    BOOL RemoveAppMenuItem(struct [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) *);
```
FUNCTION

    Attempt to remove an appmenuitem from workbench's list
    of appmenuitems.
INPUTS

```c
    [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) - pointer to an [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) structure returned by
                  AddAppMenuItem.
```
RESULTS

    error - Currently always TRUE...
NOTES

    As with anything that deals with async operation, you will need to
    do a final check for messages on your App message port for messages
    that may have come in between the last time you checked and the
    call to removed the App.
SEE ALSO

```c
    [AddAppMenuItemA()](autodocs-2.0/workbench-library-addappmenuitema.md)
```
BUGS

    None

---

## See Also

- [AddAppMenuItemA — workbench.library](../autodocs/workbench.library.md#addappmenuitema)
