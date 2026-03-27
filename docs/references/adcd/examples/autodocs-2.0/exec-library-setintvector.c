/* Source: ADCD 2.1
 * Section: exec-library-setintvector
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/exec-library-setintvector.md
 */

    This function provides a mechanism for setting the system interrupt
    vectors.  These are non-sharable; setting a new interrupt handler
    disconnects the old one.  Installed handlers are responsible for
    processing, enabling and clearing the interrupt.  Note that interrupts
    may have been left in any state by the previous code.

    The IS_CODE and IS_DATA pointers of the [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure will
    be copied into a private place by Exec.  A pointer to the previously
    installed [Interrupt](../Includes_and_Autodocs_2._guide/node008C.html#line23) structure is returned.

    When the system calls the specified interrupt code, the registers are
    setup as follows:

        D0 - scratch
        D1 - scratch (on entry: active
                      interrupts -> equals INTENA & INTREQ)

        A0 - scratch (on entry: pointer to base of custom chips
                      for fast indexing)
        A1 - scratch (on entry: Interrupt's IS_DATA pointer)

        A5 - jump vector register (scratch on call)
        A6 - Exec library base pointer (scratch on call)

        all other registers must be preserved
