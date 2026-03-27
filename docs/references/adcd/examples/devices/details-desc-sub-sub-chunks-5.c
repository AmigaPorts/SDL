/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    BYTE    SProps[5];      ; object properties

    This chunk contains object (surface) properties used by Turbo Silver.

    SProps[0] - PRP_SURFACE ; surface type
                            ;   0 - normal
                            ;   4 - genlock
                            ;   5 - IFF brush
    SProps[1] - PRP_BRUSH   ; brush number (if IFF mapped)
    SProps[2] - PRP_WRAP    ; IFF brush wrapping type
                            ;   0 - no wrapping
                            ;   1 - wrap X
                            ;   2 - wrap Z
                            ;   3 - wrap X and Z
    SProps[3] - PRP_STENCIL ; stencil number for stencil objects
    SProps[4] - PRP_TEXTURE ; texture number if texture mapped
