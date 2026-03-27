/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ Open up the file whose name is in a0
        ;       DOSBase still in a6
                move.l  a0,d1
                move.l  #MODE_OLDFILE,d2
                callsys Open
        ;------ d0 now contains handle for Workbench Output
        ;------ save handle for closing on exit
                move.l  d0,sv_WbOutput(a5)
                bne.s   gotOpen
                moveq.l #RETURN_FAIL,d2
                bra     exit2
