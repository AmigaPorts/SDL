---
title: 8 Intuition Images, Line Drawing and Text / Creating Borders
manual: libraries
chapter: libraries
section: 8-intuition-images-line-drawing-and-text-creating-borders
functions: []
libraries: []
---

# 8 Intuition Images, Line Drawing and Text / Creating Borders

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This data type is called a [Border](libraries/8-creating-borders-border-structure-definition.md) since it was originally used to create
border lines around display objects.  It is actually a general purpose
structure for drawing connected lines between any series of points.

A [Border](libraries/8-creating-borders-border-structure-definition.md) is easier to use than an [Image](libraries/8-creating-images-image-structure.md) structure.  Only the following
need be specified to define a border:

  * An internal position component which is used in determining the final

    position of the border.
  * A set of coordinate pairs for each vertex.

  * A color for the lines.

  * One of several drawing modes.

 [Border Structure Definition](libraries/8-creating-borders-border-structure-definition.md)     [Border Colors and Drawing Modes](libraries/8-creating-borders-border-colors-and-drawing-modes.md) 
 [Directly Drawing the Borders](libraries/8-creating-borders-directly-drawing-the-borders.md)    [Border Coordinates](libraries/8-creating-borders-border-coordinates.md) 
 [Border Example](libraries/lib-examples-shadowborder-c.md)                  [Linking Borders](libraries/8-creating-borders-linking-borders.md) 

