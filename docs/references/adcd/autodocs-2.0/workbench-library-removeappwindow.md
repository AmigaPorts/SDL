---
title: workbench.library/RemoveAppWindow
manual: autodocs-2.0
chapter: autodocs-2.0
section: workbench-library-removeappwindow
functions: [AddAppWindowA]
libraries: [workbench.library]
---

# workbench.library/RemoveAppWindow

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemoveAppWindow - remove a window from workbench's list         (V36)
                      of appwindows.
```
SYNOPSIS

```c
    error = RemoveAppWindow(AppWindow)
     D0                       A0
    BOOL RemoveAppWindow(struct [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) *);
```
FUNCTION

    Attempt to remove an appwindow from workbench's list of appwindows.
INPUTS

```c
    [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) - pointer to an [AppWindow](autodocs-2.0/includes-workbench-workbench-h.md) structure returned by
                AddAppWindow.
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
    [AddAppWindowA()](autodocs-2.0/workbench-library-addappwindowa.md)
```
BUGS

    None

---

## See Also

- [AddAppWindowA — workbench.library](../autodocs/workbench.library.md#addappwindowa)
