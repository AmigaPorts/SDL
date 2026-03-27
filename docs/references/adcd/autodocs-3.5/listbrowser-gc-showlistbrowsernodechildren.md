---
title: listbrowser_gc/ShowListBrowserNodeChildren
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-showlistbrowsernodechildren
functions: []
libraries: []
---

# listbrowser_gc/ShowListBrowserNodeChildren

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        ShowListBrowserNodeChildren -- Show children of a ListBrowser node.

    SYNOPSIS
        VOID ShowListBrowserNodeChildren(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, WORD);
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
```
