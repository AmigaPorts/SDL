/* Source: ADCD 2.1
 * Section: details-info-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-info-sub-chunks.md
 */

    BYTE    Props[8];       ; an array of 8 "global properties" used
                            ; by Turbo Silver.

    Props[0] - GLB_EDGING       ; edge level (globals requester)
    Props[1] - GLB_PERTURB      ; perturbance (globals requester)
    Props[2] - GLB_SKY_BLEND    ; sky blending factor (0-255)
    Props[3] - GLB_LENS         ; lens type (see below)
    Props[4] - GLB_FADE         ; flag - Sharp/Fuzzy focus (globals)
    Props[5] - GLB_SIZE         ; "apparant size" (see below)
    Props[6] - GLB_RESOLVE      ; resolve depth (globals requester)
    Props[7] - GLB_EXTRA        ; flag - genlock sky on/off

    The edging and perturbance values control the heuristics in ray
    tracing.  The sky blending factor is zero for no blending, and 255
    for full blending.  The lens type is a number from 0-4, corresponding
    to the boxes in the "camera" requester, and correspond to 0) Manual,
    1) Wide angle, 2) Normal, 3) Telephoto, and 4) Custom.  It is used
    in setting the camera's focal length if the camera is tracked to an
    object.  The Sharp/Fuzzy flag turns the "fade" feature on and off -
    non-zero means on.  The "apparant size" parameter is 100 times the
    "custom size" parameter in the camera requester.  And is used to set
    the focal length for a custom lens.  The "resolve depth" controls
    the number of rays the ray tracer will shoot for a single pixel.
    Each reflective/refractive ray increments the depth counter, and
    the count is never allowed to reach the "resolve depth".  If both
    a reflective and a refractive ray are traced, each ray gets its
    own version of the count - so theoretically, a resolve depth of
    4 could allow much more than 4 rays to be traced.  The "genlock
    sky" flag controls whether the sky will be colored, or set to
    the genlock color (color 0 - black) in the final picture.
