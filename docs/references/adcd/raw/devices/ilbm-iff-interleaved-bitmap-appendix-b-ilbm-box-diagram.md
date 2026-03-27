# ILBM IFF Interleaved Bitmap / Appendix B. ILBM Box Diagram


Here's a box diagram for a simple example: an uncompressed image 320 x 200
pixels x 3 bitplanes.  The text to the right of the diagram shows the
outline that would be printed by the Sift utility program for this
particular file.


	          +--------------------+
	          |                    |
	          |  'FORM'     24070  |  FORM 24070 ILBM
	          |                    |
	       -- +--------------------+
	       |  |                    |
	       |  |  'ILBM'            |
	       |  |                    |
	       |  | +----------------+ |
	       |  | |  'BMHD'    20  | |  .BMHD 20
	       |  | |----------------| |
	       |  | |  320, 200,     | |
	       |  | |  0 ....        | |
	       |  | +----------------+ |
	       |  |                    |
	       |  | +----------------+ |
	24070 <   | |  'CMAP'    21  | |  .CMAP 21
	 bytes |  | |----------------| |
	       |  | |  0, 0, 0,      | |
	       |  | |  255 ....      | |
	       |  | +----------------+ |
	       |  |   0                |
	       |  | +----------------+ |
	       |  | |  'BODY'  24000 | |  .BODY 24000
	       |  | |----------------| |
	       |  | |  0, 0, 0....   | |
	       |  | +----------------+ |
	       |  |                    |
	       -- +--------------------+

The "0" after the [CMAP](../Devices_Manual_guide/node01B0.html) chunk is a pad byte.

