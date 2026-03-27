---
title: listbrowser_gc/FreeListBrowserNode
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-freelistbrowsernode
functions: []
libraries: []
---

# listbrowser_gc/FreeListBrowserNode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        FreeListBrowserNode -- Free a ListBrowser node.

    SYNOPSIS
        VOID FreeListBrowserNode(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *)
        FreeListBrowserNode(node)

    FUNCTION
        Frees a ListBrowser node allocated with [AllocListBrowserNodeA()](autodocs-3.5/listbrowser-gc-alloclistbrowsernodea.md).

    INPUTS
        node - The node to free.

    SEE ALSO
        [AllocListBrowserNodeA()](autodocs-3.5/listbrowser-gc-alloclistbrowsernodea.md)
```
