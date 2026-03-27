---
title: workbench.library/AddAppWindowA
manual: autodocs-2.0
chapter: autodocs-2.0
section: workbench-library-addappwindowa
functions: [RemoveAppWindow]
libraries: [workbench.library]
---

# workbench.library/AddAppWindowA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    AddAppWindow - add a window to workbench's list of appwindows.  (V36)
```
SYNOPSIS

```c
    [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) = AddAppWindowA(id, userdata, window, msgport, taglist)
    D0                        D0     D1       A0      A1       A2

    struct [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) *AddAppWindowA(ULONG, ULONG, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
                                    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *, struct [TagItem](autodocs-2.0/includes-utility-tagitem-h.md) *);

    Alternate, varargs version:
    struct [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) *AddAppWindow(ULONG, ULONG, struct [Window](autodocs-2.0/includes-intuition-intuition-h.md) *,
                                    struct [MsgPort](autodocs-2.0/includes-exec-ports-h.md) *
                                    tag1, data1,
                                    tag2, data2,
                                    ...
                                    TAG_END );
```
FUNCTION

```c
    Attempt to add the window to workbench's list of appwindows.
    Normally non-workbench windows (those not opened by workbench)
    cannot have icons dropped in them.  This call is provided to
    allow applications to be notified when an icon or icons get
    dropped inside a window that they have registered with workbench.
    The notification consists of an [AppMessage](autodocs-2.0/includes-workbench-workbench-h.md) (found in workbench.h/i)
    of type 'MTYPE_APPWINDOW' arriving at the message port you specified.
    What you do with the list of icons (pointed to by am_ArgList) is
    up to you, but generally you would want to call [GetDiskObjectNew](autodocs-2.0/icon-library-getdiskobjectnew.md) on
    them.
```
INPUTS

```c
    id       - this variable is strictly for your own use and is ignored
               by workbench.  Typical uses in C are in switch and case
               statements, and in assembly language table lookup.
    userdata - this variable is strictly for your own use and is ignored
               by workbench.
    window   - pointer to window to add.
    msgport  - pointer to message port workbench will use to send you an
               [AppMessage](autodocs-2.0/includes-workbench-workbench-h.md) message of type 'MTYPE_APPWINDOW' when your
               window gets an icon or icons dropped in it.
    taglist  - ptr to a list of tag items.  Must be NULL for V2.0.
```
RESULTS

```c
    [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) - a pointer to an appwindow structure which you pass to
                [RemoveAppWindow](autodocs-2.0/workbench-library-removeappwindow.md) when you want to remove the window
                from workbench's list of appwindows.  NULL
                if workbench was unable to add your window; typically
                happens when workbench is not running or under low
                memory conditions.
```
SEE ALSO

```c
    [RemoveAppWindow()](autodocs-2.0/workbench-library-removeappwindow.md)
```
NOTES
   The V2.0 icon editor is an example of an app window.  Note that app
   window applications generally want to call [GetDiskObjectNew](autodocs-2.0/icon-library-getdiskobjectnew.md)
   (as opposed to GetDiskObject) to get the disk object for the icon
   dropped in the window.

BUGS

    None

---

## See Also

- [RemoveAppWindow — workbench.library](../autodocs/workbench.library.md#removeappwindow)
