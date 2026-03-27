# 23 / List Structure / Node Structure Definition


A Node structure is divided into three parts: linkage, information, and
content.  The linkage part contains memory pointers to the node's
successor and predecessor nodes.  The information part contains the node
type, the priority, and a name pointer.  The content part stores the
actual data structure of interest.  For nodes that require linkage only, a
small [MinNode](../Includes_and_Autodocs_2._guide/node0091.html#line31) structure is used.


```c
    struct MinNode
    {
        struct MinNode *mln_Succ;
        struct MinNode *mln_Pred;
    };
```
ln_Succ

```c
    points to the next node in the list (successor).
```
ln_Pred

```c
    points to the previous node in the list (predecessor).
```
When a type, priority, or name is required, a full-featured [Node](../Includes_and_Autodocs_2._guide/node0091.html#line23) structure
is used.


```c
    struct Node
    {
        struct Node *ln_Succ;
        struct Node *ln_Pred;
        UBYTE        ln_Type;
        BYTE         ln_Pri;
        char        *ln_Name;
    };
```
ln_Type

```c
    defines the type of the node (see <exec/[nodes.h](../Includes_and_Autodocs_2._guide/node0091.html#line43)> for a list).
```
ln_Pri

```c
    specifies the priority of the node  (+127 (highest) to -128
    (lowest)).
```
ln_Name

```c
    points to a printable name for the node (a NULL-terminated
    string).
```
The Node and MinNode structures are often incorporated into larger
structures, so groups of the larger structures can easily be linked
together.   For example, the Exec Interrupt structure is defined as
follows:


```c
    struct Interrupt
    {
        struct Node is_Node;
        APTR        is_Data;
        VOID        (*is_Code)();
    };
```
Here the is_Data and is_Code fields represent the useful content of the
node.  Because the Interrupt structure begins with a Node structure, it
may be passed to any of the Exec [List](../Libraries_Manual_guide/node02DB.html#line23) manipulation functions.

