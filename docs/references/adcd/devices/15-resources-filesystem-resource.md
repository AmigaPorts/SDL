---
title: 15 Resources / FileSystem Resource
manual: devices
chapter: devices
section: 15-resources-filesystem-resource
functions: []
libraries: []
---

# 15 Resources / FileSystem Resource

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The FileSystem resource returns the filesystems that are available on the
Amiga.  It has no functions.  Opening the FileSystem resource returns a
pointer to a [List](autodocs-2.0/includes-exec-lists-h.md) structure containing the current filesystems in the
Amiga.


```c
     [Get_Filesys.c](devices/devices-dev-examples-get-filesys-c.md) 
```
Additional programming information on the FileSystem resource can be found
in the include files and the Autodocs for the FileSystem resource in the
Amiga ROM Kernel Reference Manual: [Includes and Autodocs](autodocs-2.0/includes-and-autodocs-2-0.md) and the
"[Expansion](libraries/32-expansion-library.md)" chapter of the Amiga ROM Kernel Reference Manual: Libraries.


```c
                       FileSystem Resource Information
                    --------------------------------------
                    INCLUDES        resources/[filesysres.h](autodocs-2.0/includes-resources-filesysres-h.md)
                                    resources/[filesysres.i](autodocs-2.0/includes-resources-filesysres-i.md)

                    AUTODOCS        [filesysres.doc](autodocs-2.0/filesysres-doc.md)

                    LIBRARIES       expansion library
```
