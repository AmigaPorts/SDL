---
title: listbrowser_gc/AllocListBrowserNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-alloclistbrowsernodea
functions: []
libraries: []
---

# listbrowser_gc/AllocListBrowserNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        AllocListBrowserNodeA -- [Allocate](autodocs-3.5/exec-library-allocate-2.md) a ListBrowser node.

    SYNOPSIS
        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocListBrowserNode(UWORD, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        node = AllocListBrowserNode(columns, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)

        struct [Node](autodocs-3.5/include-exec-nodes-h.md) * AllocListBrowserNodeA(UWORD, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        node = AllocListBrowserNodeA(columns, taglist)

    FUNCTION
        Allocates a node that can be added to the Exec linked list of
        labels in the listbrowser.  This is the only way to allocate a
        node for this list, you cannot allocate nodes yourself because
        the ListBrowser class uses a private node structure.

    TAGS
        See [SetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-setlistbrowsernodeattrsa.md) for the list of supported tags.  In
        addition, AllocListBrowserNodeA() supports the following additional
        tags:

        LBNA_NodeSize (ULONG) (V41)
        The size in bytes of the public portion of the node structure that
        should be allocated.  Usually the default (sizeof(struct Node)) will
        suffice, unless you wish to have a custom node structure embedded
        within the ListBrowser node, in which case you'd provide the size
        of that structure.  Then the node returned can be treated as an
        instance of your custom node structure.

        Defaults to sizeof(struct Node).

    INPUTS
        columns - How many columns your ListBrowser has.
        taglist - Attributes for the node, passed onto
            [SetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-setlistbrowsernodeattrsa.md).

    RESULT
        node - A node that can be added into the Exec list of labels for
            a ListBrowser gadget.

    SEE ALSO
        [FreeListBrowserNode()](autodocs-3.5/listbrowser-gc-freelistbrowsernode.md), [SetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-setlistbrowsernodeattrsa.md)
```
