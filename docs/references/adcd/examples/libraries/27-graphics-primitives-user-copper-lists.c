/* Source: ADCD 2.1
 * Section: 27-graphics-primitives-user-copper-lists
 * Library: libraries
 * ADCD reference: libraries/27-graphics-primitives-user-copper-lists.md
 */

    struct UCopList *uCopList = NULL;

    /* Allocate memory for the Copper list.  Make certain that the */
    /* initial memory is cleared.                                  */
    uCopList = (struct UCopList *)
            AllocMem(sizeof(struct UCopList), MEMF_PUBLIC|MEMF_CLEAR);

    if (uCopList == NULL)
            return(FALSE);


    Note:
    -----
     User Copper lists do not have to be in Chip RAM.
