/* Source: ADCD 2.1
 * Section: listbrowser-gc-lbm-addnode
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/listbrowser-gc-lbm-addnode.md
 */

    NAME
        LBM_ADDNODE -- Adds a node to the attached list.

    FUNCTION
        Allocates a new node and adds it to the list currently attached to
        the listbrowser (if there is one attached).  If rendering
        information is available, then any necessary refreshing will take
        place.  You do not need to detach your list first.

        This method takes the following message structure:

          struct [lbAddNode](../Includes_and_Autodocs_3._guide/node05EF.html#line31)
          {
              ULONG MethodID;                 /* LBM_ADDNODE */
              struct [GadgetInfo](../Includes_and_Autodocs_3._guide/node060E.html#line24) *lba_GInfo;   /* to provide rendering info */
              struct [Node](../Includes_and_Autodocs_3._guide/node062F.html#line21) *lba_Node;          /* [Insert()](../Includes_and_Autodocs_3._guide/node0219.html) after this node */
              struct [TagItem](../Includes_and_Autodocs_3._guide/node064C.html#line31) *lba_NodeAttrs;  /* [AllocListBrowserNodeA()](../Includes_and_Autodocs_3._guide/node0444.html)
                                                 taglist */
          };

    RESULT
        Returns a pointer to the allocated node, or NULL on failure.

    SEE ALSO
        [LBM_EDITNODE](../Includes_and_Autodocs_3._guide/node0442.html), [LBM_REMNODE](../Includes_and_Autodocs_3._guide/node0443.html), reaction.lib/LBAddNode
