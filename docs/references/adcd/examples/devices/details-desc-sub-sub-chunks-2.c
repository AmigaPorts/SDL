/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    UWORD   TCount;         ; face count
    UWORD   Connects[][3];  ; faces

    This chunk contains the triangle (face) list for custom objects.
    The Connects[][3] array is triples of edge numbers that are
    connected by triangles.
