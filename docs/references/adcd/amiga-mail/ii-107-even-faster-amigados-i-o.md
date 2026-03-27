---
title: II-107: Even Faster AmigaDOS I/O
manual: amiga-mail
chapter: amiga-mail
section: ii-107-even-faster-amigados-i-o
functions: [Close, Open, Read, Write]
libraries: [dos.library]
---

# II-107: Even Faster AmigaDOS I/O

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Even Faster AmigaDOS I/O


In the September/October 1992 Amiga Mail issue, there is an article by
Martin Taillefer called, ``Fast AmigaDOS I/O''. Most of the article
consists of a code listing.  The code listing is a series of special
I/O routines (plus their Autodocs) that are similar in appearance to
the dos.library synchronous I/O functions Open(), Close(), Read(), and
Write(), but they use asynchronous I/O instead.  These functions shield
the programmer from the complicated, lower-level DOS work, allowing the
application programmer to easily take advantage of the performance of
asynchronous I/O.  They are as easy to use as the synchronous
dos.library I/O calls, but they yield much higher performance.

Of course, Martin Taillefer, the guy who wrote the asynchronous I/O
routines, had to improve upon his work. Besides working out one or two
minor bugs, he has further improved the performance of the code and has
also added a new feature.  There is a new routine called SeekAsync(),
which allows an application to seek into a file while using Martin's
asynchronous DOS I/O calls.

In making these improvements, Martin has made significant changes to
the file that contains the asynchronous I/O functions, AsyncIO.c and
can be found at the end of this article.  The Autodocs for the original
asynchronous I/O functions have not changed, so they have not been
reprinted here.  This article contains only the Autodoc for
SeekAsync().  See the original article, ``Fast AmigaDOS I/O'' for the
remaining files.

 [ASync.doc](amiga-mail/ii-107-async-doc.md) 
 [ASyncExample.c](amiga-mail/ii-107-asyncexample-c.md) 
 [ASyncIO.c](amiga-mail/ii-107-asyncio-c.md) 
 [ASyncIO.h](amiga-mail/ii-107-asyncio-h.md) 

---

## See Also

- [Close — dos.library](../autodocs/dos.library.md#close)
- [Open — dos.library](../autodocs/dos.library.md#open)
- [Read — dos.library](../autodocs/dos.library.md#read)
- [Write — dos.library](../autodocs/dos.library.md#write)
