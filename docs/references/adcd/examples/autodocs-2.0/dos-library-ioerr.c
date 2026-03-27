/* Source: ADCD 2.1
 * Section: dos-library-ioerr
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-ioerr.md
 */

    Most I/O routines return zero to indicate an error. When this
    happens (or whatever the defined error return for the routine)
    this routine may be called to determine more information. It is
    also used in some routines to pass back a secondary result.

    Note: there is no guarantee as to the value returned from IoErr()
    after a successful operation, unless to specified by the routine.
