---
title: 23 / List Functions / MinList/MinNode Operations
manual: libraries
chapter: libraries
section: 23-list-functions-minlist-minnode-operations
functions: []
libraries: []
---

# 23 / List Functions / MinList/MinNode Operations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

All of the above functions and macros will work with long or short format
node structures.  A [MinNode](libraries/23-list-structure-node-structure-definition.md) structure contains only linkage information.
A full [Node](libraries/23-list-structure-node-structure-definition.md) structure contains linkage information, as well as type,
priority and name fields.  The smaller MinNode is used where space and
memory alignment issues are important.  The larger Node is used for queues
or lists that require a name tag for each node.

