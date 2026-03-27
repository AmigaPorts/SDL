/* Source: ADCD 2.1
 * Section: intuition-library-closeworkbench
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/intuition-library-closeworkbench.md
 */

    The name of this function is improperly spelled.  It ought
    to have been CloseWorkbench().

    It might be more convenient to have it return TRUE if the
    Workbench wasn't opened when called.  The idea as it is now
    is probably this: if you want to free up the memory of the
    Workbench screen when your program begins, you can call
    CloseWorkBench().  The return value of that call indicates
    whether you should call [OpenWorkBench()](../Includes_and_Autodocs_2._guide/node023B.html) when your program
    exits: if FALSE, that means either the the Workbench existed
    but you could not close it, or that it wasn't around to
    begin with, and you should not try to re-open it.

    We would prefer that you provide a user selection to attempt
    to open or close the Workbench screen from within your application,
    rather than your making assumptions like these.
