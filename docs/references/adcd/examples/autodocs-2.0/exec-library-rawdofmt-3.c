/* Source: ADCD 2.1
 * Section: exec-library-rawdofmt
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-rawdofmt.md
 */

    ;
    ; Simple version of the C "sprintf" function.  Assumes C-style
    ; stack-based function conventions.
    ;
    ;   long eyecount;
    ;   eyecount=2;
    ;   sprintf(string,"%s have %ld eyes.","Fish",eyecount);
    ;
    ; would produce "Fish have 2 eyes." in the string buffer.
    ;
            XDEF _sprintf
            XREF _AbsExecBase
            XREF _LVORawDoFmt
    _sprintf:       ; ( ostring, format, {values} )
            movem.l a2/a3/a6,-(sp)

            move.l  4*4(sp),a3       ;Get the output string pointer
            move.l  5*4(sp),a0       ;Get the FormatString pointer
            lea.l   6*4(sp),a1       ;Get the pointer to the DataStream
            lea.l   stuffChar(pc),a2
            move.l  _AbsExecBase,a6
            jsr     _LVORawDoFmt(a6)

            movem.l (sp)+,a2/a3/a6
            rts

    ;------ PutChProc function used by RawDoFmt -----------
    stuffChar:
            move.b  d0,(a3)+        ;Put data to output string
            rts
