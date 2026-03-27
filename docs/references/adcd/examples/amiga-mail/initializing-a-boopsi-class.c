/* Source: ADCD 2.1
 * Section: initializing-a-boopsi-class
 * Library: amiga-mail
 * ADCD reference: amiga-mail/initializing-a-boopsi-class.md
 */

    ULONG __saveds dispatchmyTextLabel();

    /* This is the data that each instance of our class will need. */
    struct localObjData
    {
        /* Font to use */
        struct TextFont *lod_Font;

        /* The key that is underlined */
        UWORD lod_Key;

        /* DrawMode */
        UBYTE lod_Mode;
    };

    #define MYCLASSID           NULL
    #define SUPERCLASSID        (IMAGECLASS)
    #define LSIZE               (sizeof(struct localObjData))

    Class *initmyTextLabelClass (VOID)
    {
        extern ULONG __saveds dispatchmyTextLabel();
        extern ULONG hookEntry ();        /* defined in hookface.asm */
        Class *cl;

        if (cl = MakeClass (MYCLASSID, SUPERCLASSID, NULL, LSIZE, 0))
        {
            /* Fill in the callback hook */
            cl->cl_Dispatcher.h_Entry = hookEntry;
            cl->cl_Dispatcher.h_SubEntry = dispatchmyTextLabel;
        }

        /* Return a pointer to the class */
        return (cl);
    }
