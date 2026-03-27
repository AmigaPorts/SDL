---
title: misc.resource/AllocMiscResource
manual: autodocs-2.0
chapter: autodocs-2.0
section: misc-resource-allocmiscresource
functions: []
libraries: []
---

# misc.resource/AllocMiscResource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME

    AllocMiscResource - allocate one of the miscelaneous resources
SYNOPSIS

```c
    CurrentUser = AllocMiscResource( unitNum, name )
    D0                               D0       A1

    char * AllocMiscResource(ULONG,char *);
```
FUNCTION

```c
    This routine attempts to allocate one of the miscellaneous resources
    If the resource had already been allocated, an error is returned. If
    you do get it, your name is associated with the resource (so a user
    can see who has it allocated).

    This function may not be called from interrupt code
```
DESCRIPTION

```c
    There are certain parts of the hardware that a multitasking- friendly
    program may need to take over.  The serial port is a good example. By
    grabbing the misc.resource for the serial port, the caller would
    "own" the hardware registers associated with that function.  Nobody
    else, including the system serial driver, is allowed to interfere.

    Resources are called in exactly the same manner as libraries.
    From assembly language, A6 must equal the resource base.  The
    offsets for the function are listed in the resources/misc.i
    include file (MR_ALLOCMISCRESOURCE for this function).
```
INPUTS

```c
    unitNum - the number of the resource you want to allocate
              (eg.  MR_SERIALBITS).
    name - a mnenonic name that will help the user figure out
            what piece of software is hogging a resource.
            (havoc breaks out if a name of null is passed in...)
```
RESULTS

    CurrentUser - if the resource is busy, then the name of
            the current user is returned.  If the resource is
            free, then null is returned.
BUGS

SEE ALSO

```c
    resources/misc.i, [FreeMiscResource()](autodocs-2.0/misc-resource-freemiscresource.md)
```
