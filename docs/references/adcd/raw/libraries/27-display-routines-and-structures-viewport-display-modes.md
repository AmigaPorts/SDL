# 27 / Display Routines and Structures / Viewport Display Modes


The system has many different display modes that you can specify for each
[ViewPort](../Libraries_Manual_guide/node032B.html#line59).  Under 1.3, the eight constants that control the modes are
DUALPF, PFBA, HIRES, SUPERHIRES, LACE, HAM, SPRITES, and EXTRA_HALFBRITE.
Some, but not all of the modes can be combined in a ViewPort.  HIRES and
LACE combine to make a high-resolution, interlaced ViewPort, but HIRES and
SUPERHIRES conflict, and cannot be combined.

Under 1.3, you set these flags directly in the Modes field during
initialization of the [ViewPort](../Libraries_Manual_guide/node032B.html#line59).  Under Release 2, there are many more
display modes possible than in 1.3 so a new system of flags and structures
is used to set the mode.  With Release 2, you set the display mode for a
ViewPort by using the [VideoControl()](../Libraries_Manual_guide/node0339.html#line15) function as described in the section
on "[Monitors, Modes and the Display Database](../Libraries_Manual_guide/node0335.html)" later in this chapter.

The [DUALPF](../Includes_and_Autodocs_2._guide/node00B8.html#line87) and PFBA modes are related.  DUALPF tells the system to treat
the raster specified by this [ViewPort](../Libraries_Manual_guide/node032B.html#line59) as the first of two independent and
separately controllable playfields. It also modifies the manner in which
the pixel colors are selected for this raster (see the [above table](../Libraries_Manual_guide/node0326.html#line71)).

When [PFBA](../Includes_and_Autodocs_2._guide/node00B8.html#line87) is specified, it indicates that the second playfield has video
priority over the first one.  Playfield relative priorities can be
controlled when the playfield is split into two overlapping regions.
Single-playfield and dual-playfield modes are discussed below in
"[Advanced Topics](../Libraries_Manual_guide/node0345.html)."

[HIRES](../Includes_and_Autodocs_2._guide/node00B8.html#line87) tells the system that the raster specified by this [ViewPort](../Libraries_Manual_guide/node032B.html#line59) is to be
displayed with (nominally) 640 horizontal pixels, rather than the 320
horizontal pixels of Lores mode.

[SUPERHIRES](../Includes_and_Autodocs_2._guide/node00B8.html#line87) tells the system that the raster specified by this [ViewPort](../Libraries_Manual_guide/node032B.html#line59) is
to be displayed with (nominally) 1280 horizontal pixels.  This can be used
with 31 kHz scan rates to provide the VGA and Productivity modes available
in Release 2.  SUPERHIRES modes require both the ECS and Release 2.   See
the section on "[Determining Chip Versions](../Libraries_Manual_guide/node031D.html)" earlier in this chapter for an
explanation of how to find out if the ECS is present.

[LACE](../Includes_and_Autodocs_2._guide/node00B8.html#line87) tells the system that the raster specified by this [ViewPort](../Libraries_Manual_guide/node032B.html#line59) is to be
displayed in interlaced mode. If the ViewPort is non-interlaced and the
[View](../Libraries_Manual_guide/node032B.html#line51) is interlaced, the ViewPort will be displayed at its specified height
and will look only slightly different than it would look when displayed in
a non-interlaced View (this is handled by the system automatically). See
"[Interlaced Mode vs. Non-interlaced Mode](../Libraries_Manual_guide/node032A.html)" below for more information.

[HAM](../Includes_and_Autodocs_2._guide/node00B8.html#line87) tells the system to use "hold-and-modify" mode, a special mode that
lets you display up to 4,096 colors on screen at the same time. It is
described in the "[Advanced Topics](../Libraries_Manual_guide/node0348.html)" section.

[SPRITES](../Includes_and_Autodocs_2._guide/node00B8.html#line87) tells the system that you are using sprites in this display
(either [VSprites](../Libraries_Manual_guide/node0380.html) or [Simple Sprites](../Libraries_Manual_guide/node0379.html)). The system will load color registers
for the sprites. Note that since the mouse pointer is a sprite, omitting
this mode will prevent the mouse pointer from being displayed when this
ViewPort is frontmost. See the "[Graphics Sprites, Bobs and Animation](../Libraries_Manual_guide/node036F.html)"
chapter for more information about sprites.

[EXTRA_HALFBRITE](../Includes_and_Autodocs_2._guide/node00B8.html#line87) tells the system to use the Extra-Half-Brite mode, a
special mode that allows you to display up to 64 colors on screen at the
same time.  It is described in the "[Advanced Topics](../Libraries_Manual_guide/node0347.html)" section.

If you peruse the <graphics/[view.h](../Includes_and_Autodocs_2._guide/node00B8.html#line87)> include file you will see another
flag, [EXTENDED_MODE](../Includes_and_Autodocs_2._guide/node00B8.html#line87). Never set this flag yourself; it is used by the
Release 2 system to control more advanced mode features.

Be sure to read the section on "[Monitors, Modes and the Display Database](../Libraries_Manual_guide/node0335.html)"
for additional information about the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) mode and how it has changed
in the Release 2 version of the operating system.

 [Single-playfield Mode vs. Dual-playfield Mode](../Libraries_Manual_guide/node0328.html) 
 [Low-resolution Mode vs. High-resolution Mode](../Libraries_Manual_guide/node0329.html) 
 [Interlaced Mode vs. Non-interlaced Mode](../Libraries_Manual_guide/node032A.html) 

