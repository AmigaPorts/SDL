---
title: page_gc/SetPageGadgetAttrsA
manual: autodocs-3.5
chapter: autodocs-3.5
section: page-gc-setpagegadgetattrsa
functions: []
libraries: []
---

# page_gc/SetPageGadgetAttrsA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       SetPageGadgetAttrsA -- Set gadget attributes in a paged layout
       SetPageGadgetAttrs -- Varargs stub for SetPageGadgetAttrsA
   SYNOPSIS

```c
       value = SetPageGadgetAttrsA(gad, page, win, req, tags)
       D0                            A0     A1       A2   A3   A4

       ULONG SetPageGadgetAttrsA(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *,
               struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) *)

       ULONG SetPageGadgetAttrs(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *,
               struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, ULONG, ...)
```
   FUNCTION

       Like SetGadgetAttrs, but passes a NULL window and requester pointer
       if the gadget is not on the currently visible page.
