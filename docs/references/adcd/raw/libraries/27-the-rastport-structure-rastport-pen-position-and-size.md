# 27 / / The RastPort Structure / RastPort Pen Position and Size


The graphics drawing routines keep the current position of the drawing pen
in the [RastPort](../Libraries_Manual_guide/node034A.html) fields [cp_x](../Libraries_Manual_guide/node034A.html#line23) and [cp_y](../Libraries_Manual_guide/node034A.html#line23), for the horizontal and vertical
positions, respectively. The coordinate location 0,0 is in the upper left
corner of the drawing area.  The x value increases proceeding to the
right; the y value increases proceeding toward the bottom of the drawing
area.

The variables [RastPort.PenWidth](../Libraries_Manual_guide/node034A.html#line25) and [RastPort.PenHeight](../Libraries_Manual_guide/node034A.html#line25) are not currently
implemented.  These fields should not be read or written by applications.

