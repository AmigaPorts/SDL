---
title: potgo.resource/WritePotgo
manual: autodocs-2.0
chapter: autodocs-2.0
section: potgo-resource-writepotgo
functions: []
libraries: []
---

# potgo.resource/WritePotgo

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    WritePotgo -- Write to the hardware potgo register.
SYNOPSIS

```c
    WritePotgo(word, mask)
               D0    D1

    void WritePotgo( UWORD, UWORD );
```
FUNCTION

    The WritePotgo routine sets and clears bits in the hardware
    potgo register.  Only those bits specified by the mask are
    affected -- it is improper to set bits in the mask that you
    have not successfully allocated.  The bits in the high byte
    are saved to be maintained when other users write to the
    potgo register.  The START bit is not saved, it is written
    only explicitly as the result of a call to this routine with
    the START bit set: other users will not restart it.
INPUTS

    word - the data to write to the hardware potgo register and
        save for further use, except the START bit, which is
        not saved.
    mask - those bits in word that are to be written.  Other
        bits may have been provided by previous calls to
        this routine, and default to zero.
