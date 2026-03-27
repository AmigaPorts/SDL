---
title: reaction.lib/RadioButtonsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-radiobuttonsa
functions: []
libraries: []
---

# reaction.lib/RadioButtonsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       RadioButtonsA -- Make a linked list of radiobuttons
       RadioButtons -- varags stub for RadioButtonsA
   SYNOPSIS

```c
       list = RadioButtonsA( array )
       list = RadioButtons( label, ... )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *RadioButtonsA( [STRPTR](autodocs-3.5/include-exec-types-h.md) * )
       struct [List](autodocs-3.5/include-exec-lists-h.md) *RadioButtons( [STRPTR](autodocs-3.5/include-exec-types-h.md), ... )
```
   FUNCTION

       Make a linked list of radiobutton nodes from the NULL terminated
       label array. The labels are not copied, so they must stay
       valid until the list is free'd.
   INPUTS

       array -- a NULL terminated array of string pointers.
   RESULTS

       list -- a linked list of radiobutton nodes
