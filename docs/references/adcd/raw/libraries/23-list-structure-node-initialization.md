# 23 / List Structure / Node Initialization


Before linking a node into a list, certain fields may need initialization.
Initialization consists of setting the [ln_Type](../Libraries_Manual_guide/node02D9.html#line31), [ln_Pri](../Libraries_Manual_guide/node02D9.html#line34), and [ln_Name](../Libraries_Manual_guide/node02D9.html#line38) fields
to their appropriate values (A [MinNode](../Libraries_Manual_guide/node02D9.html#line7) structure does not have these
fields).  The successor and predecessor fields do not require
initialization.

The [ln_Type](../Libraries_Manual_guide/node02D9.html#line31) field contains the data type of the node.  This indicates to
Exec (and other subsystems) the type, and hence the structure, of the
content portion of the node (the extra data after the [Node](../Libraries_Manual_guide/node02D9.html#line19) structure).
The standard system types are defined in the <exec/[nodes.h](../Includes_and_Autodocs_2._guide/node0091.html#line43)> include file.
Some examples of standard system types are NT_TASK, NT_INTERRUPT,
NT_DEVICE, and NT_MSGPORT.

The [ln_Pri](../Libraries_Manual_guide/node02D9.html#line34) field uses a signed numerical value ranging from +127 to -128
to indicate the priority of the node.  Higher-priority nodes have greater
values; for example, 127 is the highest priority, zero is nominal
priority, and -128 is the lowest priority.  Some Exec lists are kept
sorted by priority order.  In such lists, the highest-priority node is at
the head of the list, and the lowest-priority node is at the tail of the
list.  Most Exec node types do not use a priority.  In such cases,
initialize the priority field to zero.

The [ln_Name](../Libraries_Manual_guide/node02D9.html#line38) field is a pointer to a NULL-terminated string of characters.
Node names are used to find and identify list-bound objects (like public
message ports and libraries), and to bind symbolic names to actual nodes.
Names are also useful for debugging purposes, so it is a good idea to
provide every node with a name.  Take care to provide a valid name
pointer; Exec does not copy name strings.

This fragment initializes a [Node](../Libraries_Manual_guide/node02D9.html#line19) called myInt, an instance of the
[Interrupt](../Libraries_Manual_guide/node02D9.html#line47) data structure introduced above.


```c
    struct Interrupt interrupt;

    interrupt.is_Node.ln_Type = NT_INTERRUPT;
    interrupt.is_Node.ln_Pri  = -10;
    interrupt.is_Node.ln_Name = "sample.interrupt";
```
