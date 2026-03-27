/* Source: ADCD 2.1
 * Section: includes-devices-prtbase-i
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-devices-prtbase-i.md
 */

    STRUCT  pd_Unit,MP_SIZE   ; the one and only unit
    BPTR pd_PrinterSegment    ; the printer specific segment
    UWORD   pd_PrinterType    ; the segment printer type
    APTR pd_SegmentData       ; the segment data structure
    APTR pd_PrintBuf	      ; the raster print buffer
    APTR pd_PWrite	      ; the parallel write function
    APTR pd_PBothReady	      ; the parallel write function's done

    IFGT IOEXTPar_SIZE-IOEXTSER_SIZE
    STRUCT  pd_IOR0,IOEXTPar_SIZE   ; port I/O request 0
    STRUCT  pd_IOR1,IOEXTPar_SIZE   ;   and 1 for double buffering
    ENDC

    IFLE IOEXTPar_SIZE-IOEXTSER_SIZE
    STRUCT  pd_IOR0,IOEXTSER_SIZE   ; port I/O request 0
    STRUCT  pd_IOR1,IOEXTSER_SIZE   ;   and 1 for double buffering
    ENDC

    STRUCT  pd_TIOR,IOTV_SIZE       ; timer I/O request
    STRUCT  pd_IORPort,MP_SIZE      ;   and message reply port
    STRUCT  pd_TC,TC_SIZE           ; write task
    STRUCT  pd_OldStk,P_OLDSTKSIZE  ;   and stack space (OBSOLETE)
    UBYTE   pd_Flags                ; device flags
    UBYTE   pd_pad		    ; padding
    STRUCT  pd_Preferences,pf_SIZEOF ; the latest preferences
    UBYTE   pd_PWaitEnabled         ; wait function switch
