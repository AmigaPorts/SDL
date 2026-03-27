---
title: D / Errors / Fails only on Older ROMs or Older WB
manual: libraries
chapter: libraries
section: d-errors-fails-only-on-older-roms-or-older-wb
functions: [OpenLibrary]
libraries: [exec.library]
---

# D / Errors / Fails only on Older ROMs or Older WB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This can be caused by asking for a library version higher than you need
(Do not use the #define LIBRARY_VERSION when compiling!).  Can also be
caused by calling functions or using structures which do not exist in the
older version of the operating system.  Ask for the lowest version which
provides the functions you need (usually 33), and exit gracefully and
informatively if an [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md) fails (returns NULL).  Or code
conditionally to only use new functions and structures if the available
Library's [lib_Version](libraries/18-exec-libraries-what-is-a-library.md) supports them.

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
