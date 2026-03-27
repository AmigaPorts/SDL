/* Source: ADCD 2.1
 * Section: ii-1-systemtest-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-1-systemtest-c.md
 */

    {
    struct TagItem stags[5];
    BPTR file;

    if(file = Open(autocon, MODE_OLDFILE))
        {
        stags[0].ti_Tag = SYS_Input;
        stags[0].ti_Data = file;
        stags[1].ti_Tag = SYS_Output;
        stags[1].ti_Data = NULL;
        stags[2].ti_Tag = SYS_Asynch;
        stags[2].ti_Data = TRUE;
        stags[3].ti_Tag = SYS_UserShell;
        stags[3].ti_Data = TRUE;
        stags[4].ti_Tag = TAG_DONE;
        return(System(command, stags));
        }
    else return(WINDOWFAIL);
    }
