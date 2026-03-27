/* Source: ADCD 2.1
 * Section: lib-examples-asmsupp-i
 * Library: libraries
 * ADCD reference: libraries/lib-examples-asmsupp-i.md
 */

                IFGE    INFO_LEVEL-\1

                PEA     subSysName(PC)
                MOVEM.L A0/A1/D0/D1,-(SP)
                LEA     msg\@(pc),A0    ;Point to static format string
                LEA     4*4(SP),A1      ;Point to args
                JSR     KPutFmt
                MOVEM.L (SP)+,D0/D1/A0/A1
                ADDQ.L  #4,SP
                BRA.S   end\@
