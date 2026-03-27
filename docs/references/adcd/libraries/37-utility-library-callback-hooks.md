---
title: 37 Utility Library / Callback Hooks
manual: libraries
chapter: libraries
section: 37-utility-library-callback-hooks
functions: []
libraries: []
---

# 37 Utility Library / Callback Hooks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The callback features of Release 2 provide a standard means for
applications to extend the functionality of libraries, devices, and
applications.  This standard makes it easy for the operating system to use
custom modules from different high level programming languages as part of
the operating system.  For example, the layers library, which takes care
of treating a display as a series of layered regions, allows an
application to attach a pattern function to a display layer.  Instead of
filling in the background of a layer with the background color, the layers
library calls the custom pattern function which fills in the layer display
with a custom background pattern.

 [Callback Hook Structure and Function](libraries/37-callback-hooks-callback-hook-structure-and-function.md) 

