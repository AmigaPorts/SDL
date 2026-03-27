---
title: 18 / Adding a Library / Resident (Romtag) Structure
manual: libraries
chapter: libraries
section: 18-adding-a-library-resident-romtag-structure
functions: [AddLibrary, InitStruct]
libraries: [exec.library]
---

# 18 / Adding a Library / Resident (Romtag) Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A library or device with a romtag should start with MOVEQ #-1,D0 (to
safely return an error if a user tries to execute the file), followed by a
[Resident](autodocs-2.0/includes-exec-resident-h.md) structure:


```c
    STRUCTURE RT,0
       UWORD RT_MATCHWORD   * romtag identifier (==$4AFC)
       APTR  RT_MATCHTAG    * pointer to the above UWORD (RT_MATCHWORD)
       APTR  RT_ENDSKIP     * usually ptr to end of your code
       UBYTE RT_FLAGS       * usually RTF_AUTOINIT
       UBYTE RT_VERSION     * release version number (for example: 37)
       UBYTE RT_TYPE        * type of module (NT_LIBRARY)
       BYTE  RT_PRI         * initialization priority (for example: 0)
       APTR  RT_NAME        * pointer to node name ("my.library")
       APTR  RT_IDSTRING    * pointer to id string ("name ver.rev (date)")
       APTR  RT_INIT        * pointer to init code or AUTOINIT tables
       LABEL RT_SIZE        * size of a Resident structure (romtag)
```
If you wish to perform [MakeLibrary()](libraries/18-exec-libraries-adding-a-library.md) and [AddLibrary()](libraries/18-exec-libraries-what-is-a-library.md) yourself, then your
RT_FLAGS will not include RTF_AUTOINIT, and RT_INIT will be simply be a
pointer to your own initialization code.  To have Exec automatically load
and initialize the library, set the RTF_AUTOINIT flag in the Resident
structure's RT_FLAGS field, and point RT_INIT to a set four longwords
containing the following:

dataSize

```c
    This is the size of your library data area, i.e., the combined size
    of the standard [Library](libraries/18-exec-libraries-what-is-a-library.md) node structure plus your own library-specific
    data.
```
vectors

    This is a pointer to a table of pointers to your library's functions,
    terminated with a -1.  If the first word of the table is -1, then the
    table is interpreted as a table of words specifying the relative
    displacement of each function entry point from the start of the
    table.  Otherwise it is treated as a table of longword address
    pointers to the functions.  vectors must specify a valid table
    address.
structure

```c
    This parameter points to the base of an [InitStruct()](libraries/20-allocating-multiple-memory-summary-of-allocation-routines.md) data region.
    That is, it points to the first location within a table that the
    InitStruct() routine can use to initialize your [Library](libraries/18-exec-libraries-what-is-a-library.md) node
    structure, library-specific data, and other memory areas.
    InitStruct() will typically be used to initialize the data segment of
    the library, perhaps forming data tables, task control blocks, I/O
    control blocks, etc. If this entry is a 0, then InitStruct() is not
    called.
```
initFunction

```c
    This points to a routine that is to be executed after the library (or
    device) node has been allocated and the code and data areas have been
    initialized.  When the routine is called, the base address of the
    newly created library is passed in D0.  If initFunction is zero, no
    initialization routine is called.
```
Complete source code for an RT_AUTOINIT library may be found in the
[appendix C](libraries/c-sample-library-source-code.md) of this book.

---

## See Also

- [AddLibrary — exec.library](../autodocs/exec.library.md#addlibrary)
- [InitStruct — exec.library](../autodocs/exec.library.md#initstruct)
