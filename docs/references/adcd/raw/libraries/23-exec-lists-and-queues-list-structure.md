# 23 Exec Lists and Queues / List Structure


A list is composed of a header and a doubly-linked chain of elements
called nodes.  The header contains memory pointers to the first and last
nodes of the linked chain.  The address of the header is used as the
handle to the entire list.  To manipulate a list, you must provide the
address of its header.


                                    _______________
                                 _\|               |
                                / /|   First Node  |
                               /  /|_______________|
                              /  /       |  /|\
            _______________  /  /        |   |
           |               |/  /    ____\|/__|_____
           |   Head Node   |/_/    |               |
           |_______________|\      |  Second Node  |
           |               |/_     |_______________|
           |   Tail Node   |\ \          |  /|\
           |_______________|\  \         |   |
                             \  \   ____\|/__|_____
                              \  \ |               |
                               \  \|   Third Node  |
                                \_\|_______________|
                                  /

             Figure 23-1: Simplified Overview of an Exec List
Nodes may be scattered anywhere in memory.  Each node contains two
pointers; a successor and a predecessor.  As illustrated above, a list
header contains two placeholder nodes that contain no data.  In an empty
list, the head and tail nodes point to each other.

 [Node Structure Definition](../Libraries_Manual_guide/node02D9.html)    [List Header Structure Definition](../Libraries_Manual_guide/node02DB.html) 
 [Node Initialization](../Libraries_Manual_guide/node02DA.html)          [Header Initialization](../Libraries_Manual_guide/node02DC.html) 

