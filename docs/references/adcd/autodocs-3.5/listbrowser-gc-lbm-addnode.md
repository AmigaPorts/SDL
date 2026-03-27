---
title: listbrowser_gc/LBM_ADDNODE
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-lbm-addnode
functions: [Insert]
libraries: [exec.library]
---

# listbrowser_gc/LBM_ADDNODE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        LBM_ADDNODE -- Adds a node to the attached list.

    FUNCTION
        Allocates a new node and adds it to the list currently attached to
        the listbrowser (if there is one attached).  If rendering
        information is available, then any necessary refreshing will take
        place.  You do not need to detach your list first.

        This method takes the following message structure:

          struct [lbAddNode](autodocs-3.5/include-gadgets-listbrowser-h.md)
          {
              ULONG MethodID;                 /* LBM_ADDNODE */
              struct [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) *lba_GInfo;   /* to provide rendering info */
              struct [Node](autodocs-3.5/include-exec-nodes-h.md) *lba_Node;          /* [Insert()](autodocs-3.5/exec-library-insert-2.md) after this node */
              struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *lba_NodeAttrs;  /* [AllocListBrowserNodeA()](autodocs-3.5/listbrowser-gc-alloclistbrowsernodea.md)
                                                 taglist */
          };

    RESULT
        Returns a pointer to the allocated node, or NULL on failure.

    SEE ALSO
        [LBM_EDITNODE](autodocs-3.5/listbrowser-gc-lbm-editnode.md), [LBM_REMNODE](autodocs-3.5/listbrowser-gc-lbm-remnode.md), reaction.lib/LBAddNode
```

---

## See Also

- [Insert — exec.library](../autodocs/exec.library.md#insert)
