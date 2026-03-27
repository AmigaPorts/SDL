/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ENDC    QARG
        IFGT    QARG
                clr.l   -(sp)
        ENDC    QARG

                clr.l   -(sp)           ; reserve space for WBenchMsg if any

        ;------ branch to Workbench startup code if not a CLI process
                move.l  pr_CLI(A4),d0
                beq     fromWorkbench
