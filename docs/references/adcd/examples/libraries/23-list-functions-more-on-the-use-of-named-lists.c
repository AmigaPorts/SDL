/* Source: ADCD 2.1
 * Section: 23-list-functions-more-on-the-use-of-named-lists
 * Library: libraries
 * ADCD reference: libraries/23-list-functions-more-on-the-use-of-named-lists.md
 */

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
