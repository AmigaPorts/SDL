---
title: 1 / Programming in the Amiga Environment / Libraries of Functions
manual: libraries
chapter: libraries
section: 1-programming-in-the-amiga-environment-libraries-of
functions: [OpenLibrary, Read]
libraries: [dos.library, exec.library]
---

# 1 / Programming in the Amiga Environment / Libraries of Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most of the routines that make up the Amiga's operating system are
organized into groups called libraries.  In order to call a function on
the Amiga you must first open the library that contains the function.  For
example, if you want to call the [Read()](autodocs-2.0/dos-library-read.md) function to read data from disk
you must first open the DOS library.

The system's master library, called [Exec](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md), is always open.  Exec keeps
track of all the other libraries and is in charge of opening and closing
them.  One Exec function, [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md), is used to open all the other
libraries.

Almost any program you write for the Amiga will have to call the
[OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) function.  Usage is as follows:


```c
    struct Library *LibBase;      /* Global: declare this above main() */

    main()
    {
    LibBase = OpenLibrary("library.name",version);

    if(!LibBase) { /* Library did not open, so exit        */ }
    else         { /* Library opened, so use its functions */ }
    }
```
LibBase

```c
    This is a pointer to the library structure in memory, often referred
    to as the library base.  The library base must be global because the
    system uses it to handle the library's function calls.  The name of
    this pointer is established by the system (you cannot use any name
    you want).  Refer to the list below for the appropriate name.
```
library.name

    This is a C string that describes the name of the library you wish to
    open.  The list of Amiga library names is given below.
version

```c
    This should be set to the earliest acceptable [library version](libraries/1-programming-in-the-amiga-environment-operating-system.md).  A
    value of 0 matches any version.  A value of 33 means you require at
    least version 33, or a later version of the library.  If the library
    version in the system is older than the one you specify,
    [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md) will fail (return 0).
```
The following table shows all the function libraries that are currently
part of the Amiga system software.  Column one shows the name string to
use with [OpenLibrary()](autodocs-2.0/exec-library-openlibrary.md); column two shows the name of the global variable
you should use to hold the pointer to the library; column three shows the
oldest [version](libraries/1-programming-in-the-amiga-environment-operating-system.md) of the library still in use.




```c
         Table 1-1: Parameters to Use With OpenLibrary()


                                                    Oldest Version
     Library Name              Library Base Name        In Use
    (library.name)*               (LibBase)            (version)
    --------------             -----------------    --------------
    [asl](autodocs-2.0/asl-doc.md).library                AslBase                    36
    [commodities](autodocs-2.0/commodities-doc.md).library        CxBase                     36
    [diskfont](autodocs-2.0/diskfont-doc.md).library           DiskfontBase               33
    [dos](autodocs-2.0/dos-doc.md).library                DOSBase                    33
    [exec](autodocs-2.0/exec-doc.md).library               SysBase                    33
    [expansion](autodocs-2.0/expansion-doc.md).library          ExpansionBase              33
    [gadtools](autodocs-2.0/gadtools-doc.md).library           GadToolsBase               36
    [graphics](autodocs-2.0/graphics-doc.md).library           GfxBase                    33
    [icon](autodocs-2.0/icon-doc.md).library               IconBase                   33
    [iffparse](autodocs-2.0/iffparse-doc.md).library           IFFParseBase               36
    [intuition](autodocs-2.0/intuition-doc.md).library          IntuitionBase              33
    [keymap](autodocs-2.0/keymap-doc.md).library             KeymapBase                 33
    [layers](autodocs-2.0/layers-doc.md).library             LayersBase                 33
    [mathffp](autodocs-2.0/mathffp-doc.md).library            MathBase                   33
    [mathtrans](autodocs-2.0/mathtrans-doc.md).library          MathTransBase              33
    [mathieeedoubbas](autodocs-2.0/mathieeedoubbas-doc.md).library    MathIeeeDoubBasBase        33
    [mathieeedoubtrans](autodocs-2.0/mathieeedoubtrans-doc.md).library  MathIeeeDoubTransBase      33
    [mathieeesingbas](autodocs-2.0/mathieeesingbas-doc.md).library    MathIeeeSingBasBase        33
    [mathieeesingtrans](autodocs-2.0/mathieeesingtrans-doc.md).library  MathIeeeSingTransBase      33
    [rexxsyslib](autodocs-2.0/rexxsyslib-doc.md).library         RexxSysBase                36
    [translator](autodocs-2.0/translator-doc.md).library         TranslatorBase             33
    [utility](autodocs-2.0/utility-doc.md).library            UtilityBase                36
    [wb](autodocs-2.0/wb-doc.md).library          WorkbenchBase              33
```
  * Other libraries may exist that are not supplied by Amiga, Inc. since


    it is a feature of the operating system to allow such libraries.
 [Opening a Library in C](libraries/1-libraries-of-functions-opening-a-library-in-c.md)            [Another Kind of Function Library](libraries/1-libraries-of-functions-another-kind-of-function-library.md) 
 [Opening a Library in Assembler](libraries/1-libraries-of-functions-opening-a-library-in-assembler.md)    [Libraries, Devices and Resources](libraries/1-libraries-of-functions-libraries-devices-and-resources.md) 

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
- [Read — dos.library](../autodocs/dos.library.md#read)
