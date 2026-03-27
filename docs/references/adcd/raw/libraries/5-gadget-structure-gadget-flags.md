# 5 / Gadget Structure / Gadget Flags


The following are the flags that can be set in the [Flags](../Libraries_Manual_guide/node0149.html#line48) variable of the
[Gadget](../Libraries_Manual_guide/node0149.html) structure.  There are four highlighting methods to choose from.
These determine how the gadget imagery will be changed when the gadget is
selected.  One of these four flags must be set.

GFLG_GADGHNONE

    Set this flag for no highlighting.
GFLG_GADGHCOMP

    This flag chooses highlighting by complementing all of the bits
    contained within the gadget's select box.
GFLG_GADGHBOX

    This flag chooses highlighting by drawing a complemented box around
    the gadget's select box.
GFLG_GADGHIMAGE


    Set this flag to indicate highlighting with an alternate image.
In addition to the highlighting flags, these other values may be set in
the [Flags](../Libraries_Manual_guide/node0149.html#line48) field of the [Gadget](../Libraries_Manual_guide/node0149.html) structure.

GFLG_GADGIMAGE

```c
    If the gadget has a graphic, and it is implemented with an [Image](../Libraries_Manual_guide/node01BA.html)
    structure, set this bit.  If the graphic is implemented with a [Border](../Libraries_Manual_guide/node01C1.html)
    structure, make sure this bit is clear.  This bit is also used by
    [SelectRender](../Libraries_Manual_guide/node0149.html#line102) to determine the rendering type.
```
GFLG_RELBOTTOM

```c
    Set this flag if the gadget's [TopEdge](../Libraries_Manual_guide/node0149.html#line33) variable describes an offset
    relative to the bottom of the display element (window or requester)
    containing it.  A GFLG_RELBOTTOM gadget moves automatically as its
    window is made taller or shorter.  Clear this flag if TopEdge is
    relative to the top of the display element.  If GFLG_RELBOTTOM is
    set, TopEdge should contain a negative value, which will position it
    up from the bottom of the display element.
```
GFLG_RELRIGHT

```c
    Set this flag if the gadget's [LeftEdge](../Libraries_Manual_guide/node0149.html#line33) variable describes an offset
    relative to the right edge of the display element containing it.  A
    GFLG_RELRIGHT gadget moves automatically as its window is made wider
    or narrower.  Clear this flag if LeftEdge is relative to the left
    edge of the display element.  If GFLG_RELRIGHT is set, LeftEdge
    should contain a negative value, which will position the gadget left
    of the right edge of the display element.
```
GFLG_RELWIDTH

```c
    Set this flag for "relative gadget width."  If this flag is set, the
    width of the gadget's select box changes automatically whenever the
    width of its window changes.  When using GFLG_RELWIDTH, set the
    gadget's [Width](../Libraries_Manual_guide/node0149.html#line33) to a negative value.  This value will be added to the
    width of the gadget's display element (window or requester) to
    determine the actual width of the gadget's select box.
```
GFLG_RELHEIGHT

```c
    Set this flag for "relative gadget height."  If this flag is set, the
    height of the gadget's select box changes automatically whenever the
    height of its window changes.  When using GFLG_RELHEIGHT, set the
    gadget's [Height](../Libraries_Manual_guide/node0149.html#line33) to a negative value.  This value will be added to the
    height of the gadget's display element (window or requester) to
    determine the actual height of the gadget's select box.
```
GFLG_SELECTED

```c
    Use this flag to preset the on/off selected state for a toggle-select
    [boolean](../Libraries_Manual_guide/node014C.html) gadget (see the discussion of the [GACT_TOGGLESELCT](../Libraries_Manual_guide/node014B.html#line2) flag
    below).  If the flag is set, the gadget is initially selected and is
    highlighted.  If the flag is clear, the gadget starts off in the
    unselected state.  To change the selection state of one or more
    gadgets, change their GFLG_SELECTED bits as appropriate, add them
    back and refresh them.  However, see the section on
    "[Updating a Gadget's Imagery](../Libraries_Manual_guide/node0145.html)" for important details.
```
GFLG_DISABLED

```c
    If this flag is set, this gadget is disabled. To enable or disable a
    gadget after the gadget has been added to the system, call the
    routines [OnGadget()](../Libraries_Manual_guide/node0147.html#line10) and [OffGadget()](../Libraries_Manual_guide/node0147.html#line10).  The GFLG_DISABLED flag can be
    programmatically altered in much the same way as GFLG_SELECTED above.
    See the section on "[Updating a Gadget's Imagery](../Libraries_Manual_guide/node0145.html)" for important
    details.
```
GFLG_STRINGEXTEND

```c
    The [StringInfo](../Libraries_Manual_guide/node016B.html) [Extension](../Libraries_Manual_guide/node016B.html#line76) field points to a valid [StringExtend](../Libraries_Manual_guide/node016D.html)
    structure.  Use of this structure is described later in the
    "[String Gadget Type](../Libraries_Manual_guide/node016B.html)" section of this chapter.  This flag is ignored
    prior to V37, see [GACT_STRINGEXTEND](../Libraries_Manual_guide/node014B.html#line108) for the same functionality under
    V36.  Note that GACT_STRINGEXTEND is not ignored prior to V36 and
    should only be set in V36 or later systems.
```
GFLG_TABCYCLE

```c
    This string participates in cycling activation with the tab (or
    shifted tab) key.  If this flag is set, the tab keys will de-activate
    this gadget as if the Return or Enter keys had been pressed, sending
    an [IDCMP_GADGETUP](../Libraries_Manual_guide/node01DD.html#line6) message to the application, then the next [string](../Libraries_Manual_guide/node0164.html)
    gadget with GFLG_TABCYCLE set will be activated.  Shifted tab
    activates the previous gadget.
```
