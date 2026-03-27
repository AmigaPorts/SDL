/* Source: ADCD 2.1
 * Section: devices-dev-examples-hp-laserjet-printertag-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-hp-laserjet-printertag-asm.md
 */

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
