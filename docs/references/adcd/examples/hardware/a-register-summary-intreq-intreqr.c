/* Source: ADCD 2.1
 * Section: a-register-summary-intreq-intreqr
 * Library: hardware
 * ADCD reference: hardware/a-register-summary-intreq-intreqr.md
 */

                 This register contains interrupt request bits (or
                 flags).  These bits may be polled by the processor;
                 if enabled by the bits listed in the above register,
                 they may cause processor interrupts.  Both a set and
                 clear operation are required to load arbitrary data
                 into this register.  These status bits are not
                 automatically reset when the interrupt is serviced,
                 and must be reset when desired by writing to this
                 address.  The bit assignments are identical to the
                  [enable register](../Hardware_Manual_guide/node0036.html) .
