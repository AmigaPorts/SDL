---
title: 23 Exec Lists and Queues / Function Reference
manual: libraries
chapter: libraries
section: 23-exec-lists-and-queues-function-reference
functions: [AddHead, AddTail, Enqueue, FindName, Insert, RemHead, RemTail, Remove]
libraries: [exec.library]
---

# 23 Exec Lists and Queues / Function Reference

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The following charts give a brief description of the Exec list and queue
functions and assembler macros.  See the Amiga ROM Kernel Reference
Manual: Includes and Autodocs for details about each call.


             Table 23-1: Exec List and Queue Functions
  _________________________________________________________________
 |                                                                 |
 |  Exec Function  Description                                     |
 |=================================================================|
 |    [AddHead()](autodocs-2.0/exec-library-addhead.md)  Insert a node at the head of a list.              |
 |    [AddTail()](autodocs-2.0/exec-library-addtail.md)  Append a node to the tail of a list.              |
 |    [Enqueue()](autodocs-2.0/exec-library-enqueue.md)  Insert or append a node to a system queue.        |
 |   [FindName()](autodocs-2.0/exec-library-findname.md)  Find a node with a given name in a system list.   |
 |     [Insert()](autodocs-2.0/exec-library-insert.md)  Insert a node into a list.                        |
 |  IsListEmpty  Test if list is empty                             |
 |    [NewList()](autodocs-2.0/amiga-lib-newlist.md)  Initialize a list structure for use.              |
 |    [RemHead()](autodocs-2.0/exec-library-remhead.md)  Remove the head node from a list.                 |
 |     [Remove()](autodocs-2.0/exec-library-remove.md)  Remove a node from a list.                        |
 |    [RemTail()](autodocs-2.0/exec-library-remtail.md)  Remove the tail node from a list.                 |
 |_________________________________________________________________|


          Table 23-2: Exec List and Queue Assembler Macros
  _________________________________________________________________
 |                                                                 |
 |  Exec Function  Description                                     |
 |=================================================================|
 |      [NEWLIST](autodocs-2.0/includes-exec-lists-i.md)  Initialize a list header for use.                 |
 |      [TSTLIST](autodocs-2.0/includes-exec-lists-i.md)  Test if list is empty (list address in register). |
 |               No arbitration needed.                            |
 |      [TSTLST2](autodocs-2.0/includes-exec-lists-i.md)  Test is list is empty (from effective address of  |
 |               list).  Arbitration needed.                       |
 |         [SUCC](autodocs-2.0/includes-exec-lists-i.md)  Get next node in a list.                          |
 |         [PRED](autodocs-2.0/includes-exec-lists-i.md)  Get previous node in a list.                      |
 |      [IFEMPTY](autodocs-2.0/includes-exec-lists-i.md)  Branch if list is empty.                          |
 |   [IFNOTEMPTY](autodocs-2.0/includes-exec-lists-i.md)  Branch if list is not empty.                      |
 |      [TSTNODE](autodocs-2.0/includes-exec-lists-i.md)  Get next node, test if at end of list.            |
 |     [NEXTNODE](autodocs-2.0/includes-exec-lists-i.md)  Get next node, go to exit label if at end.        |
 |      [ADDHEAD](autodocs-2.0/includes-exec-lists-i.md)  Add node to head of list.                         |
 |      [ADDTAIL](autodocs-2.0/includes-exec-lists-i.md)  Add node to tail of list.                         |
 |       [REMOVE](autodocs-2.0/includes-exec-lists-i.md)  Remove node from a list.                          |
 |      [REMHEAD](autodocs-2.0/includes-exec-lists-i.md)  Remove node from head of list.                    |
 |     [REMHEADQ](autodocs-2.0/includes-exec-lists-i.md)  Remove node from head of list quickly.            |
 |      [REMTAIL](autodocs-2.0/includes-exec-lists-i.md)  Remove node from tail of list.                    |
 |_________________________________________________________________|

---

## See Also

- [AddHead — exec.library](../autodocs/exec.library.md#addhead)
- [AddTail — exec.library](../autodocs/exec.library.md#addtail)
- [Enqueue — exec.library](../autodocs/exec.library.md#enqueue)
- [FindName — exec.library](../autodocs/exec.library.md#findname)
- [Insert — exec.library](../autodocs/exec.library.md#insert)
- [RemHead — exec.library](../autodocs/exec.library.md#remhead)
- [RemTail — exec.library](../autodocs/exec.library.md#remtail)
- [Remove — exec.library](../autodocs/exec.library.md#remove)
