---
title: Hand-Coded Version Strings
manual: amiga-mail
chapter: amiga-mail
section: hand-coded-version-strings
functions: []
libraries: []
---

# Hand-Coded Version Strings

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The hand-coded method can be used in text files and is often quite
suitable for simple programs with a single code module.  If you code
the version strings by hand, they should be formatted like the examples
below.  The example hand-coded strings are for a program named myapp,
version 37.1, date 20-Mar-91 (20.3.91):

In C:



```c
    UBYTE versiontag[] = "\0$VER: appname 37.1 (20.3.91)";
```
In assembler:



```c
    versiontag      dc.b 0,'$VER: myapp 37.1 (20.3.91)',0
```
In a text file:



```c
    $VER: myapp.doc 37.1 (20.3.91)
```
Note that the NULL ("\0" or 0,) at the beginning of the versiontag
string is not necessary but can be useful if you choose to #define the
string and wish to give a version number to  a C program with no data
segment.  With the initial NULL, you can concatenate a #defined
versiontag string onto an arbitrary immediate string used in your code
to get the versiontag into your code segment.

