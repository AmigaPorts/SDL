# 27 / / Viewport Display Modes / Interlaced vs. Non-interlaced Mode


In interlaced mode, there are twice as many lines available as in
non-interlaced mode, providing better vertical resolution in the same
display area.


  -----------------------------------------
  -----------------------------------------
  ------------                -------------
  ----------- 200 lines define ------------  [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) = 0
  -----------  a full screen   ------------
  ------------                -------------
  -----------------------------------------
  -----------------------------------------


  =========================================
  =========================================
  ============                =============
  =========== 400 lines define ============  [ViewPort.Modes](../Libraries_Manual_guide/node0327.html) = LACE
  ===========  a full screen   ============
  ============                =============
  =========================================
  =========================================



            Figure 27-15: How LACE Affects Vertical Resolution
If the [View](../Libraries_Manual_guide/node032B.html#line51) structure does not specify [LACE](../Libraries_Manual_guide/node0327.html#line36), and the [ViewPort](../Libraries_Manual_guide/node032B.html#line59) specifies
LACE, only the top half of the ViewPort data will be displayed. If the
View structure specifies LACE and the ViewPort is non-interlaced, the same
ViewPort data will be repeated in both fields.  The height of the ViewPort
display is the height specified in the ViewPort structure. If both the
View and the ViewPort are interlaced, the ViewPort will be built with
double the normal vertical resolution.  That means it will need twice as
much data space in memory as a non-interlaced picture to fill the display.

