/* Source: ADCD 2.1
 * Section: listbrowser-gc-showlistbrowsernodechildren
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-showlistbrowsernodechildren.md
 */

    NAME
        ShowListBrowserNodeChildren -- Show children of a ListBrowser node.

    SYNOPSIS
        VOID ShowListBrowserNodeChildren(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *, WORD);
        ShowListBrowserNodeChildren(node, depth);

    FUNCTION
        Show the children of a ListBrowser node.  The next depth generations
        will be shown.  To only show the next generation, use a depth of 1.

        Note that as with any modifications to a ListBrowser list, the list
        must NOT be attached to the listbrowser at the time of modification.

    INPUTS
        node - the node whose children you will be showing.  The node must
            NOT be in a list that that is currently attached to a ListBrowser.
        depth - how many generations deep to show.
