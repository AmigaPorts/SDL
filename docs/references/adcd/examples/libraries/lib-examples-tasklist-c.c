/* Source: ADCD 2.1
 * Section: lib-examples-tasklist-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-tasklist-c.md
 */

    struct List *ourtasklist;
    struct List *exectasklist;
    struct Task *task;
    struct TaskNode *node, *tnode, *rnode = NULL;
    struct Node *execnode;

    /* Allocate memory for our list */
    if (ourtasklist = AllocMem(sizeof(struct List), MEMF_CLEAR)) {
        /* Initialize list structure (ala NewList()) */
        ourtasklist->lh_Head = (struct Node *)&ourtasklist->lh_Tail;
        ourtasklist->lh_Tail = 0;
        ourtasklist->lh_TailPred = (struct Node *)&ourtasklist->lh_Head;

        /* Make sure tasks won't switch lists or go away */
        Disable();

        /* Snapshot task WAIT list */
        exectasklist = &(SysBase->TaskWait);
        for (execnode = exectasklist->lh_Head;
                 execnode->ln_Succ; execnode = execnode->ln_Succ)
        {
            if (tnode = AllocMem(sizeof(struct TaskNode), MEMF_CLEAR))
            {
                /* Save task information we want to print */
                strncpy(tnode->tn_Name, execnode->ln_Name, 32);
                tnode->tn_Node.ln_Pri = execnode->ln_Pri;
                tnode->tn_TaskAddress = (ULONG)execnode;
                tnode->tn_SigAlloc = ((struct Task *)execnode)->tc_SigAlloc;
                tnode->tn_SigWait = ((struct Task*)execnode)->tc_SigWait;
                AddTail(ourtasklist, (struct Node *)tnode);
            }
            else break;
        }

        /* Snapshot task READY list */
        exectasklist = &(SysBase->TaskReady);
        for (execnode = exectasklist->lh_Head;
                 execnode->ln_Succ; execnode = execnode->ln_Succ)
        {
            if (tnode = AllocMem(sizeof(struct TaskNode), MEMF_CLEAR))
            {
                /* Save task information we want to print */
                strncpy(tnode->tn_Name, execnode->ln_Name, 32);
                tnode->tn_Node.ln_Pri = execnode->ln_Pri;
                tnode->tn_TaskAddress = (ULONG)execnode;
                tnode->tn_SigAlloc = ((struct Task *)execnode)->tc_SigAlloc;
                tnode->tn_SigWait = ((struct Task*)execnode)->tc_SigWait;
                AddTail(ourtasklist, (struct Node *)tnode);
                if(!rnode)  rnode = tnode;  /* first READY task */
            }
            else
                break;
        }

        /* Re-enable interrupts and taskswitching */
        Enable();

        /* Print now (printing above would have defeated a Forbid or Disable) */
        printf("Pri Address     SigAlloc    SigWait    Taskname\n");

        node = (struct TaskNode *)(ourtasklist->lh_Head);
        printf("\nWAITING:\n");
        while (tnode = (struct TaskNode *)node->tn_Node.ln_Succ)
        {
            if(tnode == rnode)
                printf("\nREADY:\n");  /* we set rnode above */
            printf("%02d  0x%08lx  0x%08lx  0x%08lx %s\n",
                    node->tn_Node.ln_Pri, node->tn_TaskAddress, node->tn_SigAlloc,
                    node->tn_SigWait, node->tn_Name);

            /* Free the memory, no need to remove the node, referenced once only */
            FreeMem(node,sizeof(struct TaskNode));
            node = tnode;
        }
        FreeMem(ourtasklist, sizeof(struct List));

        /* Say who we are */
        printf("\nTHIS TASK:\n");
        task = FindTask(NULL);
        printf("%02d  0x%08lx  0x%08lx  0x%08lx %s\n",
                task->tc_Node.ln_Pri, task, task->tc_SigAlloc,
                task->tc_SigWait, task->tc_Node.ln_Name);

    }
