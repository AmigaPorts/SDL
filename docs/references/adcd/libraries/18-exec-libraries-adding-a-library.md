---
title: 18 Exec Libraries / Adding a Library
manual: libraries
chapter: libraries
section: 18-exec-libraries-adding-a-library
functions: [AddLibrary, LoadSeg, OpenDevice, OpenLibrary]
libraries: [dos.library, exec.library]
---

# 18 Exec Libraries / Adding a Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec provides several ways to add your own libraries to the system library
list.  One rarely used way is to call [LoadSeg()](autodocs-2.0/dos-library-loadseg.md) (a DOS library function)
to load your library and then use the Exec [MakeLibrary()](autodocs-2.0/exec-library-makelibrary.md) and [AddLibrary()](autodocs-2.0/exec-library-addlibrary.md)
functions to initialize your library and add it to the system.

[MakeLibrary()](autodocs-2.0/exec-library-makelibrary.md) allocates space for the code vectors and data area,
initializes the library node, and initializes the data area according to
your specifications, returning to you a library base pointer.  The base
pointer may then be passed to [AddLibrary()](autodocs-2.0/exec-library-addlibrary.md) to add your library to the
system.

Another way to initialize and add a library or device to the system is
through the use of a [Resident](libraries/18-adding-a-library-resident-romtag-structure.md) structure or romtag (see <exec/[resident.h](autodocs-2.0/includes-exec-resident-h.md)>).
A romtag allows you to place your library or device in a directory
(default LIBS: for libraries, DEVS: for devices) and have the OS
automatically load and initialize it when an application tries to open it
with [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md) or [OpenDevice()](libraries/19-accessing-a-device-opening-a-device.md).

Two additional initialization methods exist for a library or device which
is bound to a particular Amiga expansion board.  The library or device
(containing a romtag) may be placed in the SYS:Expansion drawer, along
with an icon containing the Manufacturer and Product number of the board
it requires.  If the startup-sequence BindDrivers command finds that board
in the system, it will load and initialize the matching Expansion drawer
device or library. In addition, since 1.3, the Amiga system software
supports ROM drivers on expansion boards.  See the "[Expansion Library](libraries/32-expansion-library-expansion-board-drivers.md)"
chapter for additional information on ROM drivers and Expansion drawer
drivers.  The [sample device code](devices/appendix-b-example-device.md) in the Amiga ROM Kernel Reference Manual:
Devices volume of this manual set may be conditionally assembled as an
Expansion drawer driver.

 [Resident (Romtag) Structure](libraries/18-adding-a-library-resident-romtag-structure.md) 

---

## See Also

- [AddLibrary — exec.library](../autodocs/exec.library.md#addlibrary)
- [LoadSeg — dos.library](../autodocs/dos.library.md#loadseg)
- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
