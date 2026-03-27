---
title: E / Release 2 Changes That Can Affect Compatibility / Workbench
manual: libraries
chapter: libraries
section: e-release-2-changes-that-can-affect-compatibility-workbench
functions: []
libraries: []
---

# E / Release 2 Changes That Can Affect Compatibility / Workbench

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

  * The Workbench GUI now has new screen sizes, screen top/left offsets,

    depths, modes, and fonts.
  * Default Tool now searches paths.

  * New Look (boxed) icons take more space.

  * Do not use icons which have more 1bits set in [PlanePick](libraries/8-creating-images-image-structure.md) than planes

```c
    in the [ImageData](libraries/8-creating-images-image-structure.md) (one IFF-to-Icon utility does this).  Such icons
    will appear trashed on deeper Workbenches.
```
  * New Look colors have black and white swapped (as compared to 1.3).

  * The Workbench screen may not be open at startup-sequence time until

```c
    some output occurs to the initial Shell window.  This can break
    startup-sequence-started games that think they can steal WB's screen
    bitplanes.  Do not steal the Workbench screen's bitplanes.  (For
    compatibility, booting off pre-2.0 disks forces the initial screen
    open. This is not guaranteed to remain in the system.)  Use startup
    code that can detach when RUN (such as cback.o) and use
    [CloseWorkbench()](libraries/3-public-screen-functions-the-default-public-screen-and.md) to regain the screen's memory.  In addition, see
    "[Workbench and Startup](libraries/e-additional-information-workbench-and-startup.md)" in the "Additional Information" section
    below.
```
