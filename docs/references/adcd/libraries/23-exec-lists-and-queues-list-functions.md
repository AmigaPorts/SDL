---
title: 23 Exec Lists and Queues / List Functions
manual: libraries
chapter: libraries
section: 23-exec-lists-and-queues-list-functions
functions: []
libraries: []
---

# 23 Exec Lists and Queues / List Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Exec provides a number of symmetric functions for handling lists.  There
are functions for inserting and removing nodes, for adding and removing
head and tail nodes, for inserting nodes in a priority order, and for
searching for nodes by name.  The prototypes for Exec list handling
functions are as follows.

   Exec Functions
   --------------
   VOID AddHead( struct List *list, struct Node *node );
   VOID AddTail( struct List *list, struct Node *node );
   VOID Enqueue( struct List *list, struct Node *node );
   struct Node *FindName( struct List *list, UBYTE *name );
   VOID Insert( struct List *list, struct Node *node, struct Node *pred );
   VOID Remove( struct Node *node );
   struct Node *RemHead( struct List *list );
   struct Node *RemTail( struct List *list );

   Exec Support Functions in amiga.lib
   -----------------------------------
   VOID NewList( struct List *list );

In this discussion of the Exec list handling functions, header represents
a pointer to [List](libraries/23-list-structure-list-header-structure-definition.md) header, and node represents pointer to a [Node](libraries/23-list-structure-node-structure-definition.md).

 [Insertion and Removal](libraries/23-list-functions-insertion-and-removal.md) 
 [Special Case Insertion](libraries/23-list-functions-special-case-insertion.md) 
 [Special Case Removal](libraries/23-list-functions-special-case-removal.md) 
 [MinList/MinNode Operations](libraries/23-list-functions-minlist-minnode-operations.md) 
 [Prioritized Insertion](libraries/23-list-functions-prioritized-insertion.md) 
 [Searching by Name](libraries/23-list-functions-searching-by-name.md) 
 [More on the Use of Named Lists](libraries/23-list-functions-more-on-the-use-of-named-lists.md) 
 [List Macros for Assembly Language Programmers](libraries/23-list-functions-list-macros-for-assembly-language.md) 
 [Empty Lists](libraries/23-list-functions-empty-lists.md) 
 [Scanning a List](libraries/23-list-functions-scanning-a-list.md) 
 [Important Note About Shared Lists](libraries/23-list-functions-important-note-about-shared-lists.md) 

