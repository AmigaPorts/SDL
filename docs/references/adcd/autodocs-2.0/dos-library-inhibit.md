---
title: dos.library/Inhibit
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-inhibit
functions: []
libraries: []
---

# dos.library/Inhibit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Inhibit -- Inhibits access to a filesystem (V36)
```
SYNOPSIS

```c
    success = Inhibit(filesystem, flag)
    D0                    D1       D2

    BOOL Inhibit(STRPTR,LONG)
```
FUNCTION

    Sends an ACTION_INHIBIT packet to the indicated handler.  This stops
    all activity by the handler until uninhibited.  When uninhibited,
    anything may have happened to the disk in the drive, or there may no
    longer be one.
INPUTS

```c
    filesystem - Name of device to inhibit (with ':')
    flag       - New status.  DOSTRUE = inhibited, FALSE = uninhibited
```
RESULT

    success    - Success/failure indicator
SEE ALSO

