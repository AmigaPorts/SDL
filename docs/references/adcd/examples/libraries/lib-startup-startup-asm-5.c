/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

                ;------ null termination check
                move.b  (a2)+,d1
                beq.s   parmExit
                cmp.b   #' ',d1
                beq.s   endarg

                move.b  d1,(a1)+
                bra.s   nextchar
