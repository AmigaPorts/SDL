---
title: D / Errors / CLI Won't Close on RUN
manual: libraries
chapter: libraries
section: d-errors-cli-won-t-close-on-run
functions: [Lock]
libraries: [dos.library]
---

# D / Errors / CLI Won't Close on RUN

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A CLI can't close if a program has a [Lock()](autodocs-2.0/dos-library-lock.md) on the CLI input or output
stream ("*").  If your program is RUN >NIL: from a CLI, that CLI should be
able to close unless your code or your compiler's startup code explicitly
opens "*".

---

## See Also

- [Lock — dos.library](../autodocs/dos.library.md#lock)
