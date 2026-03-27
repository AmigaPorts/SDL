/* Source: ADCD 2.1
 * Section: lib-examples-suits8-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-suits8-asm.md
 */

    DC.L  $00000000B  ; fontData. Each pair of words specifies how the
    DC.L  $0000B000B  ; characters are bit-packed.  For example, the first
    DC.L  $000160007  ; character starts at bit position 0x0000, and is
    DC.L  $0001D000B  ; 0x000B (11) bits wide.  The second character starts
    DC.L  $00028000C  ; at bit position 0x000B and is 0x000B bits wide, and
                      ; so on.  This tellsthe font handler how to unpack
                      ; the bits from the array.
