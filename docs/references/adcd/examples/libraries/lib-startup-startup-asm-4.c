/* Source: ADCD 2.1
 * Section: lib-startup-startup-asm
 * Library: libraries
 * ADCD reference: libraries/lib-startup-startup-asm.md
 */

                ;-- skip spaces
                move.b  (a2)+,d1
                beq.s   parmExit
                cmp.b   #' ',d1
                beq.s   newarg
                cmp.b   #9,d1           ; tab
                beq.s   newarg

                ;-- check for argument count overflow
                cmp.l   sv_MaxArgc(a5),d3
                beq.s   parmExit

                ;-- push address of the next parameter
                move.l  a1,(a3)+
                addq.w  #1,d3

                ;-- process quotes
                cmp.b   #'"',d1
                beq.s   doquote

                ;-- copy the parameter in
                move.b  d1,(a1)+
