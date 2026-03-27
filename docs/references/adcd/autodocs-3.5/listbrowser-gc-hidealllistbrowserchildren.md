---
title: listbrowser_gc/HideAllListBrowserChildren
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-hidealllistbrowserchildren
functions: []
libraries: []
---

# listbrowser_gc/HideAllListBrowserChildren

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        HideAllListBrowserChildren -- Hide all children in a ListBrowser.

    SYNOPSIS
        VOID HideAllListBrowserChildren(struct [List](autodocs-3.5/include-exec-lists-h.md) *);
        HideAllListBrowserChildren(list);

    FUNCTION
        Hides all children in a hierarchical ListBrowser, "collapsing" all
        generations so that only root generation nodes are shown.

        Note that as with any modifications to a ListBrowser list, the list
        MUST be detached to the listbrowser at the time of modification.

    INPUTS
        list - a list of ListBrowser nodes, not currently attached to a
            ListBrowser.
```
