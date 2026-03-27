---
title: 30 / Layers / Opening the Layers Library
manual: libraries
chapter: libraries
section: 30-layers-opening-the-layers-library
functions: []
libraries: []
---

# 30 / Layers / Opening the Layers Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like all libraries, the layers library must be opened before it may be
used.  Check the Layers Autodocs to determine what version of the library
is required for any particular Layers function.


```c
    struct Library *LayersBase;

    if (NULL != (LayersBase = OpenLibrary("layers.library",33L)))
        {
        /* use Layers library */

        CloseLibrary((struct Library *)LayersBase);
        }
```
