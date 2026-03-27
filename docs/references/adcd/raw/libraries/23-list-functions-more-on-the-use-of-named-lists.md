# 23 / List Functions / More on the Use of Named Lists


To find multiple occurrences of nodes with identical names, the [FindName()](../Libraries_Manual_guide/node02E3.html#line5)
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
[FindName()](../Libraries_Manual_guide/node02E3.html#line5) function never compares the specified name with that of the
starting node.  It always begins the search with the successor of the
starting point.

