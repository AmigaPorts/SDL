/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

        ENDC    QARG

        IFGT    WBOUT

        ;------ Open NIL: or AppWindow for WB Input()/Output() handle
        ;       Also for possible initialization of stdio globals
        ;       Stdio used to be initialized to -1


        IFGT    WINDOW
        ;------ Get AppWindow defined in application
                lea     _AppWindow,a0
                cmp.b   #0,(a0)
                bne.s   doOpen          ; Open if not null string
        ENDC    WINDOW

        ;------ Open NIL: if no window provided
        lea     NilName(PC),a0
