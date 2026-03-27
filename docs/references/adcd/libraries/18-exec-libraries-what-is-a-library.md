---
title: 18 Exec Libraries / What is a Library?
manual: libraries
chapter: libraries
section: 18-exec-libraries-what-is-a-library
functions: [OpenLibrary]
libraries: [exec.library]
---

# 18 Exec Libraries / What is a Library?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A library consists of a group of functions somewhere in memory (ROM or
RAM), a vector table, and a [Library](autodocs-2.0/includes-exec-libraries-h.md) structure which can be followed by an
optional private data area for the library.  The library's base pointer
(as returned by [OpenLibrary()](libraries/17-introduction-to-exec-libraries-and-devices.md)) points to the library's Library data
structure:


struct Library
{
```c
    struct  Node lib_Node;
    UBYTE   lib_Flags;
    UBYTE   lib_pad;
    UWORD   lib_NegSize;            /* number of bytes before library */
    UWORD   lib_PosSize;            /* number of bytes after library */
    UWORD   lib_Version;
    UWORD   lib_Revision;
    APTR    lib_IdString;
    ULONG   lib_Sum;                /* the checksum itself */
    UWORD   lib_OpenCnt;            /* number of current opens */
```
};
/* Meaning of the flag bits: */
                               /* A task is currently running a checksum */
#define LIBF_SUMMING (1 << 0)  /* on this library (system maintains this */
```c
                               /* flag)                                  */
```
#define LIBF_CHANGED (1 << 1)  /* One or more entries have been changed  */

```c
                               /* in the library code vectors used by    */
                               /* SumLibrary (system maintains this flag)*/
```
#define LIBF_SUMUSED (1 << 2)  /* A checksum fault should cause a system */
```c
                               /* panic (library flag)                   */
```
#define LIBF_DELEXP (1 << 3)   /* A user has requested expunge but       */


```c
                               /* another user still has the library     */
                               /* open (this is maintained by library)   */
```
 [Using a Library to Reference Data](libraries/18-what-is-a-library-using-a-library-to-reference-data.md)    [Relationship of Libraries to Devices](libraries/18-what-is-a-library-relationship-of-libraries-to-devices.md) 
 [Minimum Subset of Library Vectors](libraries/18-what-is-a-library-minimum-subset-of-library-vectors.md)    [Changing the Contents of a Library](libraries/18-what-is-a-library-changing-the-contents-of-a-library.md) 

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
