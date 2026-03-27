/* Source: ADCD 2.1
 * Section: 2-advanced-topics-a-copper-loop-example
 * Library: hardware
 * ADCD reference: hardware/2-advanced-topics-a-copper-loop-example.md
 */

        DC.W    $8F01,$8F00   ; Wait for VP=1xxx1111
        DC.W    [INTREQ](../Hardware_Manual_guide/node0164.html#line11),$8010  ; Set the copper interrupt bit...

        DC.W    $80E3,$80FE   ; Wait for Horizontal $E2
                              ; This is so the line gets finished before
                              ; we check if we are there  (The wait above)

        DC.W    $FF01,$FE01   ; Skip if VP>=255
        DC.W    [COPJMP2](../Hardware_Manual_guide/node0051.html),$0    ; Force a jump to  [COP2LC](../Hardware_Manual_guide/node0050.html) 
