/* Source: ADCD 2.1
 * Section: 28-using-bobs-using-bob-flags
 * Library: libraries
 * ADCD reference: libraries/28-using-bobs-using-bob-flags.md
 */

    When a Bob has been completely removed, the system sets the BOBNIX
    flag to 1 on return from [DrawGList()](../Libraries_Manual_guide/node038C.html).  In other words, when the
    background area has been fully restored and the Bob has been removed
    from the GEL list, this flag in is set to a 1.  BOBNIX is especially
    significant when double-buffering because when an application asks
    for a Bob to be removed, the system must remove it from both the
    drawing buffer and from the display buffer.  Once BOBNIX has been
    set, it means the Bob has been removed from both buffers and the
    application is free to reuse or deallocate the Bob.
