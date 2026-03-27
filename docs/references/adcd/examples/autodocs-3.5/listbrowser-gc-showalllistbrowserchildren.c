/* Source: ADCD 2.1
 * Section: listbrowser-gc-showalllistbrowserchildren
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-showalllistbrowserchildren.md
 */

    NAME
        ShowAllListBrowserChildren -- Show all children in a ListBrowser

    SYNOPSIS
        VOID ShowAllListBrowserChildren(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);
        ShowAllListBrowserChildren(list);

    FUNCTION
        Shows all children in a hierarchical ListBrowser, no matter what
        generation they are in.

        Note that as with any modifications to a ListBrowser list, the list
        must NOT be attached to the listbrowser at the time of modification.

    INPUTS
        list - a list of ListBrowser nodes, not currently attached to a
            ListBrowser.
