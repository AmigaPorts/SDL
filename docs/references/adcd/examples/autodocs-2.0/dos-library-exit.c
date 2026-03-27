/* Source: ADCD 2.1
 * Section: dos-library-exit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-exit.md
 */

    Exit() is currently for use with programs written as if they
    were BCPL programs.  This function is not normally useful for
    other purposes.

    In general, therefore, please DO NOT CALL THIS FUNCTION!

    In order to exit, C programs should use the C language exit()
    function (note the lower case letter "e").  Assembly programs should
    place a return code in D0, and execute an RTS instruction with
    their original stack ptr.
