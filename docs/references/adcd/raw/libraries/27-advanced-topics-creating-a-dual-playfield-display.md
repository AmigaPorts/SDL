# 27 / Advanced Topics / Creating a Dual-Playfield Display


In dual-playfield mode, you have two separately controllable playfields.
You specify dual-playfield mode in 1.3 by setting the [DUALPF](../Libraries_Manual_guide/node0327.html#line14) bit in the
[ViewPort.Modes](../Libraries_Manual_guide/node0327.html) field.  In Release 2, you specify dual-playfield by using
any ModeID that includes DPF in its name as listed in <graphics/[displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html#line152)>.

In dual-playfield mode, you always define two [RasInfo](../Libraries_Manual_guide/node032B.html#line69) data structures.
Each of these structures defines one of the playfields. There are five
different ways you can configure a dual-playfield display, because there
are five different distributions of the bitplanes which the system
hardware allows.




        Table 27-6: Bitplane Assignment in Dual-playfield Mode


               Number of    Playfield 1    Playfield 2
               Bitplanes       Depth          Depth
               ---------       -----          -----
                   2             1              1
                   3             2              1
                   4             2              2
                   5             3              2
                   6             3              3
Under 1.3 if [PFBA](../Libraries_Manual_guide/node0327.html#line19) is set in the [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) field, or, under Release 2,
if the ModeID includes DPF2 in its name, then the playfield priorities are
swapped and playfield 2 will be displayed in front of playfield 1.  In
this way, you can get more bitplanes in the background playfield than you
have in the foreground playfield. The playfield priority affects only one
[ViewPort](../Libraries_Manual_guide/node032B.html#line59) at a time.  If you have multiple ViewPorts with dual-playfields,
the playfield priority is set for each one individually.

Here's a summary of the steps you need to take to create a dual-playfield
display:

  * Allocate one [View](../Libraries_Manual_guide/node032B.html#line51) structure and one [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure.

  * Allocate two [BitMap](../Libraries_Manual_guide/node032B.html#line74) structures.  Allocate two [RasInfo](../Libraries_Manual_guide/node032B.html#line69) structures

```c
    (linked together), each pointing to a separate BitMap. The two
    RasInfo structures are linked together as follows:

        struct RasInfo playfield1, playfield2;

        playfield1.Next = &playfield2;
        playfield2.Next = NULL;
```
  * Initialize each [BitMap](../Libraries_Manual_guide/node032B.html#line74) structure to describe one playfield, using one

    of the permissible bitplane distributions shown in the above table
    and allocate memory for the bitplanes themselves.  Note that BitMap 1
    and BitMap 2 need not be the same width and height.
  * Initialize the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) structure.  In 1.3, specify dual-playfield

```c
    mode by setting the [DUALPF](../Libraries_Manual_guide/node0327.html#line14) bit (and [PFBA](../Libraries_Manual_guide/node0327.html#line19), if appropriate) in the
    [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) field.  Under Release 2, specify dual-playfield mode
    by selecting a ModeID that includes DPF (or DPF2) in its name as
    listed in <graphics/[displayinfo.h](../Includes_and_Autodocs_2._guide/node00BD.html#line152)>.  Set the [ViewPort.RasInfo](../Includes_and_Autodocs_2._guide/node00B8.html#line40) field
    to the address of the playfield 1 [RasInfo](../Libraries_Manual_guide/node032B.html#line69).
```
  * Set up the [ColorMap](../Libraries_Manual_guide/node00F1.html#line4) information

  * Call [MakeVPort()](../Libraries_Manual_guide/node0332.html#line9), [MrgCop()](../Libraries_Manual_guide/node0332.html#line27) and [LoadView()](../Libraries_Manual_guide/node0333.html) to display the newly

```c
    created [ViewPort](../Libraries_Manual_guide/node032B.html#line59).
```
For display purposes, each of the two [BitMap](../Libraries_Manual_guide/node032B.html#line74)s is assigned to a separate
[ViewPort](../Libraries_Manual_guide/node032B.html#line59).  To draw separately into the BitMaps, you must also assign these
BitMaps to two separate [RastPort](../Libraries_Manual_guide/node034A.html)s.  The section called
"[Initializing a RastPort Structure](../Libraries_Manual_guide/node034C.html)" shows you how to use a RastPort data
structure to control your drawing routines.

