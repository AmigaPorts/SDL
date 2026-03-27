---
title: Appendix A. Reference / Example Diagrams
manual: devices
chapter: devices
section: appendix-a-reference-example-diagrams
functions: []
libraries: []
---

# Appendix A. Reference / Example Diagrams

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Here's a box diagram for an example IFF file, a raster image FORM [ILBM](devices/ilbm-iff-interleaved-bitmap-introduction.md).
This [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) contains a bitmap header property [chunk](devices/primitive-data-types-chunks.md) [BMHD](devices/standard-properties-bmhd.md), a color map
property chunk [CMAP](devices/standard-properties-cmap.md), and a raster data chunk [BODY](devices/standard-body-data-chunk-body.md).  This particular raster
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


This second diagram shows a [LIST](devices/a-quick-introduction-to-iff-advanced-topics.md) of two FORMs ILBM sharing a common [BMHD](devices/standard-properties-bmhd.md)
property and a common [CMAP](devices/standard-properties-cmap.md) property.  Again, the text on the right is an
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

