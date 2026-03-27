/* Source: ADCD 2.1
 * Section: iii-1-ispy-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iii-1-ispy-c.md
 */

    struct SignalSemaphore *jt;


    if (jt = FindSemaphore(JTName))
    {
        ObtainSemaphoreShared(jt);
        if (rp != NULL && font != NULL)
        {
            (*oldSetFont) (rp, font, base);
        }
        else
        {
            ULONG           ACaller = stackptr[ACALLER];
            ULONG           CCaller = stackptr[CCALLER];

            Forbid();
            zprintf("SetFont(0x%lx,0x%lx) by `%s' (at 0x%lx) from A:0x%lx C:0x%lx SP:0x%lx\n",
                    rp, font,
                    SysBase->ThisTask->tc_Node.ln_Name,
                    SysBase->ThisTask,
                    ACaller,
                    CCaller,
                    stackptr);
            Permit();
        }
        ReleaseSemaphore(jt);
    }
