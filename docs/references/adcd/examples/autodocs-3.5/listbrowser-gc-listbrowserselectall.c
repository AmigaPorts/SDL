/* Source: ADCD 2.1
 * Section: listbrowser-gc-listbrowserselectall
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-listbrowserselectall.md
 */

    NAME
        ListBrowserSelectAll -- Select all nodes in a multiselect ListBrowser.

    SYNOPSIS
        VOID ListBrowserSelectAll(struct [List](../Includes_and_Autodocs_3._guide/node0628.html#line19) *);
        ListBrowserSelectAll(list);

    FUNCTION
        Sets the LBNA_Selected bit to TRUE in all nodes in list.  This is a
        quick way to select all nodes in a multi-select ListBrowser.

        Note that as with any modifications to a ListBrowser list, the list
        MUST be detached to the listbrowser at the time of modification.

    INPUTS
        list - a list of ListBrowser nodes, not currently attached to a
            ListBrowser.
