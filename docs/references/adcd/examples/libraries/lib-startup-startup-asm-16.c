/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        IFEQ    QARG
        ;------ deallocate the SVar structure
                move.l  a5,a1
                move.l  sv_Size(a5),d0
                callsys FreeMem
        ENDC    QARG

        ;------ this rts sends us back to DOS:
                move.l  d2,d0
                rts
