---
title: reaction.lib/BrowserNodesA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-browsernodesa
functions: []
libraries: []
---

# reaction.lib/BrowserNodesA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       BrowserNodesA -- Make a linked list of listbrowser nodes
       BrowserNodes -- varags stub for BrowserNodesA
   SYNOPSIS

```c
       list = BrowserNodesA( array )
       list = BrowserNodes( label, ... )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *BrowserNodesA( [STRPTR](autodocs-3.5/include-exec-types-h.md) * )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *BrowserNodes( [STRPTR](autodocs-3.5/include-exec-types-h.md), ... )
```
   FUNCTION

       Make a linked list of single column listbrowser nodes from the
       NULL terminated label array. The labels are not copied, so they
       must stay valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of chooser nodes
