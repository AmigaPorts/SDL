---
title: listbrowser_gc/ListBrowserSelectAll
manual: autodocs-3.5
chapter: autodocs-3.5
section: listbrowser-gc-listbrowserselectall
functions: []
libraries: []
---

# listbrowser_gc/ListBrowserSelectAll

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

```c
    NAME
        ListBrowserSelectAll -- Select all nodes in a multiselect ListBrowser.

    SYNOPSIS
        VOID ListBrowserSelectAll(struct [List](autodocs-3.5/include-exec-lists-h.md) *);
        ListBrowserSelectAll(list);

    FUNCTION
        Sets the LBNA_Selected bit to TRUE in all nodes in list.  This is a
        quick way to select all nodes in a multi-select ListBrowser.

        Note that as with any modifications to a ListBrowser list, the list
        MUST be detached to the listbrowser at the time of modification.

    INPUTS
        list - a list of ListBrowser nodes, not currently attached to a
            ListBrowser.
```
