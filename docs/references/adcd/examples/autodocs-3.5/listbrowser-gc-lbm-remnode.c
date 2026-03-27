/* Source: ADCD 2.1
 * Section: listbrowser-gc-lbm-remnode
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-lbm-remnode.md
 */

    NAME
        LBM_REMNODE -- Removes a node from the attached list.

    FUNCTION
        Removes and de-allocates a node from the list currently attached
        to the listbrowser.  If rendering information is available, then
        any necessary refreshing will take place.  You do not need to
        detach your list first.

        This method takes the following message structure:

          struct [lbRemNode](../Includes_and_Autodocs_3._guide/node05EF.html#line46)
          {
              ULONG MethodID;               /* LBM_REMNODE */
              struct [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) *lbr_GInfo; /* to provide rendering info */
              struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *lbr_Node;        /* [Remove()](../Includes_and_Autodocs_3._guide/node022F.html) this node */
          };

    RESULT
        Returns non-zero on success, zero on failure.

    SEE ALSO
        [LBM_ADDNODE](../Includes_and_Autodocs_3._guide/node0441.html), LBM_REMNODE, [reaction.lib/LBRemNode](../Includes_and_Autodocs_3._guide/node052E.html)
