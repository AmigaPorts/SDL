/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    UBYTE   Type;           ; refraction type (0-4)
    UBYTE   Index;          ; custom index of refraction

    This chunk contains refraction data for transparent or glossy
    objects.  If the refraction type is 4, the object has a "custom"
    refractive index stored in the Index field.  The Index field is
    100 * (true index of refraction - 1.00) -- so it must be in the
    range of 1.00 to 3.55.  The refraction types 0-3 specify 0) Air
    - 1.00, 1) Water - 1.33, 2) Glass - 1.67 or 3) Crystal 2.00.
