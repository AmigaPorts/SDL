/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    UBYTE   Props[6];       ; more object properties

    This chunk contains object properties that programs other
    than Turbo Silver might support.

    Props[0] - PRP_BLEND    ; blending factor (0-255)
    Props[1] - PRP_SMOOTH   ; roughness factor
    Props[2] - PRP_SHADE    ; shading on/off flag
    Props[3] - PRP_PHONG    ; phong shading on/off flag
    Props[4] - PRP_GLOSSY   ; glossy on/off flag
    Props[5] - PRP_QUICK    ; Quickdraw on/off flag

    The blending factor controls the amount of dithering used
    on the object - 255 is fully dithered.  The roughness factor
    controls how rough the object should appear - 0 is smooth, 255
    is max roughness.  The shading flag is interpreted differently
    depending on whether the object is a light source or not.  For
    light sources, it sets the light to cast shadows or not.  For
    normal objects, if the flag is set, the object is always
    considered as fully lit - i.e., it's color is read directly
    from the object (or IFF brush), and is not affected by light
    sources.  The phong shading is on by default - a non-zero value
    turns it off.  The glossy flag sets the object to be glossy or
    not.  If the object is glossy, the "transmit" colors and the
    index of refraction control the amount of "sheen".  The glossy
    feature is meant to simulate something like a wax coating
    on the object with the specified index of refraction. The
    trasmission coefficients control how much light from the
    object makes it through the wax coating.
    The Quickdraw flag, if set, tells the editor not to draw
    all the points and edges for the object, but to draw a
    rectanglular solid centered at the object position, and
    with sizes detemined by the axis lengths.
