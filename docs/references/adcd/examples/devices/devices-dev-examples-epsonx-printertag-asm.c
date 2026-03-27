/* Source: ADCD 2.1
 * Section: devices-dev-examples-epsonx-printertag-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-epsonx-printertag-asm.md
 */

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
