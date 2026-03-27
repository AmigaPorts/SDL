# 3 / Screen Data Structures / Other Screen Data Structures


In addition to the Screen structure, Intuition uses some other supporting
structures defined in the include file <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html)> and in
<utility/[tagitems.h](../Includes_and_Autodocs_2._guide/node012E.html)>.  (See the Amiga ROM Kernel Reference Manual:
Includes and Autodocs for a complete listing.)




      Table 3-2: Data Structures Used with Intuition Screens
  Structure Name  Description                    Defined in Include File
  --------------  -----------                    -----------------------
  [Screen](../Libraries_Manual_guide/node00DD.html)          Main Intuition structure that   <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html#line97)>

```c
                  defines a screen (see above)
```
  [DrawInfo](../Libraries_Manual_guide/node00EB.html)        Holds the screen's pen, font    <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html#line60)>

                  and aspect data for Intuition
  [TagItem](../Libraries_Manual_guide/node0497.html)         General purpose parameter        <utility/[tagitem.h](../Includes_and_Autodocs_2._guide/node012E.html#line31)>

                  structure used to set up
                  screens in V36
  NewScreen       Parameter structure used to     <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html#line309)>

                  create a screen in V34
  ExtNewScreen    An extension to the NewScreen   <intuition/[screens.h](../Includes_and_Autodocs_2._guide/node00DD.html#line345)>


                  structure used in V37 for
                  backward compatibility with
                  older systems
As [previously mentioned](../Libraries_Manual_guide/node00DC.html), there is an Intuition Screen structure (and a
corresponding graphics [ViewPort](../Libraries_Manual_guide/node00F1.html#line4)) for every screen in memory.  Under
Release 2, whenever a new screen is created, Intuition also creates an
auxiliary data structure called a DrawInfo.

The [DrawInfo](../Libraries_Manual_guide/node00EB.html) structure is similar to a [RastPort](../Libraries_Manual_guide/node00F1.html#line4) in that it holds drawing
information.  But where a RastPort is used at the lower graphics level,
the DrawInfo structure is used at the higher Intuition level.
Specifically, DrawInfo contains data needed to support the New Look of
Intuition in Release 2.  (For more information see the section below,
"[DrawInfo and the 3D Look](../Libraries_Manual_guide/node00EB.html)".)

Another new feature of Release 2 is [tag](../Libraries_Manual_guide/node0496.html) items.  A [TagItem](../Libraries_Manual_guide/node0497.html) is a general
purpose parameter structure used to pass arguments to many of the
functions in the Release 2 system software.  Each tag consists of a LONG
tag ID ([ti_Tag](../Libraries_Manual_guide/node0497.html#line9)) and a LONG tag data value ([ti_Data](../Libraries_Manual_guide/node0497.html#line9)).  With screens, tag
items are used to describe the attributes an application wants for a new,
[custom screen](../Libraries_Manual_guide/node00DF.html).  Tag items replace the NewScreen structure, the set of
parameters used in older versions of the OS to set up a screen.

Applications may wish to use tag items to set up a new screen instead of
the [NewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line309) structure since tag items are often more convenient.  For
the sake of backwards compatibility, the [ExtNewScreen](../Includes_and_Autodocs_2._guide/node00DD.html#line345) structure is
available.  ExtNewScreen combines the NewScreen method used to define
screens in older versions of the OS with the tag item method used in
Release 2.  The [examples](../Libraries_Manual_guide/node00E1.html) listed in the next section show how these various
data structures can be used to set up a new screen.

