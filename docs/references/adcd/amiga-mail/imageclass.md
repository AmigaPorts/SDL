---
title: imageclass
manual: amiga-mail
chapter: amiga-mail
section: imageclass
functions: [EraseRect]
libraries: [graphics.library]
---

# imageclass

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Class:                  imageclass
Superclass:             rootclass
Description:            Base class for Intuition Images
Include File:           <intuition/imageclass.h>


New Methods:
------------

IM_DRAW - Draw the image in the RastPort passed in the message, at the
xoffset and in the state provided in the message.


IM_HITTEST - Return TRUE if the point passed is within the image.  This
base Image class returns TRUE if the point is within the old Image
structure box.


IM_ERASE - Erase an image.  This class will call the new graphics
library function EraseRect() for its Image box.  IM_ERASE does not test
the box dimensions  (>= 0).


IM_MOVE - Erase and redraw an image.  This is intended for subclasses
capable of performing animation or smooth dragging (e.g., prop gadget
knobs).  A no-op for imageclass.


IM_FRAMEBOX - A no-op for this base class, but implemented by image
subclasses which are "stretchable".  For example, frameiclass objects
put an embossed frame around a text label or glyph.  The message passed
to this method contains a pointer to a box describing the dimensions of
the contents to frame, and a pointer to a frame box for the result.
There is also a FrameFlags field which currentlly has only one defined
flag, FRAMEF_SPECIFY.

The idea behind this frame business is to support multiple gadgets (as
found in a system requester) which share a single frame image object,
but render it in different dimensions appropriate for their enclosed
label.  The operation of this method should be defined by suitable
subclasses as follows, and return non-zero to indicate that they support
this method.

If FRAMEF_SPECIFY is not set, you should set up the povided frame box
with the position and dimensions of the frame you would render to
enclose the contents box.  This is an inquiry function used, for
example, by a gadget which wants to know what sized frame dimensions to
pass to IM_DRAWFRAME (defined below) and how to center the contents.

The caller might then add a little aesthetic margin by increasing the
dimensions (or might decide to make a column of framed objects all the
same width as the largest one), and having done so, can call the method
IM_FRAMEBOX again, this time with FRAMEF_SPECIFY set.  Now, your method
is expected to respect the dimensions specified in the frame box (even
if you think they are too small!) and to set up only the position of the
frame box appropriately for enclosing the provided contents box.
Currently implemented frame image classes always center the contents,
but future classes might want to support an attribute for optional left
or right justification of the contents.


IM_DRAWFRAME - Image subclasses which assign proper meaning to this
class (i.e. frameiclass) should respect the dimensions that are passed
in this message by superceding this method.  If imageclass sees this
message, it will convert it to an IM_DRAW message and send it back to
the image's true class.  This way, any subclass of imageclass which
doesn't implement or recognize the IM_DRAWFRAME method will default to
drawing objects at their "natural" dimensions.


IM_HITFRAME - Perform a hit test for the image respecting the frame
dimensions passed in the message.  Useful for something like a
stretchable rounded box.  This class just performs the same as
IM_HITTEST, ignoring the dimensions passed.


IM_ERASEFRAME - Erase an image respecting the frame dimensions passed in
the message.  This class calls EraseRect() for the frame dimensions,
again not checking dimension validity.


Changed Methods:
----------------

OM_NEW - Instance data contains an Image structure, and its Depth field
is initialized to CUSTOMIMAGEDEPTH, which identifies such images to
Intuition.  The Width and Height fields are set to arbitrary positive
numbers for safety, but you should always set them to something
meaningful.


OM_SET - Applies all supported attributes, returns '1'.


Attributes:
-----------

IA_Left                         (ISG)
IA_Top                          (ISG)
IA_Width                        (ISG)
IA_Height                       (ISG)

These attributes are stored (by imageclass) as values in the familiar
Image structure.


IA_FGPen                        (ISG)
IA_BGPen                        (ISG)

These attributes are maintained in the PlanePick and PlaneOnOff fields,
which concept they generalize.


IA_Data                         (ISG)

A pointer to general image data.  This value is stored in the ImageData
field of the old Image structure.


IA_LineWidth                    ()

A no-op for imageclass.


IA_Pens                         ()

Defined but not supported by imageclass. Pointer to UWORD pens[],
terminated by ~0.  This can be used to the exclusion of DrawInfo
attributes or parameters, or as an override.

---

## See Also

- [EraseRect — graphics.library](../autodocs/graphics.library.md#eraserect)
