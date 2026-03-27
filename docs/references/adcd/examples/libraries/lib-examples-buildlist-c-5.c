/* Source: ADCD 2.1
 * Section: lib-examples-buildlist-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-buildlist-c.md
 */

    if (node = FindName(list,name)) {
        while (node) {
            printf("Found a %s at location %lx\n",node->ln_Name,node);
            node = FindName((struct List *)node,name);
        }
    } else printf("No node with name %s found.\n",name);
