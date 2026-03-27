/* Source: ADCD 2.1
 * Section: d-troubleshooting-guide-general-debugging-techniques
 * Library: libraries
 * ADCD reference: libraries/d-troubleshooting-guide-general-debugging-techniques.md
 */

    Use methodical testing procedures, and debugging messages if
    necessary, to locate the problem area.  Low level code can be
    debugged using [KPrintF()](../Includes_and_Autodocs_2._guide/node0178.html) serial (or dprintf() parallel) messages.
    Check the initial values, allocation, use, and freeing of all
    pointers and structures used in the problem area.  Check that all of
    your system and internal function calls pass correct initialized
    arguments, and that all possible error returns are checked for and
    handled.
