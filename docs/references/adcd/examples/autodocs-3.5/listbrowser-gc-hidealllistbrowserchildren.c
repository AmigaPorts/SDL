/* Source: ADCD 2.1
 * Section: listbrowser-gc-hidealllistbrowserchildren
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-hidealllistbrowserchildren.md
 */

    NAME
        HideAllListBrowserChildren -- Hide all children in a ListBrowser.

    SYNOPSIS
        VOID HideAllListBrowserChildren(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);
        HideAllListBrowserChildren(list);

    FUNCTION
        Hides all children in a hierarchical ListBrowser, "collapsing" all
        generations so that only root generation nodes are shown.

        Note that as with any modifications to a ListBrowser list, the list
        MUST be detached to the listbrowser at the time of modification.

    INPUTS
        list - a list of ListBrowser nodes, not currently attached to a
            ListBrowser.
