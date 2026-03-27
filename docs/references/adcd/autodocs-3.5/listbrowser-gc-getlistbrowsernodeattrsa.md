---
title: listbrowser_gc/GetListBrowserNodeAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-getlistbrowsernodeattrsa
functions: []
libraries: []
---

# listbrowser_gc/GetListBrowserNodeAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        GetListBrowserNodeAttrsA -- Get attributes about a ListBrowser node.

    SYNOPSIS
        VOID GetListBrowserNodeAttrs(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, [Tag](autodocs-3.5/include-utility-tagitem-h.md), ...)
        GetListBrowserNodeAttrs(node, firsttag, ...)

        VOID GetListBrowserNodeAttrsA(struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)
        GetListBrowserNodeAttrsA(node, taglist)

    FUNCTION
        The ListBrowser uses a private node structure and all attributes
        are hidden, and must therefore be accessed with this function.

    TAGS
        See [SetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-setlistbrowsernodeattrsa.md) for the list of supported tags.

    INPUTS
        node - The ListBrowser node to get the information on.
        taglist - A tag list of attributes to get.  ti_Tag is the attribute
            to get and ti_Data is a pointer to a location to copy the result
            to.  The exception is LBNA_Column, which is used to specify a
            column to get attributes on.

    SEE ALSO
        [SetListBrowserNodeAttrsA()](autodocs-3.5/listbrowser-gc-setlistbrowsernodeattrsa.md)
```
