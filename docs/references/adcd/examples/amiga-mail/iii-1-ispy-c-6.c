/* Source: ADCD 2.1
 * Section: iii-1-ispy-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-1-ispy-c.md
 */

    struct SignalSemaphore *jt;
    struct Window  *window = NULL;


    if (jt = FindSemaphore(JTName))
    {
        ObtainSemaphoreShared(jt);
        if (newwindow != NULL || tags != NULL)
        {
            window = (*oldOpenWindowTagList) (newwindow, tags, base);
        }
        else
        {
            ULONG           ACaller = stackptr[ACALLER];
            ULONG           CCaller = stackptr[CCALLER];

            Forbid();
            zprintf("OpenWindowTagList(NULL,NULL) by `%s' (at 0x%lx) from A:0x%lx C:0x%lx SP:0x%lx\n",
                    SysBase->ThisTask->tc_Node.ln_Name,
                    SysBase->ThisTask,
                    ACaller,
                    CCaller,
                    stackptr);
            Permit();
        }
        ReleaseSemaphore(jt);
    }

    return (window);
