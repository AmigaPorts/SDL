---
title: 1 / / Libraries of Functions / Another Kind of Function Library
manual: libraries
chapter: libraries
section: 1-libraries-of-functions-another-kind-of-function-library
functions: []
libraries: []
---

# 1 / / Libraries of Functions / Another Kind of Function Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga has two kinds of libraries: run-time libraries and link
libraries.  All the libraries discussed so far are run-time libraries.
Run-time libraries make up most of the Amiga's operating system and are
the main topic of this book.

There is another type of library known as a link library.  Even though a
link library is a collection of functions just like a run-time library,
there are some major differences in the two types.

Run-time libraries

```c
    A run-time, or shared library is a group of functions managed by [Exec](libraries/1-dynamic-memory-architecture-exec-the-system-executive.md)
    that resides either in ROM or on disk (in the LIBS: directory).  A
    run-time library must be opened before it can be used (as explained
    [above](libraries/1-programming-in-the-amiga-environment-libraries-of.md)).  The functions in a run-time library are accessed dynamically
    at run-time and can be used by many programs at once even though only
    one copy of the library is in memory.  A disk based run-time library
    is loaded into memory only if requested by a program and can be
    automatically flushed from memory when no longer needed.
```
Link libraries

```c
    A link library is a group of functions on disk that are managed by
    the compiler at link time.  Link libraries do not have to be opened
    before they are used, instead you must link your code with the
    library when you compile a program.  The functions in a link library
    are actually copied into every program that uses them.  For instance
    the [exit()](autodocs-2.0/dos-library-exit.md) function used in the [C program](libraries/lib-examples-easy-c.md) listed above is not part of
    any of the libraries that make up the Amiga OS.  It comes from the
    link library supplied with the [compiler](libraries/1-introduction-to-amiga-system-libraries-about-the-examples.md) (lc.lib for SAS/Lattice C or
    c.lib for Manx Aztec C).  The code that performs the exit() function
    is copied into the program when it is compiled.
```
