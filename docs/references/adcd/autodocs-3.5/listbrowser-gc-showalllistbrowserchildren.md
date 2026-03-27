---
title: listbrowser_gc/ShowAllListBrowserChildren
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-showalllistbrowserchildren
functions: []
libraries: []
---

# listbrowser_gc/ShowAllListBrowserChildren

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        ShowAllListBrowserChildren -- Show all children in a ListBrowser

    SYNOPSIS
        VOID ShowAllListBrowserChildren(struct [List](autodocs-3.5/include-exec-lists-h.md) *);
        ShowAllListBrowserChildren(list);

    FUNCTION
        Shows all children in a hierarchical ListBrowser, no matter what
        generation they are in.

        Note that as with any modifications to a ListBrowser list, the list
        must NOT be attached to the listbrowser at the time of modification.

    INPUTS
        list - a list of ListBrowser nodes, not currently attached to a
            ListBrowser.
```
