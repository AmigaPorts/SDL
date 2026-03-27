/* Source: ADCD 2.1
 * Section: 27-performing-data-move-operations-accessing-blitter
 * Library: libraries
 * ADCD reference: libraries/27-performing-data-move-operations-accessing-blitter.md
 */

    The address of a routine that is to be called after your last return
    from the [QBlit()](../Includes_and_Autodocs_2._guide/node0468.html) routine.  When you finally return a zero, the queuer
    will call this subroutine (ends in RTS or return()) as the clean-up.
    Your first entry to the function may have dynamically allocated some
    memory or may have done something that must be undone to make for a
    clean exit.  This routine must be specified.
