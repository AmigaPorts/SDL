/* Source: ADCD 2.1
 * Section: intuition-library-openscreen
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-openscreen.md
 */

    By default, AmigaDOS requesters related to your process are put on
    the Workbench screen (these are messages like "Disk Full").  If
    you wish them to show up on custom screens, DOS must be told.
    This fragment shows the procedure.  More information is available
    in the AmigaDOS manuals.  Sample code fragment:

    #include "libraries/dosextens.h"
            ...
    struct [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) *process;
    struct [Window](../Includes_and_Autodocs_2._guide/node00D4.html#line797)   *window;
    APTR            temp;
            ...
            process = (struct [Process](../Includes_and_Autodocs_2._guide/node0078.html#line38) *) FindTask(NULL);
            temp = process->pr_WindowPtr;   (save old value)
            process->pr_WindowPtr = (APTR) window;
            ( use a pointer to any open window on your screen )
                    ...
            your code goes here
                    ...
            process->pr_WindowPtr = temp;
            ( restore value BEFORE [CloseWindow()](../Includes_and_Autodocs_2._guide/node0208.html) )
            CloseWindow(window);
