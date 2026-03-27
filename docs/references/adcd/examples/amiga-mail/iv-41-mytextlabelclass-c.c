/* Source: ADCD 2.1
 * Section: iv-41-mytextlabelclass-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-41-mytextlabelclass-c.md
 */

    ULONG           hookEntry(); /* from hookface.o */
    Class          *cl;

    if (cl = MakeClass(MYCLASSID,
                       SUPERCLASSID, NULL,
                       sizeof(struct localObjData), 0))
    {
        /* Fill in the callback hook */
        cl->cl_Dispatcher.h_Entry = hookEntry;
        cl->cl_Dispatcher.h_SubEntry = dispatchmyTextLabel;
    }
    /* Return a pointer to the class */
    return (cl);
