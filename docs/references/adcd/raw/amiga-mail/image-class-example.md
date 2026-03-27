# Image Class Example


The image class example code, [mytextlabelclass.c](../AmigaMail_Vol2_guide/node01AF.html), illustrates a complete
custom image class.  This image class provides an application with textual
labels that have a particular character underlined.  This is useful for
indicating which key controls a gadget (although the example provided only
utilizes imageclass objects; there are no gadgets involved).

A custom image can be used in the place of any standard Intuition Image
structure.  For example, an application can attach an imageclass object
to: the GadgetRender and SelectRender fields of a Gadget structure
(defined in <intuition/intuition.h>), the ReqImage field of a Requester
structure, or even the ItemFill field of the MenuItem structure.

Under Intuition V36, the DrawImage() function passed an invalid DrawInfo
structure, therefore it wasn't possible to use a custom imageclass object
and the DrawImage() together.  With V37, a NULL DrawInfo is passed when no
valid DrawInfo is available.

The example code ([usemyIC.c](../AmigaMail_Vol2_guide/node01B0.html)) initializes and uses a custom imageclass
object.  Notice that usemyIC.c directly manipulates fields within the
Image structure embedded within the boopsi imageclass object.  This is
legal for image classes whose immediate superclass is imageclass (for the
LeftEdge, TopEdge, Width, Height, ImageData, PlanePick, and PlaneOnOff
Image structure fields only; the other Image structure fields are off
limits).  Indirect subclasses of imageclass may not alter the values in
the embedded Image structure as future direct subclasses of imageclass may
need to know about changes to values in the Image structure.

