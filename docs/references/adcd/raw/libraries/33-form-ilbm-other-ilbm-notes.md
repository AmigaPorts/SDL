# 33 / / FORM ILBM / Other ILBM Notes


Amiga [ILBM](../Libraries_Manual_guide/node045D.html#line8)s images must be stored as an even number of bytes in width.
However, the [ILBM BMHD](../Libraries_Manual_guide/node0461.html#line3) field w (width) should describe the actual image
width, not the rounded up width as stored.

[ILBM](../Libraries_Manual_guide/node045D.html#line8)s created with Electronic Arts IBM or Amiga Deluxe Paint II packages
are compatible (though you may have to use a `.lbm' filename extension on
an IBM).  The ILBM graphic files may be transferred between the machines
(or between the Amiga and IBM sides your Amiga if you have a CBM
Bridgeboard card installed) and loaded into either package.

