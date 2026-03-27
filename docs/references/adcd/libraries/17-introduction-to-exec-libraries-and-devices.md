---
title: 17 Introduction to Exec / Libraries and Devices
manual: libraries
chapter: libraries
section: 17-introduction-to-exec-libraries-and-devices
functions: [CloseLibrary, OpenLibrary]
libraries: [exec.library]
---

# 17 Introduction to Exec / Libraries and Devices

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One of the design goals for the Amiga OS was to make the system dynamic
enough so that the OS could be extended and updated without effecting
existing applications.  Another design goal was to make it easy for
different applications to be able to share common pieces of code.  The
Amiga accomplished these goals through a system of libraries.  An Amiga
library consists of a collection of related functions which can be
anywhere in system memory (RAM or ROM).

Devices are very similar to libraries, except they usually control some
sort of I/O device and contain some extra standard functions. Although
this section does not really discuss devices directly, the material here
applies to them. For more information on devices, see the "[Exec Device I/O](libraries/19-exec-device-i-o.md)"
section of this manual or the Amiga ROM Kernel Reference Manual:
[Devices](devices/contents-2.md).

An application accesses a library's functions through the library's jump,
or vector, table.  Before a task can use the functions of a particular
library, it must first acquire the library's base pointer by calling the
Exec [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) function:


```c
    struct Library *OpenLibrary( UBYTE *libName,
                                 unsigned long mylibversion );
```
where libName is a string naming the library and mylibversion is a version
number for the library.  The version number reflects a revision of the
system software.  The chart below lists the specific Amiga OS release
versions that system libraries versions correspond to:




```c
    30  Kickstart 1.0 -  This revision is obsolete.
    31  Kickstart 1.1 -  This was an NTSC only release and is obsolete.
    32  Kickstart 1.1 -  This was a PAL only release and is obsolete.
    33  Kickstart 1.2 -  This is the oldest revision of the OS still in
                         use.

    34  Kickstart 1.3 -  This is almost the same as release 1.2 except it
                         has an Autobooting [expansion.library](libraries/17-libraries-and-devices-calling-a-library-function.md)

    35  This is a special RAM-loaded version of the 1.3 revision, except
                         that it knows about the A2024 display modes.  No
                         application should need this library unless they
                         need to open an A2024 display mode under 1.3.

    36  Kickstart 2.0  - This is the original Release 2 revision that was
                         initially shipped on early Amiga 3000 models.

    37  Kickstart 2.04 - This is the general Release 2 revision for all
                         Amiga models.
```
The [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) function looks for a library with a name that matches
libName and also with a version at least as high as mylibversion.  For
example, to open version 33 or greater of the Intuition library:


```c
    IntuitionBase = OpenLibrary("intuition.library", 33L);
```
In this example, if version 33 or greater of the Intuition library is not
available, [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) returns NULL.  A version of zero in OpenLibrary()
tells the OS to open any version of the library.  Unless your code
requires Release 2 features, it should specify a version number of 33 to
remain backwards compatible with Kickstart 1.2.

When [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) looks for a library, it first looks in memory.  If the
library is not in memory, OpenLibrary() will look for the library on disk.
If libName is a library name with an absolute path (for example,
"myapp:mylibs/mylib.library"), OpenLibrary() will follow that absolute
path looking for the library.  If libName is only a library name
("[diskfont.library](libraries/17-libraries-and-devices-calling-a-library-function.md)"), OpenLibrary() will look for the library in the
directory that the LIBS: logical assign currently references.

If [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) finds the library on disk, it takes care of loading it
and initializing it.  As part of the initialization process, OpenLibrary()
dynamically creates a jump, or vector, table.  There is a vector for each
function in the library.  Each entry in the table consists of a 680x0 jump
instruction (JMP) to one of the library functions.  The OS needs to create
the vector table dynamically because the library functions can be anywhere
in memory.

After the library is loaded into memory and initialized, [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) can
actually "open" the library.  It does this by calling the library's [Open](libraries/17-libraries-and-devices-library-vector-offsets-lvos.md)
function vector.  Every library has a standard vector set aside for an
OPEN function so the library can set up any data or processes that it
needs.  Normally, a library's OPEN function increments its open count to
keep track of how many tasks currently have the library opened.

If any step of [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) fails, it returns a NULL value.  If
OpenLibrary() is successful, it returns the address of the library base.
The library base is the address of this library's [Library](libraries/18-exec-libraries-what-is-a-library.md) structure
(defined in <exec/[libraries.h](autodocs-2.0/includes-exec-libraries-h.md)>).  The Library structure immediately
follows the vector table in memory.

After an application is finished with a library, it must close it by
calling [CloseLibrary()](autodocs-2.0/exec-library-closelibrary.md):


```c
    void CloseLibrary(struct Library *libPtr);
```
where libPtr is a pointer to the library base returned when the library
was opened with [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md).

 [Library Vector Offsets (LVOs)](libraries/17-libraries-and-devices-library-vector-offsets-lvos.md)    [Calling a Library Function](libraries/17-libraries-and-devices-calling-a-library-function.md) 

---

## See Also

- [CloseLibrary — exec.library](../autodocs/exec.library.md#closelibrary)
- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
