/* Source: ADCD 2.1
 * Section: lib-examples-trap-c-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-trap-c-c.md
 */

    struct Task *thistask;
    ULONG k,j;

    thistask = FindTask(NULL);

    /* Save our task's current trap code pointer */
    oldTrapCode = thistask->tc_TrapCode;

    /* Point task to our assembler trap handler code.  Ours will just count */
    /* divide-by-zero traps, and pass other traps on to the normal TrapCode */
    thistask->tc_TrapCode = (APTR)trapa;

    countdiv0 = 0L;

    for(k=0; k<4; k++)            /* Let's divide by zero a few times */
       {
       printf("dividing %ld by zero... ",k);
       j = k/0L;
       printf("did it\n");
       }
    printf("\nDivide by zero happened %ld times\n",countdiv0);

    thistask->tc_TrapCode = oldTrapCode;     /* Restore old trap code */
