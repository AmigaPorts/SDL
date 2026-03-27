# 4 / Window Types / GimmeZeroZero Window Type


GimmeZeroZero windows provide a window border layer separate from the main
(inner) window layer.  This allows the application to freely render into
the window without worrying about the window border and its contents.

System gadgets and the window title are placed in the border layer.
Application gadgets go into the inner window by default, but may be placed
in the border.  To position application gadgets in the border layer, the
[GTYP_GZZGADGET](../Libraries_Manual_guide/node0149.html#line81) flag and the appropriate [Gadget](../Libraries_Manual_guide/node0149.html) border flag must be set in
the [Activation](../Libraries_Manual_guide/node0149.html#line53) field of the Gadget.

The top left coordinates of the inner window are always (0,0), regardless
of the size or contents of the border, thus the name "GimmeZeroZero."  The
application need not take the border size into account when rendering.
The inner window always begins at (0,0) and extends to
(GZZWidth,GZZHeight).  The GZZWidth and GZZHeight variables are available
in the [Window](../Libraries_Manual_guide/node0102.html#line8) structure.

The [GZZMouseX and GZZMouseY](../Libraries_Manual_guide/node0121.html#line48) variables provide the position of the mouse
relative to the inner window.  Note that the mouse positions in
[IDCMP_MOUSEMOVE](../Libraries_Manual_guide/node01DC.html#line23) events are always relative to the total window, even for
GimmeZeroZero windows.

Requesters in a GimmeZeroZero window are also positioned relative to the
inner window.  See the chapter entitled "[Intuition Requesters and Alerts](../Libraries_Manual_guide/node01A6.html),"
for more information about requester location.

To specify a GimmeZeroZero window, set the WFLG_GIMMEZEROZERO flag or the
[WA_GimmeZeroZero](../Libraries_Manual_guide/node0125.html#line81) tag in the [OpenWindowTagList()](../Libraries_Manual_guide/node0103.html) call.


```c
    WARNING!
    --------
    The GimmeZeroZero window uses more system resources than other window
    types because the window creates a separate layer for the border
    display.  Using multiple GimmeZeroZero windows will quickly degrade
    performance in the positioning and sizing of windows.

    Applications should consider using regions as an alternative to
    GimmeZeroZero windows.  See the "[Layers Library](../Libraries_Manual_guide/node03F8.html)" chapter,
    especially the [InstallClipRegion()](../Libraries_Manual_guide/node03FA.html) function, for information on
    setting up regions to limit graphics display in the window.
```
