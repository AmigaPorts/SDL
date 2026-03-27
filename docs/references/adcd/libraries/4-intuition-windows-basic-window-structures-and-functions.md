---
title: 4 Intuition Windows / Basic Window Structures and Functions
manual: libraries
chapter: libraries
section: 4-intuition-windows-basic-window-structures-and-functions
functions: []
libraries: []
---

# 4 Intuition Windows / Basic Window Structures and Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This section introduces the basic data structures and functions an
application uses to create an Intuition window.  Intuition uses the Window
data structure defined in <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)> to represent windows.
Most of Intuition's window functions use this structure in some way.
Other related structures used to create and operate windows are summarized
in Table 4-1.




       Table 4-1: Data Structures Used with Intuition Windows
  Structure Name  Description                    Defined in Include File
  --------------  -----------                    -----------------------
  [Window](libraries/4-intuition-windows-the-window-structure.md)          Main Intuition structure that  <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>

                  defines a window
  [TagItem](libraries/4-opening-a-window-setting-window-attributes.md)         General purpose parameter        <utility/[tagitem.h](autodocs-2.0/includes-utility-tagitem-h.md)>

                  structure used to set up
                  windows in V37
  NewWindow       Parameter structure used to    <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>

                  create a window in V34
  [ExtNewWindow](libraries/4-window-attributes-extended-new-window.md)    An extension to the NewWindow  <intuition/[intuition.h](autodocs-2.0/includes-intuition-intuition-h.md)>

                  structure used in V37 for
                  backward compatibility with
                  older systems
  [Layer](libraries/30-layers-the-layer-structure.md)           A drawing rectangle that          <graphics/[clip.h](autodocs-2.0/includes-graphics-clip-h.md)>

                  clips graphic operations
                  falling within its boundaries
  [RastPort](libraries/27-drawing-routines-the-rastport-structure.md)        General purpose handle used     <graphics/[rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)>


                  for graphics library drawing
                  operations.
Intuition's window system relies on the layers library and graphics
library to implement many of its features.  The Window structure is
closely related to the Layer structure defined in <graphics/[clip.h](autodocs-2.0/includes-graphics-clip-h.md)> and
the RastPort structure defined in <graphics/[rastport.h](autodocs-2.0/includes-graphics-rastport-h.md)>.  The system uses
these structures to store drawing state data. In general, applications
don't have to worry about the internal details of these structures but use
them instead as convenient handles, passing them as arguments to
lower-level functions. See the "[Layers Library](libraries/30-layers-library-layers.md)" and "[Graphics Primitives](libraries/27-graphics-primitives-drawing-routines.md)"
chapters for more information.

 [Opening a Window](libraries/4-basic-window-structures-and-functions-opening-a-window.md)                [Window Dimensions](libraries/4-basic-window-structures-and-functions-window-dimensions.md) 
 [Closing Windows](libraries/4-basic-window-structures-and-functions-closing-windows.md)                 [Window Border Dimensions](libraries/4-basic-window-structures-and-functions-window-border.md) 
 [Windows and Screens](libraries/4-basic-window-structures-and-functions-windows-and-screens.md)             [Changing Window Size Limits](libraries/4-window-structures-and-functions-changing-window-size.md) 
 [Graphics and Text in Windows](libraries/4-window-structures-and-functions-graphics-and-text-in.md) 

