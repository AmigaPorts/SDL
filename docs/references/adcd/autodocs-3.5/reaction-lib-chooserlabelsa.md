---
title: reaction.lib/ChooserLabelsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-chooserlabelsa
functions: []
libraries: []
---

# reaction.lib/ChooserLabelsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       ChooserLabelsA -- Make a linked list of chooser labels
       ChooserLabels -- varags stub for ChooserLabelsA
   SYNOPSIS

```c
       list = ChooserLabelsA( array )
       list = ChooserLabels( label, ... )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *ChooserLabelsA( [STRPTR](autodocs-3.5/include-exec-types-h.md) * )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *ChooserLabels( [STRPTR](autodocs-3.5/include-exec-types-h.md), ... )
```
   FUNCTION

       Make a linked list of chooser nodes from the NULL terminated
       label array. The labels are not copied, so they must stay
       valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of chooser nodes
