/* Source: ADCD 2.1
 * Section: lib-examples-vertb-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-vertb-c.md
 */

    struct Interrupt *vbint;
    ULONG counter = 0;
    ULONG endcount;
                                                                         /* Allocate memory for  */
    if (vbint = AllocMem(sizeof(struct Interrupt), MEMF_PUBLIC|MEMF_CLEAR))   /* interrupt node. */
    {
        vbint->is_Node.ln_Type = NT_INTERRUPT;         /* Initialize the node. */
        vbint->is_Node.ln_Pri = -60;
        vbint->is_Node.ln_Name = "VertB-Example";
        vbint->is_Data = (APTR)&counter;
        vbint->is_Code = VertBServer;


        AddIntServer(INTB_VERTB, vbint); /* Kick this interrupt server to life. */

        printf("VBlank server will increment a counter every frame.\n");
        printf("counter started at zero, CTRL-C to remove server\n");

        Wait(SIGBREAKF_CTRL_C);
        endcount = counter;
        printf("%ld vertical blanks occurred\nRemoving server\n", endcount);

        RemIntServer(INTB_VERTB, vbint);
        FreeMem(vbint, sizeof(struct Interrupt));
    }
    else printf("Can't allocate memory for interrupt node\n");
