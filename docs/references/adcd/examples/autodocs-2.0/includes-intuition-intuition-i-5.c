/* Source: ADCD 2.1
 * Section: includes-intuition-intuition-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-intuition-intuition-i.md
 */

    WORD ig_LeftEdge		; starting offset relative to something
    WORD ig_TopEdge		; starting offset relative to something
    WORD ig_Width		; pixel size (though data is word-aligned)
    WORD ig_Height		; pixel size
    WORD ig_Depth		; pixel size
    APTR ig_ImageData		; pointer to the actual image bits

    ; the PlanePick and PlaneOnOff variables work much the same way as the
    ; equivalent GELS Bob variables.  It's a space-saving
    ; mechanism for image data.  Rather than defining the image data
    ; for every plane of the RastPort, you need define data only for planes
    ; that are not entirely zero or one.  As you define your Imagery, you will
    ; often find that most of the planes ARE just as color selectors.  For
    ; instance, if you're designing a two-color Gadget to use colors two and
    ; three, and the Gadget will reside in a five-plane display, plane zero
    ; of your imagery would be all ones, bit plane one would have data that
    ; describes the imagery, and bit planes two through four would be
    ; all zeroes.  Using these flags allows you to avoid wasting all that
    ; memory in this way:
    ; first, you specify which planes you want your data to appear
    ; in using the PlanePick variable.	For each bit set in the variable, the
    ; next "plane" of your image data is blitted to the display.  For each bit
    ; clear in this variable, the corresponding bit in PlaneOnOff is examined.
    ; If that bit is clear, a "plane" of zeroes will be used.  If the bit is
    ; set, ones will go out instead.  So, for our example:
    ;	Gadget.PlanePick = 0x02;
    ;	Gadget.PlaneOnOff = 0x01;
    ; Note that this also allows for generic Gadgets, like the System Gadgets,
    ; which will work in any number of bit planes
    ; Note also that if you want an Image that is only a filled rectangle,
    ; you can get this by setting PlanePick to zero (pick no planes of data)
    ; and set PlaneOnOff to describe the pen color of the rectangle.
    ;
    ; NOTE:  Intuition relies on PlanePick to know how many planes
    ; of data are found in ImageData.  There should be no more
    ; '1'-bits in PlanePick than there are planes in ImageData.
    BYTE ig_PlanePick
    BYTE ig_PlaneOnOff

    ; if the NextImage variable is not NULL, Intuition presumes that
    ; it points to another Image structure with another Image to be
    ; rendered
    APTR ig_NextImage


    LABEL ig_SIZEOF
