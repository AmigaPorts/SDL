/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ do recoverable alert for no DOS and exit
                ALERT   (AG_OpenLib!AO_DOSLib)

        ;------ do recoverable alert for no memory and exit
        ;------ If we got this far, DOS is open, so close it
        IFEQ QARG
                bra.s   failExit
