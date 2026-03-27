---
title: B / fillrectclass / Attributes: IA_APattern, IA_APatSize (IS)
manual: libraries
chapter: libraries
section: b-fillrectclass-attributes-ia-apattern-ia-apatsize-is
functions: []
libraries: []
---

# B / fillrectclass / Attributes: IA_APattern, IA_APatSize (IS)

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

These attributes supply the [fillrectclass](libraries/b-boopsi-class-reference-fillrectclass.md) object with an area fill
pattern.  The IA_APattern attribute points to the area fill pattern for
the object.  The IA_APatSize attribute is the depth of the area fill
pattern.  These attribute values are similar to the parameters passed to
the SetAfPt() macro (defined in <graphics/[gfxmacros.h](autodocs-2.0/includes-graphics-gfxmacros-h.md)>) and indirectly
correspond to fields in a [RastPort](libraries/27-drawing-routines-the-rastport-structure.md) structure.  For more information on
these patterns, see the section on patterns in the "[Graphics Primitives](libraries/27-rastport-structure-rastport-line-and-area-drawing.md)"
chapter of the Amiga ROM Kernel Reference Manual: Libraries.

