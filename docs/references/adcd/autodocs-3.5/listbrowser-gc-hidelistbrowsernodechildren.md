---
title: listbrowser_gc/HideListBrowserNodeChildren
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-hidelistbrowsernodechildren
functions: []
libraries: []
---

# listbrowser_gc/HideListBrowserNodeChildren

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        HideListBrowserNodeChildren -- Hide a ListBrowser node's children

    SYNOPSIS
        VOID HideListBrowserNodeChildren(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *);
        HideListBrowserNodeChildren(node);

    FUNCTION
        Hides the children of a ListBrowser node.  It will only hide the
        next generation, nodes of higher generations will not be modified.

        Note that as with any modifications to a ListBrowser list, the list
        must NOT be detached to the listbrowser at the time of modification.

    INPUTS
        node - the node whose children you will be hiding.  The node must
            NOT be in a list that that is currently attached to a ListBrowser.
```
