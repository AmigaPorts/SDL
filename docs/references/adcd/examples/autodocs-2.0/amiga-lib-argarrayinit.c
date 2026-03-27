/* Source: ADCD 2.1
 * Section: amiga-lib-argarrayinit
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/amiga-lib-argarrayinit.md
 */

    This function returns a null-terminated array of strings
    suitable for sending to [icon.library/FindToolType()](../Includes_and_Autodocs_2._guide/node0186.html). This array will
    be the ToolTypes array of the program's icon, if it was started from
    Workbench. It will just be 'argv' if the program was started from
    a shell.

    Pass ArgArrayInit() your startup arguments received by main().

    ArgArrayInit() requires that icon.library be open (even if the caller
    was started from a shell, so that the function [FindToolType()](../Includes_and_Autodocs_2._guide/node0186.html) can be
    used) and may call [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html), so clean up is necessary when
    the strings are no longer needed. The function [ArgArrayDone()](../Includes_and_Autodocs_2._guide/node013C.html) does
    just that.
