# 28 Graphics Sprites, Bobs and Animation / About the GELs System


Before going into details, a quick glossary is in order.  A playfield
forms the background that GELs operate in.  It encompasses the [View](../Libraries_Manual_guide/node00F1.html#line4),
[ViewPort](../Libraries_Manual_guide/node00F1.html#line4), and [RastPort](../Libraries_Manual_guide/node034A.html) data structures.  (VSprites appear over, and Bobs
appear in the playfield.)  Playfields can be created and controlled at
several levels.  Refer to the "[Graphics Primitives](../Libraries_Manual_guide/node0320.html)" and "[Layers Library](../Libraries_Manual_guide/node03E3.html)"
chapters for details on lower-level playfield control.  The chapter
"[Intuition Screens](../Libraries_Manual_guide/node00D7.html)" explains how to get higher-level access to playfields.

GELs, or graphic elements, are special graphic objects that appear in the
foreground and can be moved easily around the display.  They are software
constructs based on the Amiga's sprite and blitter hardware.  The GELs
system is compatible with all playfield modes, including dual-playfield.
All the various types of GELs are defined by data structures found in
<graphics/[gels.h](../Includes_and_Autodocs_2._guide/node00C3.html#line71)>.

 [Types of GELs](../Libraries_Manual_guide/node0371.html)    [The GELs System](../Libraries_Manual_guide/node0377.html) 

