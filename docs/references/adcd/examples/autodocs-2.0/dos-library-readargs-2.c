/* Source: ADCD 2.1
 * Section: dos-library-readargs
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/dos-library-readargs.md
 */

    In V36, there were a couple of minor bugs with certain argument
    combinations (/M/N returned strings, /T didn't work, and /K and
    /F interacted).  Also, a template with a /K before any non-switch
    parameter will require the argument name to be given in order for
    line to be accepted (i.e. "parm/K,xyzzy/A" would require
    "xyzzy=xxxxx" in order to work - "xxxxx" would not work).  If you
    need to avoid this for V36, put /K parameters after all non-switch
    parameters.  These problems should be fixed for V37.

    Currently (V37 and before) it requires any strings passed in to have
    newlines at the end of the string.  This may or may not be fixed in
    the future.
