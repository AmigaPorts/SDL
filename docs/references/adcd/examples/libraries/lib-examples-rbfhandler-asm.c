/* Source: ADCD 2.1
 * Section: lib-examples-rbfhandler-asm
 * Library: libraries
 * ADCD reference: libraries/lib-examples-rbfhandler-asm.md
 */

        MOVE.W  serdatr(A0),D1          ;get the input word (flags and char)

        MOVE.W  rd_buffercount(A1),D0   ;get our buffer index
        CMPI.W  #BUFLEN,D0              ;no more room in our buffer ?
        BEQ.S   ExitHandler             ;yes - just exit (ignore new char)
        LEA.L   rd_charbuffer(A1),A5    ;else get our character buffer address
        MOVE.B  D1,0(A5,D0.W)           ;store character in our character buffer
        LEA.L   rd_flagbuffer(A1),A5    ;get our flag buffer address
        LSR.W   #8,d1                   ;shift flags down
        MOVE.B  D1,0(A5,D0.W)           ;store flags in flagbuffer

        ADDQ.W  #1,D0                   ;increment our buffer index
        MOVE.W  D0,rd_buffercount(A1)   ;   and replace it
        CMPI.W  #BUFLEN,D0              ;did our buffer just become full ?
        BNE.S   ExitHandler             ;no - we can exit
        MOVE.L  A0,-(SP)                ;yes - save custom
        MOVE.L  rd_signal(A1),D0        ;get signal allocated in main()
        MOVE.L  rd_task(A1),A1          ;and pointer to main task
        JSRLIB  Signal                  ;tell main we are full
        MOVE.L  (SP)+,A0                ;restore custom
                                        ;Note: system call trashed D0-D1/A0-A1
