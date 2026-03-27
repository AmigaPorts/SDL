/* Source: ADCD 2.1
 * Section: a-amiga-lib-commodities
 * Library: libraries
 * ADCD reference: libraries/a-amiga-lib-commodities.md
 */

    ArgArrayInit() returns an array of strings suitable for sending to
    icon.library/[FindToolType()](../Includes_and_Autodocs_2._guide/node0186.html). This array will be the ToolTypes array
    of the program's icon, if it was started from Workbench. It will just
    be 'argv' if the program was started from a shell. ArgArrayDone()
    frees memory and does cleanup required after a call to ArgArrayInit().
