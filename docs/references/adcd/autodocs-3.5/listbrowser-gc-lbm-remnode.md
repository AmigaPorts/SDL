---
title: listbrowser_gc/LBM_REMNODE
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-lbm-remnode
functions: [Remove]
libraries: [exec.library]
---

# listbrowser_gc/LBM_REMNODE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        LBM_REMNODE -- Removes a node from the attached list.

    FUNCTION
        Removes and de-allocates a node from the list currently attached
        to the listbrowser.  If rendering information is available, then
        any necessary refreshing will take place.  You do not need to
        detach your list first.

        This method takes the following message structure:

          struct [lbRemNode](autodocs-3.5/include-gadgets-listbrowser-h.md)
          {
              ULONG MethodID;               /* LBM_REMNODE */
              struct [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) *lbr_GInfo; /* to provide rendering info */
              struct [Node](autodocs-3.5/include-exec-nodes-h.md) *lbr_Node;        /* [Remove()](autodocs-3.5/exec-library-remove-2.md) this node */
          };

    RESULT
        Returns non-zero on success, zero on failure.

    SEE ALSO
        [LBM_ADDNODE](autodocs-3.5/listbrowser-gc-lbm-addnode.md), LBM_REMNODE, [reaction.lib/LBRemNode](autodocs-3.5/reaction-lib-lbremnode.md)
```

---

## See Also

- [Remove — exec.library](../autodocs/exec.library.md#remove)
