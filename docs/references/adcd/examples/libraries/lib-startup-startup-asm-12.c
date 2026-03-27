/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ;------ a6 = ExecBase
                lea     pr_MsgPort(A4),a0       ; our process base
                callsys WaitPort
                lea     pr_MsgPort(A4),a0       ; our process base
                callsys GetMsg
                rts
