/* Source: ADCD 2.1
 * Section: 23-list-functions-empty-lists
 * Library: libraries
 * ADCD reference: libraries/23-list-functions-empty-lists.md
 */

    /* You can use this method...   */
    if (list->lh_TailPred == (struct Node *)list)
        printf("list is empty\n");

    /* Or you can use this method   */
    if (NULL == list->lh_Head->ln_Succ)
        printf("list is empty\n");
