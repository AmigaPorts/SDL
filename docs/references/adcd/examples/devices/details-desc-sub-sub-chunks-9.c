/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    UBYTE   IProps[8];       ; more object properties

    This chunk contains object properties that programs other
    than Imagine might support.

    IProps[0] - IPRP_DITHER   ; blending factor (0-255)
    IProps[1] - IPRP_HARD     ; hardness factor (0-255)
    IProps[2] - IPRP_ROUGH    ; roughness factor (0-255)
    IProps[3] - IPRP_SHINY    ; shinyness factor (0-255)
    IProps[4] - IPRP_INDEX    ; index of refraction
    IProps[5] - IPRP_QUICK    ; flag - Quickdraw on/off
    IProps[6] - IPRP_PHONG    ; flag - Phong shading on/off
    IProps[7] - IPRP_GENLOCK  ; flag - Genlock on/off

    The blending factor controls the amount of dithering used
    on the object - 255 is fully dithered.
    The hardness factor controls how tight the specular spot
    should be - 0 is a big soft spot, 255 is a tight hot spot
    The roughness factor controls how rough the object should
    appear - 0 is smooth, 255 is max roughness.
    The shiny factor in interaction with the object's filter
    values controls how shiny the object appears.  Setting it
    to anything but zero forces the object to be non-transparent
    since then the filter values are used in the shiny (reflection)
    calculations.  A value of 255 means maximum shinyness.
