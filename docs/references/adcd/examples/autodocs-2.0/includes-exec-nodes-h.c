/* Source: ADCD 2.1
 * Section: includes-exec-nodes-h
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/includes-exec-nodes-h.md
 */

    struct  Node *ln_Succ;	/* Pointer to next (successor) */
    struct  Node *ln_Pred;	/* Pointer to previous (predecessor) */
    UBYTE   ln_Type;
    BYTE    ln_Pri;		/* Priority, for sorting */
    char    *ln_Name;		/* ID string, null terminated */
