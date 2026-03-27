/* Source: ADCD 2.1
 * Section: a-register-summary-bltxdat
 * Library: hardware
 * ADCD reference: hardware/a-register-summary-bltxdat.md
 */

                 This register holds source x (x=A,B,C) data for
                 use by the blitter. It is normally loaded by the
                 blitter DMA channel; however, it may also be
                 preloaded by the microprocessor.

                 LINE DRAW   BLTADAT is used as an index register
                 LINE DRAW   and must be preloaded with 8000.
                 LINE DRAW   BLTBDAT is used for texture; it must
                 LINE DRAW   be preloaded with FF if no texture
                 LINE DRAW   (solid line) is desired.
