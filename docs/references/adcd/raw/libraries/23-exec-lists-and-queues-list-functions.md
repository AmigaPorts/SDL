# 23 Exec Lists and Queues / List Functions


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
a pointer to [List](../Libraries_Manual_guide/node02DB.html#line23) header, and node represents pointer to a [Node](../Libraries_Manual_guide/node02D9.html#line19).

 [Insertion and Removal](../Libraries_Manual_guide/node02DE.html) 
 [Special Case Insertion](../Libraries_Manual_guide/node02DF.html) 
 [Special Case Removal](../Libraries_Manual_guide/node02E0.html) 
 [MinList/MinNode Operations](../Libraries_Manual_guide/node02E1.html) 
 [Prioritized Insertion](../Libraries_Manual_guide/node02E2.html) 
 [Searching by Name](../Libraries_Manual_guide/node02E3.html) 
 [More on the Use of Named Lists](../Libraries_Manual_guide/node02E4.html) 
 [List Macros for Assembly Language Programmers](../Libraries_Manual_guide/node02E5.html) 
 [Empty Lists](../Libraries_Manual_guide/node02E6.html) 
 [Scanning a List](../Libraries_Manual_guide/node02E7.html) 
 [Important Note About Shared Lists](../Libraries_Manual_guide/node02E8.html) 

