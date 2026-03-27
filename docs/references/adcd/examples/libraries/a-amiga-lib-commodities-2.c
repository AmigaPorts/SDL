/* Source: ADCD 2.1
 * Section: a-amiga-lib-commodities
 * Library: libraries
 * ADCD reference: libraries/a-amiga-lib-commodities.md
 */

    These functions look for a particular entry in a ToolType array
    returned by ArgArrayInit() and return the integer (ArgInt()) or
    string (ArgString()) associated with that entry.  A default value can
    be passed to each function which will be returned in the event that
    the requested entry could not be found in the ToolType array.
