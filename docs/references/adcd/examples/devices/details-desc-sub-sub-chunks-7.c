/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    UBYTE   Specularity;    ; range of 0-255
    UBYTE   Hardness;       ; specular exponent (0-31)

    This chunk contains specular information.  The Specularity
    field is the amount of specular reflection -- 0 is none,
    255 is fully specular.  The "specular exponent" controls
    the "tightness" of the specular spots.  A value of zero
    gives broad specular spots and a value of 31 gives smaller
    spots.
