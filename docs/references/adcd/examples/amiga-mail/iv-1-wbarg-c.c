/* Source: ADCD 2.1
 * Section: iv-1-wbarg-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-1-wbarg-c.md
 */

    struct DiskObject *dob = NULL;
    UBYTE work_name[34];
    BPTR old, new;

    /* Copy the WBArg contents */
    strcpy (work_name, arg->wa_Name);

    /* Duplicate the lock */
    if (new = DupLock (arg->wa_Lock))
    {
