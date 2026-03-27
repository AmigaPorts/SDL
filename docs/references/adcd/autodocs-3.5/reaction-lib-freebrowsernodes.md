---
title: reaction.lib/FreeBrowserNodes
manual: autodocs-3.5
chapter: autodocs-3.5
section: reaction-lib-freebrowsernodes
functions: []
libraries: []
---

# reaction.lib/FreeBrowserNodes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       FreeBrowserNodes -- Free a linked list of chooser labels
   SYNOPSIS

```c
       FreeBrowserNodes( list )
       void FreeBrowserNodes( struct [List](autodocs-3.5/include-exec-lists-h.md) * )
```
   FUNCTION

```c
       Free a linked list of chooser labels allocated with
       [BrowserNodesA()](autodocs-3.5/reaction-lib-browsernodesa.md).
```
   INPUTS

       list -- the list to free
   RESULTS

       None
