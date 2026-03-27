/* Source: ADCD 2.1
 * Section: details-desc-sub-sub-chunks
 * Library: devices
 * ADCD reference: devices/details-desc-sub-sub-chunks.md
 */

    This chunk contains texture data when texture mapping is used.

    UWORD   Flags;          ; texture flags:
                            ;    1 - TXTR_CHILDREN - apply to child objs
    TFORM   TForm;          ; local coordinates of texture axes.
    FRACT   Params[16];     ; texture parameters
    UBYTE   PFlags[16];     ; parameter flags (currently unused)
    UBYTE   Length;         ; length of texture file name
    UBYTE   Name[Length];   ; texture file name (not NULL terminated)
    UBYTE   pad;            ; (if necessary to make an even length)
