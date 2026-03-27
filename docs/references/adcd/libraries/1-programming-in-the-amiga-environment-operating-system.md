---
title: 1 / Programming in the Amiga Environment / Operating System Versions
manual: libraries
chapter: libraries
section: 1-programming-in-the-amiga-environment-operating-system
functions: []
libraries: []
---

# 1 / Programming in the Amiga Environment / Operating System Versions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Amiga operating system has undergone several major revisions
summarized in the table below.  The latest revision is Release 2
(corresponds to library versions 36 and above).


  System library
  version number  Kickstart release
  --------------  -----------------


```c
       0          Any version
       30         Kickstart V1.0 (obsolete)
       31         Kickstart V1.1 (NTSC only - obsolete)
       32         Kickstart V1.1 (PAL only - obsolete)
       33         Kickstart V1.2 (the oldest revision still in use)
       34         Kickstart V1.3 (adds autoboot to V33)
       35         Special Kickstart version to support A2024
                  high-resolution monitor
       36         Kickstart V2.0 (old version of Release 2)
       37         Kickstart V2.04 (current version of Release 2)
```
The examples listed throughout this book assume you are using Release 2.

Many of the libraries and functions documented in this manual are
available in all versions of the Amiga operating system.  Others are
completely new and cannot be used unless you have successfully opened the
appropriate version of the library.

To find out which functions are new with Release 2 refer to the ROM Kernel
Reference Manual: [Includes and Autodocs](autodocs-2.0/autodocs-2-0.md).  The functions which are new are
marked with (V36) or (V37) in the NAME line of the function Autodoc.
These new functions require you to use a matching version number (36, 37,
or higher) when opening the library.

[Exit gracefully](libraries/27-loading-and-displaying-the-view-exiting-gracefully.md) and informatively if the required library version is not
available.

 [About Release 2](libraries/1-operating-system-versions-about-release-2.md) 

