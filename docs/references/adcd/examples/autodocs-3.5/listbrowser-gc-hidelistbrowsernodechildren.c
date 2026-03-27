/* Source: ADCD 2.1
 * Section: listbrowser-gc-hidelistbrowsernodechildren
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-hidelistbrowsernodechildren.md
 */

    NAME
        HideListBrowserNodeChildren -- Hide a ListBrowser node's children

    SYNOPSIS
        VOID HideListBrowserNodeChildren(struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *);
        HideListBrowserNodeChildren(node);

    FUNCTION
        Hides the children of a ListBrowser node.  It will only hide the
        next generation, nodes of higher generations will not be modified.

        Note that as with any modifications to a ListBrowser list, the list
        must NOT be detached to the listbrowser at the time of modification.

    INPUTS
        node - the node whose children you will be hiding.  The node must
            NOT be in a list that that is currently attached to a ListBrowser.
