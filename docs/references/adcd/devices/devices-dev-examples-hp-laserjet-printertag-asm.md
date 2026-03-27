---
title: Devices/Dev_examples/HP_Laserjet_printertag.asm
manual: devices
chapter: devices
section: devices-dev-examples-hp-laserjet-printertag-asm
functions: [OpenLibrary]
libraries: [exec.library]
---

# Devices/Dev_examples/HP_Laserjet_printertag.asm

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

        INCLUDE         "hp_rev.i"

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
        XREF            _ConvFunc
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
                DC.B    PPC_BWGFX       ; PrinterClass
                DC.B    PCC_BW          ; ColorClass
                DC.B    0               ; MaxColumns
                DC.B    0               ; NumCharSets
                DC.W    1               ; NumRows
                DC.L    600             ; MaxXDots
                DC.L    795             ; MaxYDots
                DC.W    75              ; XDotsInch
                DC.W    75              ; YDotsInch
                DC.L    _CommandTable   ; Commands
                DC.L    _DoSpecial
                DC.L    _Render
                DC.L    30              ; Timeout
                DC.L    _ExtendedCharTable      ; 8BitChars
                DS.L    1               ; PrintMode (reserve space)
                DC.L    _ConvFunc       ; ptr to char conversion function
```
printerName:

                dc.b    'HP_LaserJet',0

                END

---

## See Also

- [OpenLibrary — exec.library](../autodocs/exec.library.md#openlibrary)
