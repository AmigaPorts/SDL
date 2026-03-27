---
title: C / New Features of the Enhanced Chip Set / New Genlock Capabilities
manual: hardware
chapter: hardware
section: c-new-features-of-the-enhanced-chip-set-new-genlock
functions: []
libraries: []
---

# C / New Features of the Enhanced Chip Set / New Genlock Capabilities

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The enhanced Denise chip provides the following four  [new genlock](hardware/c-ecs-hardware-and-the-graphics-library-genlock-extensions.md) 
features:

   *  Chromakey
   *  BitPlaneKey
   *  BorderBlank
   *  BorderNotTransparent

ChromaKey allows any color register to control the video overlay.
BitPlaneKey allows any bitplane to enable the video overlay. BorderBlank
creates a transparent "frame" surrounding the active area.
BorderNotTransparent makes an opaque "frame" surrounding the active area.

