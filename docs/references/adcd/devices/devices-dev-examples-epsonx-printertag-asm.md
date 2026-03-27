---
title: Devices/Dev_examples/Epsonx_printertag.asm
manual: devices
chapter: devices
section: devices-dev-examples-epsonx-printertag-asm
functions: [OpenLibrary]
libraries: [exec.library]
---

# Devices/Dev_examples/Epsonx_printertag.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

**********************************************************************
*
*       printer device dependent code tag
*
**********************************************************************


        SECTION         printer
*------ Included Files -----------------------------------------------


        INCLUDE         "exec/types.i"
        INCLUDE         "exec/nodes.i"
        INCLUDE         "exec/strings.i"

        INCLUDE         "epsonX_rev.i"

        INCLUDE         "devices/prtbase.i"
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
                MOVEQ   #0,D0           ; show error for OpenLibrary()
                RTS
                DC.W    VERSION
                DC.W    REVISION
```
_PEDData:

```c
                DC.L    printerName
                DC.L    _Init
                DC.L    _Expunge
                DC.L    _Open
                DC.L    _Close
                DC.B    PPC_COLORGFX    ;PrinterClass
                DC.B    PCC_YMCB        ; ColorClass
                DC.B    136             ; MaxColumns
                DC.B    10              ; NumCharSets
                DC.W    8               ; NumRows
                DC.L    1632            ; MaxXDots
                DC.L    0               ; MaxYDots
                DC.W    120             ; XDotsInch
                DC.W    72              ; YDotsInch
                DC.L    _CommandTable   ; Commands
                DC.L    _DoSpecial
                DC.L    _Render
                DC.L    30              ; Timeout
                DC.L    _ExtendedCharTable      ; 8BitChars
                DS.L    1               ; PrintMode (reserve space)
                DC.L    0               ; ptr to char conversion function
```
printerName:

                dc.b    'EpsonX',0

                END

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
