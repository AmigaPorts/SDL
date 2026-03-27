---
title: page_gc/RefreshPageGadget
manual: autodocs-3.5
chapter: autodocs-3.5
section: page-gc-refreshpagegadget
functions: []
libraries: []
---

# page_gc/RefreshPageGadget

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       RefreshPageGadget -- Refresh gadget in a paged layout
   SYNOPSIS

```c
       RefreshPageGadget(gad, page, win, req)
                         A0     A1       A2   A3

       void RefreshPageGadget(struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, [Object](autodocs-3.5/include-intuition-classusr-h.md) *,
               struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *)
```
   FUNCTION

```c
       Like RefreshGList(gad,win,req,1), but passes a NULL window and
       requester pointer if the gadget is not on the currently visible
       page.
```
