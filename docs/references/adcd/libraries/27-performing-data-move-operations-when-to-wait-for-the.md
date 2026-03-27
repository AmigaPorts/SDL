---
title: 27 / / Performing Data Move Operations / When to Wait for the Blitter
manual: libraries
chapter: libraries
section: 27-performing-data-move-operations-when-to-wait-for-the
functions: [DisownBlitter, OwnBlitter, WaitBlit]
libraries: [graphics.library]
---

# 27 / / Performing Data Move Operations / When to Wait for the Blitter

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section explains why you might have to call [WaitBlit()](autodocs-2.0/graphics-library-waitblit.md), a special
graphics function that suspends your task until the blitter is idle.  Many
of the calls in the graphics library use the Amiga's hardware blitter to
perform their operation, most notably those which render text and images,
fill or pattern, draw lines or dots and move blocks of graphic memory.

Internally, these graphics library functions operate in a loop, doing
graphic operations with the blitter one plane at a time as follows:


```c
    OwnBlitter();    /* Gain exclusive access to the hardware blitter    */

    for(planes=0; planes < bitmap->depth; planes++)
            {
            WaitBlit();    /* Sleep until the previous blitter operation */
                           /* completes start a blit                     */
            }

    DisownBlitter(); /* Release exclusive access to the hardware blitter */
```
Graphics library functions that are implemented this way always wait for
the blitter at the start and exit right after the final blit is started.
It is important to note that when these blitter-using functions return to
your task, the final (or perhaps only) blit has just been started, but not
necessarily completed.  This is efficient if you are making many such
calls in a row because the next graphics blitter call always waits for the
previous blitter operation to complete before starting its first blit.

However, if you are intermixing such graphics blitter calls with other
code that accesses the same graphics memory then you must first [WaitBlit()](autodocs-2.0/graphics-library-waitblit.md)
to make sure that the final blit of a previous graphics call is complete
before you use any of the memory.  For instance, if you plan to
immediately deallocate or reuse any of the memory areas which were passed
to your most recent blitter-using function call as a source, destination,
or mask, it is imperative that you first call WaitBlit().


    Warning:
    --------
    If you do not follow the above procedure, you could end up with a
    program that works correctly most of the time but crashes sometimes.
    Or you may run into problems when your program is run on faster
    machines or under other circumstances where the blitter is not as
    fast as the processor.

---

## See Also

- [DisownBlitter — graphics.library](../autodocs/graphics.library.md#disownblitter)
- [OwnBlitter — graphics.library](../autodocs/graphics.library.md#ownblitter)
- [WaitBlit — graphics.library](../autodocs/graphics.library.md#waitblit)
