---
title: 23 Exec Lists and Queues / List Structure
manual: libraries
chapter: libraries
section: 23-exec-lists-and-queues-list-structure
functions: []
libraries: []
---

# 23 Exec Lists and Queues / List Structure

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

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

 [Node Structure Definition](libraries/23-list-structure-node-structure-definition.md)    [List Header Structure Definition](libraries/23-list-structure-list-header-structure-definition.md) 
 [Node Initialization](libraries/23-list-structure-node-initialization.md)          [Header Initialization](libraries/23-list-structure-header-initialization.md) 

