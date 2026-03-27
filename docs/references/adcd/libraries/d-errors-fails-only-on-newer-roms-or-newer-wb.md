---
title: D / Errors / Fails only on Newer ROMs or Newer WB
manual: libraries
chapter: libraries
section: d-errors-fails-only-on-newer-roms-or-newer-wb
functions: []
libraries: []
---

# D / Errors / Fails only on Newer ROMs or Newer WB

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This should not happen with proper programming.  Possible causes include:
running too close to your stack limits or the memory limits of a base
machine (newer versions of the operating system may use slightly more
stack in system calls, and usually use more free memory); using system
functions improperly; not testing function return values; improper
register or condition code handling in assembler code. Remember that
result, if any, is returned in D0, and condition codes and D1/A0/A1 are
undefined after a system call; using improperly initialized pointers;
trashing memory; assuming something (such as a flag) is B if it is not A;
failing to initialize formerly reserved structure fields to zero;
violating Amiga programming guidelines (for example: depending on or
poking private system structures, jumping into ROM, depending on
undocumented or unsupported behaviors); failure to read the function
Autodocs.

See Appendix E, "[Release 2 Compatibility](libraries/e-release-2-compatibility.md)", for more information on 2.0
compatibility problem areas.

