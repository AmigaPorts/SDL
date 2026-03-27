---
title: Background for Designers / What Do We Need?
manual: devices
chapter: devices
section: background-for-designers-what-do-we-need
functions: []
libraries: []
---

# Background for Designers / What Do We Need?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A standard should be long on prescription and short on overhead.  It
should give lots of rules for designing programs and data files for
synergy.  But neither the programs nor the files should cost too much more
than the expedient variety.  Although we are looking to a future with
CD-ROMs and perpendicular recording, the standard must work well on floppy
disks.

For program portability, simplicity, and efficiency, formats should be
designed with more than one implementation style in mind.  It ought to be
possible to read one of many objects in a file without scanning all the
preceding data.   (In practice, pure stream I/O is adequate although
random access makes it easier to write files.)  Some programs need to read
and play out their data in real time, so we need good compromises between
generality and efficiency.

As much as we need standards, they can't hold up product schedules.  So we
also need a kind of decentralized extensibility where any software
developer can define and refine new object types without some "standards
authority" in the loop.  Developers must be able to extend existing
formats in a forward- and backward-compatible way.  A central repository
for design information and example programs can help us take full
advantage of the standard.

For convenience, data formats should heed the restrictions of various
processors and environments.  For example, word-alignment greatly helps
68000 access at insignificant cost to 8088 programs.

Other goals include the ability to share common elements over a list of
objects and the ability to construct composite objects.

And finally, "Simple things should be simple and complex things should be
possible" - Alan Kay.

