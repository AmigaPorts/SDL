---
title: 18 / What is a Library? / Relationship of Libraries to Devices
manual: libraries
chapter: libraries
section: 18-what-is-a-library-relationship-of-libraries-to-devices
functions: []
libraries: []
---

# 18 / What is a Library? / Relationship of Libraries to Devices

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A device is a software specification for hardware control based on the
[Library](libraries/18-exec-libraries-what-is-a-library.md) structure.  The structures of libraries and devices are so similar
that the routine [MakeLibrary()](libraries/18-exec-libraries-adding-a-library.md) is used to construct both.

Devices require the same initial four code vectors as a library, but must
have two additional code vectors for beginning and terminating special
device I/O commands. The I/O commands that devices are expected to
perform, at minimum, are shown in the "[Exec Device I/O](libraries/19-exec-device-i-o-using-a-device.md)" chapter.  An
[example device](devices/appendix-b-example-device.md) is listed in the Amiga ROM Kernel Reference Manual: Devices.

