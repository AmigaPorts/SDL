---
title: battclock.resource/WriteBattClock
manual: autodocs-2.0
chapter: autodocs-2.0
section: battclock-resource-writebattclock
functions: []
libraries: []
---

# battclock.resource/WriteBattClock

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

```c
    WriteBattClock -- Set the time on the clock chip.  (V36)
```
SYNOPSIS

```c
    WriteBattClock( AmigaTime )
                    D0

    void WriteBattClock( ULONG );
```
FUNCTION

    This routine writes the time given in AmigaTime to the clock
    chip.
INPUTS

    AmigaTime       The number of seconds from 01-Jan-1978 to the
                        time that should be written to the clock
                        chip.
RESULTS

NOTES

SEE ALSO

BUGS

