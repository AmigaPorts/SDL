---
title: dos.library/Relabel
manual: autodocs-2.0
chapter: autodocs-2.0
section: dos-library-relabel
functions: []
libraries: []
---

# dos.library/Relabel

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    Relabel -- Change the volume name of a volume (V36)
```
SYNOPSIS

```c
    success = Relabel(volumename,name)
    D0                    D1      D2

    BOOL Relabel(STRPTR,STRPTR)
```
FUNCTION

    Changes the volumename of a volume, if supported by the filesystem.
INPUTS

```c
    volumename - Full name of device to rename (with ':')
    newname    - New name to apply to device (without ':')
```
RESULT

    success    - Success/failure indicator
SEE ALSO

