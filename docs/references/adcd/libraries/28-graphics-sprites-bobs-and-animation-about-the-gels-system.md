---
title: 28 Graphics Sprites, Bobs and Animation / About the GELs System
manual: libraries
chapter: libraries
section: 28-graphics-sprites-bobs-and-animation-about-the-gels-system
functions: []
libraries: []
---

# 28 Graphics Sprites, Bobs and Animation / About the GELs System

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Before going into details, a quick glossary is in order.  A playfield
forms the background that GELs operate in.  It encompasses the [View](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md),
[ViewPort](libraries/3-intuition-screens-intuition-screens-and-the-graphics.md), and [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) data structures.  (VSprites appear over, and Bobs
appear in the playfield.)  Playfields can be created and controlled at
several levels.  Refer to the "[Graphics Primitives](libraries/27-graphics-primitives-display-routines-and-structures.md)" and "[Layers Library](libraries/30-layers-library-layers.md)"
chapters for details on lower-level playfield control.  The chapter
"[Intuition Screens](libraries/3-intuition-screens.md)" explains how to get higher-level access to playfields.

GELs, or graphic elements, are special graphic objects that appear in the
foreground and can be moved easily around the display.  They are software
constructs based on the Amiga's sprite and blitter hardware.  The GELs
system is compatible with all playfield modes, including dual-playfield.
All the various types of GELs are defined by data structures found in
<graphics/[gels.h](autodocs-2.0/includes-graphics-gels-h.md)>.

 [Types of GELs](libraries/28-about-the-gels-system-types-of-gels.md)    [The GELs System](libraries/28-about-the-gels-system-the-gels-system.md) 

