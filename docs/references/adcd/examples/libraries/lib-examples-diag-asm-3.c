/* Source: ADCD 2.1
 * Section: lib-examples-diag-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-diag-asm.md
 */

            ; routine in ROM so that it can be called at Resident
            ; initialization time.
            ; This routine will be similar to a normal expansion device
            ; initialization routine, but will MakeDosNode then set up a
            ; BootNode, and Enqueue() on eb_MountList.
            ;
            rts

            ; Rest of your position-independent device code goes here.

            END
