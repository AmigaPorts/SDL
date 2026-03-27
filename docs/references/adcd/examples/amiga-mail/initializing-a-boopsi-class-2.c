/* Source: ADCD 2.1
 * Section: initializing-a-boopsi-class
 * Library: amiga-mail
 * ADCD reference: amiga-mail/initializing-a-boopsi-class.md
 */

    #define MYCLASSID           "mytextlabelclass"

    ULONG __saveds dispatchmyTextLabel();

    Class *initmyTextLabelClass (VOID)
    {
        extern ULONG __saveds dispatchmyTextLabel();
        extern ULONG hookEntry ();
        Class *cl;

        if (cl = MakeClass (MYCLASSID, SUPERCLASSID, NULL, LSIZE, 0))
        {
            /* Fill in the callback hook */
            cl->cl_Dispatcher.h_Entry = hookEntry;
            cl->cl_Dispatcher.h_SubEntry = dispatchmyTextLabel;

            /* Make the class public */
            AddClass (cl);
        }

        /* Return a pointer to the class */
        return (cl);
    }
