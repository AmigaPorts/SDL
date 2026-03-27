/* Source: ADCD 2.1
 * Section: exec-library-setsr
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-setsr.md
 */

    To get the current SR:
        currentSR = SetSR(0,0);
    To change the processor interrupt level to 3:
        oldSR = SetSR($0300,$0700);
    Set processor interrupts back to prior level:
        SetSR(oldSR,$0700);
