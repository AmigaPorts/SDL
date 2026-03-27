---
title: graphics.library/QBlit
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-qblit
functions: [QBSBlit]
libraries: [graphics.library]
---

# graphics.library/QBlit

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    QBlit -- Queue up a request for blitter usage
SYNOPSIS

```c
    QBlit( bp )
           a1

    void QBlit( struct [bltnode](autodocs-2.0/includes-hardware-blit-h.md) * );
```
FUNCTION

    Link a request for the use of the blitter to the end of the
    current blitter queue.  The pointer bp points to a blit structure
    containing, among other things, the link information, and the
    address of your routine which is to be called when the blitter
    queue finally gets around to this specific request.  When your
    routine is called, you are in control of the blitter ... it is
    not busy with anyone else's requests.  This means that you can
    directly specify the register contents and start the blitter.
    See the description of the blit structure and the uses of QBlit
    in the section titled Graphics Support in the OS Kernel Manual.
    Your code must be written to run either in supervisor or user
    mode on the 68000.
INPUTS

    bp - pointer to a blit structure
RESULT

```c
    Your routine is called when the blitter is ready for you.
    In general requests for blitter usage through this channel are
    put in front of those who use the blitter via [OwnBlitter](autodocs-2.0/graphics-library-ownblitter.md) and
    [DisownBlitter](autodocs-2.0/graphics-library-disownblitter.md). However for small blits there is more overhead
    using the queuer than Own/Disown Blitter.
```
BUGS

SEE ALSO

```c
    [QBSBlit()](autodocs-2.0/graphics-library-qbsblit.md) [hardware/blit.h](autodocs-2.0/includes-hardware-blit-h.md)
```

---

## See Also

- [QBSBlit — graphics.library](../autodocs/graphics.library.md#qbsblit)
