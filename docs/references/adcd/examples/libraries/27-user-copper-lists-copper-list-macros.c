/* Source: ADCD 2.1
 * Section: 27-user-copper-lists-copper-list-macros
 * Library: libraries
 * ADCD reference: libraries/27-user-copper-lists-copper-list-macros.md
 */

    /* Returning memory to the system if you have NOT
     * obtained the ViewPort from Intuition.  */
    FreeVPortCopLists(viewPort);

    /* Returning memory to the system if you HAVE
     * obtained the ViewPort from Intuition.  */
    CloseScreen(screen);    /* Intuition only */
