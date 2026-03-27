---
title: Devices/Dev_examples/printertag.asm
manual: devices
chapter: devices
section: devices-dev-examples-printertag-asm
functions: []
libraries: []
---

# Devices/Dev_examples/printertag.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**********************************************************************
*
*       printer device dependent code tag
*
*
*
**********************************************************************


        SECTION         printer
*------ Included Files -----------------------------------------------



```c
        INCLUDE         "exec/types.i"
        INCLUDE         "exec/nodes.i"
        INCLUDE         "exec/strings.i"

        INCLUDE         "epsonX_rev.i"  ; contains VERSION & REVISION

        INCLUDE         "devices/prtbase.i"
```
*------ Imported Names -----------------------------------------------


        XREF            _Init
        XREF            _Expunge
        XREF            _Open
        XREF            _Close
        XREF            _CommandTable
        XREF            _PrinterSegmentData
        XREF            _DoSpecial
        XREF            _Render
        XREF            _ExtendedCharTable
*------ Exported Names -----------------------------------------------


        XDEF            _PEDData
**********************************************************************
```c
        ; in case anyone tries to execute this
        MOVEQ   #0,D0
        RTS

        DC.W    VERSION        ; must be at least 35 (V1.3 and up)
        DC.W    REVISION       ; your own revision number
```
_PEDData:

```c
        DC.L    printerName    ; pointer to the printer name
        DC.L    _Init          ; pointer to the initialization code
        DC.L    _Expunge       ; pointer to the expunge code
        DC.L    _Open          ; pointer to the open code
        DC.L    _Close         ; pointer to the close code
        DC.B    PPC_COLORGFX   ; PrinterClass
        DC.B    PCC_YMCB       ; ColorClass
        DC.B    136            ; MaxColumns
        DC.B    10             ; NumCharSets
        DC.W    8              ; NumRows
        DC.L    1632           ; MaxXDots
        DC.L    0              ; MaxYDots
        DC.W    120            ; XDotsInch
        DC.W    72             ; YDotsInch
        DC.L    _CommandTable  ; pointer to Command strings
        DC.L    _DoSpecial     ; pointer to Command Code function
        DC.L    _Render        ; pointer to Graphics Render function
        DC.L    30             ; Timeout

        DC.L    _ExtendedCharTable  ; pointer to 8BitChar table

        DS.L    1              ; Flag for PrintMode (reserve space)
        DC.L    0              ; pointer to ConvFunc (char conversion function)
```
printerName:

        DC.B    'EpsonX'
        DC.B    0
        END
