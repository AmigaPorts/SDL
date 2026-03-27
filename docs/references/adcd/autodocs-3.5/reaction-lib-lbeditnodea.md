---
title: reaction.lib/LBEditNodeA
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-lbeditnodea
functions: []
libraries: []
---

# reaction.lib/LBEditNodeA

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

```c
       LBEditNodeA -- V41 listbrowser.gadget [LBM_EDITNODE](autodocs-3.5/listbrowser-gc-lbm-editnode.md) method stub
       LBEditNode -- Varargs version of LBEditNodeA
```
   SYNOPSIS

```c
       success = LBEditNodeA( gadget, window, requester, node, tags )

       ULONG LBEditNodeA( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) * );

       success = LBEditNode( gadget, window, requester, node, tag, ... )

       ULONG LBEditNode( struct [Gadget](autodocs-3.5/include-intuition-intuition-h.md) *, sruct [Window](autodocs-3.5/include-intuition-intuition-h.md) *,
           struct [Requester](autodocs-3.5/include-intuition-intuition-h.md) *, struct [Node](autodocs-3.5/include-exec-nodes-h.md) *, ULONG, ... );
```
   FUNCTION

```c
       A function stub for calling [LibDoGadgetMethodA()](autodocs-3.5/reaction-lib-libdogadgetmethoda.md) to modify an
       existing node on a listbrowser list. The main advantage
       of this function is to let you inline the vararg LBNA taglist.
```
   INPUTS

```c
       gadget = listbrowser object
       window = the window in which the gadget is, or NULL
       requester = the requester of the window, or NULL
       node = the node to modify
       tags = the LBNA node modification taglist
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
