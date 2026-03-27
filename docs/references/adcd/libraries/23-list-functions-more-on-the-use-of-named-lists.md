---
title: 23 / List Functions / More on the Use of Named Lists
manual: libraries
chapter: libraries
section: 23-list-functions-more-on-the-use-of-named-lists
functions: [FindName]
libraries: [exec.library]
---

# 23 / List Functions / More on the Use of Named Lists

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

To find multiple occurrences of nodes with identical names, the [FindName()](libraries/23-list-functions-searching-by-name.md)
function is called multiple times.  For example, if you want to find all
the nodes with the name pointed to by name:


```c
    VOID DisplayName(struct List *list,UBYTE *name)
    {
    struct Node *node;

        if (node = FindName(list,name))
            while (node)
            {
                printf("Found %s at location %lx\n",node->ln_Name,node);
                node = FindName((struct List *)node,name);
            }
        else printf("No node with name %s found.\n",name);
    }
```
Notice that the second search uses the node found by the first search. The
[FindName()](libraries/23-list-functions-searching-by-name.md) function never compares the specified name with that of the
starting node.  It always begins the search with the successor of the
starting point.

---

## See Also

- [FindName — exec.library](../autodocs/exec.library.md#findname)
