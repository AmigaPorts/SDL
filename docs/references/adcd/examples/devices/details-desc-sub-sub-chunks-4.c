/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    UWORD   Flags;          ; brush type:
                            ;    0 - Color
                            ;    1 - Reflection
                            ;    2 - Filter
                            ;    3 - Altitude
    UWORD   WFlags;         ; brush wrapping flags:
                            ;    1   WRAP_X        - wrap type
                            ;    2   WRAP_Z        - wrap type
                            ;    4   WRAP_CHILDREN - apply to children
                            ;    8   WRAP_REPEAT   - repeating brush
                            ;    16  WRAP_FLIP     - flip with repeats
    TFORM   TForm;          ; local coordinates of brush axes.
    (UWORD   FullScale;)    ; full scale value
    (UWORD   MaxSeq;)       ; highest number for sequenced brushes
    UBYTE   Length;         ; length of brush file name
    UBYTE   Name[Length];   ; brush file name (not NULL terminated)
    UBYTE   pad;            ; (if necessary to make an even length)

    The FullScale and MaxSeq items are in BRS2 chunks only.
