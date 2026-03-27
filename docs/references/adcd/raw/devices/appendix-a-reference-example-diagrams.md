# Appendix A. Reference / Example Diagrams


Here's a box diagram for an example IFF file, a raster image FORM [ILBM](../Devices_Manual_guide/node01AC.html).
This [FORM](../Devices_Manual_guide/node01C7.html#line52) contains a bitmap header property [chunk](../Devices_Manual_guide/node01DD.html) [BMHD](../Devices_Manual_guide/node01AF.html), a color map
property chunk [CMAP](../Devices_Manual_guide/node01B0.html), and a raster data chunk [BODY](../Devices_Manual_guide/node01B7.html).  This particular raster
is 320 x 200 pixels x 3 bit planes uncompressed.  The "0" after the CMAP
chunk represents a zero pad byte; included since the CMAP chunk has an odd
length.  The text to the right of the diagram shows the outline that would
be printed by the IFFCheck utility program for this particular file.


	          +----------------------------+
	          |                            |
	          |  "FORM"            24070   |  FORM 24070 ILBM
	          |                            |
	       -  +----------------------------+
	       |  |                            |
	       |  |    "ILBM"                  |
	       |  |                            |
	       |  |  +----------------------+  |
	       |  |  |  "BMHD"         20   |  |  .BMHD 20
	       |  |  |----------------------|  |
	       |  |  |  320, 200, 0, 0, 3,  |  |
	       |  |  |  0, 0, 0, ....       |  |
	       |  |  +----------------------+  |
	       |  |                            |
	24070 <   |  +----------------------+  |
	 bytes |  |  |  "CMAP"         21   |  |  .CMAP 21
	       |  |  |----------------------|  |
	       |  |  |  0, 0, 0; 32, 0, 0;  |  |
	       |  |  |  64, 0, 0 ...        |  |
	       |  |  +----------------------+  |
	       |  |     0                      |
	       |  |  +----------------------+  |
	       |  |  |  "BODY"      24000   |  |
	       |  |  |----------------------|  |  .BODY 24000
	       |  |  |  0, 0, 0....         |  |
	       |  |  +----------------------+  |
	       |  |                            |
	       -- +----------------------------+


This second diagram shows a [LIST](../Devices_Manual_guide/node01CA.html#line49) of two FORMs ILBM sharing a common [BMHD](../Devices_Manual_guide/node01AF.html)
property and a common [CMAP](../Devices_Manual_guide/node01B0.html) property.  Again, the text on the right is an
outline á la IFFCheck.


	        +------------------------------+
	        | "LIST"              48114    |
	        +------------------------------+
	        |                              |
	        |   "ILBM"                     |
	        |                              |
	        |  +------------------------+  |
	        |  |  "PROP"        62      |  | .PROP 62 ILBM
	        |  +------------------------+  |
	        |  |                        |  |
	        |  |  "ILBM"                |  |
	        |  | +--------------------+ |  |
	        |  | |  "BMHD"       20   | |  | ..BMHD 20
	        |  | |--------------------| |  |
	        |  | |  320, 200, 0, 0, 3,| |  |
	        |  | |  0, 0, 0, ....     | |  |
	        |  | +--------------------+ |  |
	        |  |                        |  |
	        |  | +--------------------+ |  |
	        |  | |  "CMAP"       21   | |  | ..CMAP 21
	        |  | |--------------------| |  |
	        |  | |  0, 0, 0; 32, 0, 0;| |  |
	        |  | |  64, 0, 0 ....     | |  |
	        |  | +--------------------+ |  |
	        |  |   0                    |  |
	        |  +------------------------+  |
	        |                              |
	        |                              |
	        |  +------------------------+  |
	        |  |  "FORM"        24012   |  | .FORM 24012 ILBM
	        |  +------------------------+  |
	        |  |                        |  |
	        |  |  "ILBM"                |  |
	        |  | +--------------------+ |  |
	        |  | |  "BODY"    24000   | |  | ..BODY 24000
	        |  | |--------------------| |  |
	        |  | |  0, 0, 0....       | |  |
	        |  | +--------------------+ |  |
	        |  +------------------------+  |
	        |                              |
	        |                              |
	        |  +------------------------+  |
	        |  |  "FORM"        24012   |  | .FORM 24012 ILBM
	        |  +------------------------+  |
	        |  |                        |  |
	        |  |  "ILBM"                |  |
	        |  | +--------------------+ |  |
	        |  | |  "BODY"    24000   | |  | ..BODY 24000
	        |  | |--------------------| |  |
	        |  | |  0, 0, 0....       | |  |
	        |  | +--------------------+ |  |
	        |  +------------------------+  |
	        |                              |
	        |                              |
	        +------------------------------+

