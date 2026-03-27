---
title: frameiclass
manual: amiga-mail
chapter: amiga-mail
section: frameiclass
functions: []
libraries: []
---

# frameiclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  frameiclass
Superclass:             imageclass
Description:            A raised, sunken, or chisled image class
                        supporting frame dimensions and Intuition new
                        look parameters.
Include File:           <intuition/imageclass.h>


New Methods:
------------

None, but implements some of the no-ops in imageclass.


Changed Methods:
----------------

OM_GET - A no-op for this class.


IM_DRAW - Draws the embossed frame in its natural (Image) dimensions.
Frame thickness support of IA_LineWidth is currently not implemented.
Frame type is determined by attributes below, colors determined by
DrawInfo and supports these drawing states:


        IDS_NORMAL, IDS_INACTIVENORMAL, IDS_DISABLED:
Renders edges in shadowPen, shinePen, and backgroundPen for the
interior.  NOTE: No ghosting is done for IDS_DISABLED.


        IDS_SELECTED, IDS_INACTIVESELECTED:
Renders edges in shadowPen, shinePen, and hifillPen, for the interior.


IM_DRAWFRAME - Same as IM_DRAW, but draws frame to specified exterior
dimensions.


IM_FRAMEBOX - Centers contents, adds dimension for frame thickness, plus
an interior margin of the same thickness.


Attributes:
-----------

IA_Recessed                     (IS)

Specifies that the frame should be recessed into the drawing surface
(shadowPen used on upper and left edges).  Default is FALSE, a raised
frame.


IA_DoubleEmboss                 (IS)

Two nested embossed frames for "chisled" boxes or "ridges".  Not
currently supported.


IA_EdgesOnly                    (IS)

Does not fill frame, just draws the edges.


IA_LineWidth                    ()

Not currently supported.

