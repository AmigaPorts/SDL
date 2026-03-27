---
title: listbrowser_gc/LBM_EDITNODE
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-lbm-editnode
functions: []
libraries: []
---

# listbrowser_gc/LBM_EDITNODE

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        LBM_EDITNODE -- Edit an attached nodes attributes.

    FUNCTION
        Changes attributes of a node attached to a listbrowser.  If rendering
        information is available, then any necessary refreshing will take
        place.  You do not need to detach your list first.

        This method takes the following message structure:

          struct [lbEditNode](autodocs-3.5/include-gadgets-listbrowser-h.md)
          {
              ULONG MethodID;                 /* LBM_EDITNODE */
              struct [GadgetInfo](autodocs-3.5/include-intuition-cghooks-h.md) *lbe_GInfo;   /* to provide rendering info */
              struct [Node](autodocs-3.5/include-exec-nodes-h.md) *lbe_Node;          /* modify this node */
              struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *lbe_NodeAttrs;  /* [SetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-setlistbrowsernodeattrsa.md)
                                                 taglist */
          };

    RESULT
        Returns non-zero on success, zero on failure.

    SEE ALSO
        [LBM_ADDNODE](autodocs-3.5/listbrowser-gc-lbm-addnode.md), [LBM_REMNODE](autodocs-3.5/listbrowser-gc-lbm-remnode.md), reaction.lib/LBEditNode
```
