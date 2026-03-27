---
title: reaction.lib/LBRemNode
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-lbremnode
functions: []
libraries: []
---

# reaction.lib/LBRemNode

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       LBRemNode -- V41 listbrowser.gadget [LBM_REMNODE](autodocs-3.5/listbrowser-gc-lbm-remnode.md) method stub
```
   SYNOPSIS

```c
       node = LBRemNode( gadget, window, requester, node )

       ULONG LBRemNode( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) * );
```
   FUNCTION

```c
       A function stub for calling [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md) to remove and
       free a node from a listbrowser list. This function mostly
       exists for completeness's sake.
```
   INPUTS

```c
       gadget = listbrowser object
       window = the window in which the gadget is, or NULL
       requester = the requester of the window, or NULL
       node = the node to free
```
   RESULT

       Nonzero on success.
   NOTES

```c
       This function uses the [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md) function also
       defined in this link library.
```
   SEE ALSO

```c
       [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md)
```
