---
title: workbench.library/AddAppMenuItemA
manual: autodocs-2.0
chapter: autodocs-2.0
section: workbench-library-addappmenuitema
functions: [RemoveAppMenuItem]
libraries: [workbench.library]
---

# workbench.library/AddAppMenuItemA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddAppMenuItem - add a menuitem to workbench's list              (V36)
                    of appmenuitems.
```
SYNOPSIS

```c
    [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) = AddAppMenuItemA(id, userdata, text, msgport, taglist)
    D0                            D0     D1      A0     A1       A2

    struct [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) *AddAppMenuItemA(ULONG, ULONG, char *,
                                            struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *,
                                            struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    Alternate, varargs version:
    struct [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) *AddAppMenuItem(ULONG, ULONG, char *,
                                    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *,
                                    tag1, data1,
                                    tag2, data2,
                                    ...
                                    TAG_END );
```
FUNCTION

```c
    Attempt to add the text as a menuitem to workbench's list
    of appmenuitems (the 'Tools' menu strip).
```
INPUTS

```c
    id       - this variable is strictly for your own use and is ignored
               by workbench.  Typical uses in C are in switch and case
               statements, and in assembly language table lookup.
    userdata - this variable is strictly for your own use and is ignored
               by workbench.
    text     - text for the menuitem (char *)
    msgport  - pointer to message port workbench will use to send you an
               [AppMessage](autodocs-2.0/includes-workbench-workbench-h.md) message of type 'MTYPE_APPMENUITEM' when your
               menuitem gets selected.
    taglist  - ptr to a list of tag items.  Must be NULL for V2.0.
```
RESULTS

```c
    [AppMenuItem](autodocs-2.0/includes-workbench-workbench-h.md) - a pointer to an appmenuitem structure which you pass to
                  [RemoveAppMenuItem](autodocs-2.0/workbench-library-removeappmenuitem.md) when you want to remove the menuitem
                  from workbench's list of appmenuitems.  NULL if
                  workbench was unable to add your menuitem; typically
                  happens when workbench is not running or under low
                  memory conditions.
```
SEE ALSO

```c
    [RemoveAppMenuItem()](autodocs-2.0/workbench-library-removeappmenuitem.md)
```
BUGS

    Currently does not limit the system to 63 menu items...
    Any menu items after the 63rd will not be selectable.

---

## See Also

- [RemoveAppMenuItem — workbench.library](../autodocs/workbench.library.md#removeappmenuitem)
