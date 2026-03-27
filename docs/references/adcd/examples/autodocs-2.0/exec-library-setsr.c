/* Source: ADCD 2.1
 * Section: exec-library-setsr
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-setsr.md
 */

    This function provides a means of modifying the CPU status register
    in a "safe" way (well, how safe can a function like this be
    anyway?).  This function will only affect the status register bits
    specified in the mask parameter.  The prior content of the entire
    status register is returned.
