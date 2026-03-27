/* Source: ADCD 2.1
 * Section: 15-resources-cia-resource
 * Library: devices
 * ADCD reference: devices/15-resources-cia-resource.md
 */

                           CIA Resource Functions
                           ----------------------
     [AbleICR()](../Includes_and_Autodocs_2._guide/node0536.html)             Enable or disable Interrupt Control
                           Register interrupts.  Can also return the
                           current or previous enabled interrupt mask.

     [AddICRVector()](../Includes_and_Autodocs_2._guide/node0537.html)        Allocate one of the CIA timers by assigning
                           an interrupt handler to an interrupt bit
                           and enabling the interrupt of one of the
                           timers. If the timer you request is not
                           available, a pointer to the interrupt
                           structure that owns it will be returned.

     [RemICRVector()](../Includes_and_Autodocs_2._guide/node0538.html)        Remove an interrupt handler from an
                           interrupt bit and disable the interrupt.

     [SetICR()](../Includes_and_Autodocs_2._guide/node0539.html)              Cause or clear one or more interrupts, or
                           return the current or previous interrupt
                           status.
