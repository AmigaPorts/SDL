---
title: reaction.lib/ClickTabsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-clicktabsa
functions: []
libraries: []
---

# reaction.lib/ClickTabsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       ClickTabsA -- Make a linked list of clicktab nodes
       ClickTabs -- varags stub for ClickTabsA
   SYNOPSIS

```c
       list = ClickTabsA( array )
       list = ClickTabs( label, ... )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *ClickTabsA( [STRPTR](autodocs-3.5/include-exec-types-h.md) * )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *ClickTabs( [STRPTR](autodocs-3.5/include-exec-types-h.md), ... )
```
   FUNCTION

       Make a linked list of clicktab nodes from the NULL terminated
       label array. The labels are not copied, so they must stay
       valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of clicktab nodes
