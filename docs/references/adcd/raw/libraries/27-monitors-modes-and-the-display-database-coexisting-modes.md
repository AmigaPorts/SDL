# 27 / / Monitors, Modes and the Display Database / Coexisting Modes


Each display mode specifies (among other things) a pixel resolution and a
monitor scan rate.  Though the Amiga has the unique ability to change
pixel resolutions on the fly, it is not possible to change the speed of a
monitor beam in mid-frame. Therefore, if you set up a display of two or
more [ViewPort](../Libraries_Manual_guide/node032B.html#line59)s in different display modes requiring different scan rates,
at least one of the ViewPorts will be displayed with the wrong scan rate.

Such [ViewPort](../Libraries_Manual_guide/node032B.html#line59)s can be coerced into a different mode designed for the scan
rate currently in effect.  You can do this in a couple of ways,
introducing or removing interlace to adjust the vertical dimension, and
changing to faster or slower pixels (higher or lower resolution) for the
horizontal dimension.

The disadvantage of introducing interlace is flicker.  The disadvantage of
increasing resolution is the lessening of the video bus bandwidth and
possibly a reduction in the number of colors or palette resolution.

Under Intuition, the frontmost screen determines which of the conflicting
modes will take precedence.  With the graphics library, the Modes field of
the [View](../Libraries_Manual_guide/node032B.html#line51) and its frontmost [ViewPort](../Libraries_Manual_guide/node032B.html#line59) or, in Release 2, the [MonitorSpec](../Includes_and_Autodocs_2._guide/node00A7.html#line26) of
the [ViewExtra](../Libraries_Manual_guide/node032C.html#line16) determine the scan rate.  For some monitors (such as the
A2024), simultaneous display is excluded.  This is a requirement only
because the A2024 modes require very special and intricate display Copper
list management.

