/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ return the startup message to our parent
        ;       a6 = ExecBase (passed)
        ;       a2 = WBenchMsg (passed)
        ;       we forbid so workbench can't UnLoadSeg() us before we are done
                callsys Forbid
                move.l  a2,a1
                callsys ReplyMsg
                rts
