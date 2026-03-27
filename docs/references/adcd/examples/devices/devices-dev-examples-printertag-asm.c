/* Source: ADCD 2.1
 * Section: devices-dev-examples-printertag-asm
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-printertag-asm.md
 */

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
