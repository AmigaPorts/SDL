/* Source: ADCD 2.1
 * Section: opening-a-simple-file-requester
 * Library: amiga-mail
 * ADCD reference: amiga-mail/opening-a-simple-file-requester.md
 */

        APTR    rf_Reserved1;
        BYTE    *rf_File;       /* Filename pointer             */
        BYTE    *rf_Dir;        /* Directory name pointer       */
        CPTR    rf_Reserved2;
        UBYTE   rf_Reserved3;
        UBYTE   rf_Reserved4;
        APTR    rf_Reserved5;
        WORD    rf_LeftEdge,rf_TopEdge; /* Preferred window pos */
        WORD    rf_Width,rf_Height;   /* Preferred window size  */
        WORD    rf_Reserved6;
        LONG    rf_NumArgs;     /* A-la WB Args, for multiselects */
        struct WBArg *rf_ArgList;
        APTR    rf_UserData;    /* Applihandle (you may write!!) */
        APTR    rf_Reserved7;
        APTR    rf_Reserved8;
        BYTE    *rf_Pat;        /* Pattern match pointer */
        };                      /* note - more reserved fields follow */
