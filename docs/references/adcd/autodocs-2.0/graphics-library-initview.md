---
title: graphics.library/InitView
manual: autodocs-2.0
chapter: autodocs-2.0
section: graphics-library-initview
functions: []
libraries: []
---

# graphics.library/InitView

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

NAME
InitView - Initialize [View](autodocs-2.0/includes-graphics-view-h.md) structure.

SYNOPSIS

```c
    InitView( view )
               a1

    void InitView( struct [View](autodocs-2.0/includes-graphics-view-h.md) * );
```
FUNCTION

```c
    Initialize [View](autodocs-2.0/includes-graphics-view-h.md) structure to default values.
```
INPUTS

```c
    view - pointer to a [View](autodocs-2.0/includes-graphics-view-h.md) structure
```
RESULT

```c
    [View](autodocs-2.0/includes-graphics-view-h.md) structure set to all 0's. (1.0,1.1.1.2)
    Then values are put in DxOffset,DyOffset to properly position
    default display about .5 inches from top and left on monitor.
    InitView pays no attention to previous contents of view.
```
BUGS

SEE ALSO

```c
    [MakeVPort](autodocs-2.0/graphics-library-makevport.md) [graphics/view.h](autodocs-2.0/includes-graphics-view-h.md)
```
