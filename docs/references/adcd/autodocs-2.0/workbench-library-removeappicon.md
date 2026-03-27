---
title: workbench.library/RemoveAppIcon
manual: autodocs-2.0
chapter: autodocs-2.0
section: workbench-library-removeappicon
functions: [AddAppIconA]
libraries: [workbench.library]
---

# workbench.library/RemoveAppIcon

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    RemoveAppIcon - remove an icon from workbench's list            (V36)
                     of appicons.
```
SYNOPSIS

```c
    error = RemoveAppIcon(AppIcon)
     D0                     A0
    BOOL RemoveAppIcon(struct AppIcon *);
```
FUNCTION

    Attempt to remove an appicon from workbench's list of appicons.
INPUTS

    AppIcon - pointer to an AppIcon structure returned by AddAppIcon.
RESULTS

    error - Currently always TRUE...
NOTES

    As with anything that deals with async operation, you will need to
    do a final check for messages on your App message port for messages
    that may have come in between the last time you checked and the
    call to removed the App.
SEE ALSO

```c
    [AddAppIconA()](autodocs-2.0/workbench-library-addappicona.md)
```
BUGS

    None

---

## See Also

- [AddAppIconA — workbench.library](../autodocs/workbench.library.md#addappicona)
