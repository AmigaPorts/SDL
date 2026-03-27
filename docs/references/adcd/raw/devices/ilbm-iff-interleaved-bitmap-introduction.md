# ILBM IFF Interleaved Bitmap / Introduction


[EA IFF 85](../Devices_Manual_guide/node01C5.html) is Electronic Arts' standard for interchange format files.
"ILBM" is a format for a 2 dimensional raster graphics image, specifically
an InterLeaved bitplane BitMap image with color map.  An ILBM is an IFF
"data section" or "[FORM](../Devices_Manual_guide/node01C7.html#line51) type", which can be an IFF file or a part of one.
ILBM allows simple, highly portable raster graphic storage.

An ILBM is an archival representation designed for three uses.  First, a
stand- alone image that specifies exactly how to display itself
(resolution, size, color map, etc.).  Second, an image intended to be
merged into a bigger picture which has its own depth, color map, and so
on.  And third, an empty image with a color map selection or "palette" for
a paint program.  ILBM is also intended as a building block for composite
IFF [FORM](../Devices_Manual_guide/node01C7.html#line51)s like "animation sequences" and "structured graphics".  Some uses
of ILBM will be to preserve as much information as possible across
disparate environments.  Other uses will be to store data for a single
program or highly cooperative programs while maintaining subtle details.
So we're trying to accomplish a lot with this one format.

This memo is the IFF supplement for FORM ILBM.  Section 2 defines the
purpose and format of property chunks bitmap header "[BMHD](../Devices_Manual_guide/node01AF.html)", color map
"[CMAP](../Devices_Manual_guide/node01B0.html)", hotspot "[GRAB](../Devices_Manual_guide/node01B1.html)", destination merge data "[DEST](../Devices_Manual_guide/node01B2.html)", sprite information
"[SPRT](../Devices_Manual_guide/node01B3.html)", and Commodore Amiga viewport mode "[CAMG](../Devices_Manual_guide/node01B4.html)".  Section 3 defines the
standard data [chunk](../Devices_Manual_guide/node01DD.html) "[BODY](../Devices_Manual_guide/node01B7.html)".  These are the "standard" [chunk](../Devices_Manual_guide/node01DD.html)s.  Section 4
defines the non- standard data chunks.  Additional specialized chunks like
texture pattern can be added later.  The ILBM syntax is summarized in
[Appendix A](../Devices_Manual_guide/node01BB.html) as a regular expression and in [Appendix B](../Devices_Manual_guide/node01BC.html) as a box diagram.
[Appendix C](../Devices_Manual_guide/node01BD.html) explains the optional run encoding scheme.  [Appendix D](../Devices_Manual_guide/node01C0.html) names
the committee responsible for this FORM ILBM standard.

Details of the raster layout are given in part 3, [Standard Data Chunk](../Devices_Manual_guide/node01B6.html).
Some elements are based on the Commodore Amiga hardware but generalized
for use on other computers.  An alternative to ILBM would be appropriate
for computers with true color data in each pixel, though the wealth of
available ILBM images makes import and export important.

 [Reference](../Devices_Manual_guide/node01AD.html) 

