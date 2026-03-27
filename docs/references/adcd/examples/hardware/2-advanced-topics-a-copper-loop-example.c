/* Source: ADCD 2.1
 * Section: 2-advanced-topics-a-copper-loop-example
 * Library: hardware
 * ADCD reference: hardware/2-advanced-topics-a-copper-loop-example.md
 */

        DC.W    $0F01,$8F00   ; Wait for VP=0xxx1111
        DC.W    [INTREQ](../Hardware_Manual_guide/node0164.html#line11),$8010  ; Set the copper interrupt bit...

        DC.W    $00E3,$80FE   ; Wait for Horizontal $E2
                              ; This is so the line gets finished before
                              ; we check if we are there  (The wait above)

        DC.W    $7F01,$7F01   ; Skip if VP>=127
        DC.W    [COPJMP1](../Hardware_Manual_guide/node0051.html),$0    ; Force a jump to  [COP1LC](../Hardware_Manual_guide/node0050.html) 
