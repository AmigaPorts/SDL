/* Source: ADCD 2.1
 * Section: listbrowser-gc-lbm-editnode
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-lbm-editnode.md
 */

    NAME
        LBM_EDITNODE -- Edit an attached nodes attributes.

    FUNCTION
        Changes attributes of a node attached to a listbrowser.  If rendering
        information is available, then any necessary refreshing will take
        place.  You do not need to detach your list first.

        This method takes the following message structure:

          struct [lbEditNode](../Includes_and_Autodocs_3._guide/node05EF.html#line59)
          {
              ULONG MethodID;                 /* LBM_EDITNODE */
              struct [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) *lbe_GInfo;   /* to provide rendering info */
              struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *lbe_Node;          /* modify this node */
              struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *lbe_NodeAttrs;  /* [SetListBrowserNodeAttrsA()](../Includes_and_Autodocs_3._guide/node044B.html)
                                                 taglist */
          };

    RESULT
        Returns non-zero on success, zero on failure.

    SEE ALSO
        [LBM_ADDNODE](../Includes_and_Autodocs_3._guide/node0441.html), [LBM_REMNODE](../Includes_and_Autodocs_3._guide/node0443.html), reaction.lib/LBEditNode
