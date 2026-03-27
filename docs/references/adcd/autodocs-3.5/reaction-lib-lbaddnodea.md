---
title: reaction.lib/LBAddNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-lbaddnodea
functions: []
libraries: []
---

# reaction.lib/LBAddNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       LBAddNodeA -- V41 listbrowser.gadget [LBM_ADDNODE](autodocs-3.5/listbrowser-gc-lbm-addnode.md) method stub
       LBAddNode -- Varargs version of LBAddNodeA
```
   SYNOPSIS

```c
       node = LBAddNodeA( gadget, window, requester, node, tags )

       struct [Node](autodocs-3.5/include-exec-nodes-h.md) *LBAddNodeA( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

       node = LBAddNode( gadget, window, requester, node, tag, ... )

       struct [Node](autodocs-3.5/include-exec-nodes-h.md) *LBAddNode( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, sruct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, ULONG, ... );
```
   FUNCTION

```c
       A function stub for calling [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md) to allocate
       and add a new node to a listbrowser list. The main advantage
       of this function is to let you inline the vararg LBNA taglist.
```
   INPUTS

```c
       gadget = listbrowser object
       window = the window in which the gadget is, or NULL
       requester = the requester of the window, or NULL
       node = the node before which to add the new node. NULL for
           beginning of the list
       tags = the LBNA node allocation taglist
```
   RESULT

       A pointer to the newly allocated node, or NULL on failure.
   NOTES

```c
       This function uses the [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md) function also
       defined in this link library.
```
   SEE ALSO

```c
       [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md)
```
