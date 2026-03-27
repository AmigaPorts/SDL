/* Source: ADCD 2.1
 * Section: ii-113-multilist-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-113-multilist-c.md
 */

    struct DevProc *dp=NULL;
    struct MsgPort *old_fsport;
    BPTR           lock, old_curdir;
    char           *rest_of_path;


    while(dp = GetDeviceProc(dos_path, dp))
    {                                        /* I need to cut the device name from  */
        rest_of_path = strchr(dos_path,':'); /* the front of dos_path so I can give */
                                             /* that substring to Lock().           */
        if (rest_of_path == NULL)                 /* There was no device name to    */
            rest_of_path = dos_path;              /* cut off, use the whole string. */
        else
            rest_of_path++;     /* Increment string pointer to just past the colon. */



        old_fsport = SetFileSysTask(dp->dvp_Port); /* in case dp->dvp_Lock is NULL. */
        old_curdir = CurrentDir(dp->dvp_Lock);     /* Lock() locks relative to the  */
                                /* current directory and falls back to the root of  */
                                /* the current file system if dp->dvp_Lock is NULL. */

        lock = Lock(rest_of_path,SHARED_LOCK);

        (void) SetFileSysTask(old_fsport); /* reset the process' default filesystem */
        (void) CurrentDir(old_curdir);     /* port and current dir to their initial */
                                           /* values for clean up later.            */

        if (lock)
        {
            if (!(*passback_func)(lock))
            {
                printf("function returned false\n");
                UnLock(lock);         /* UnLock() will ignore NULL lock */
                FreeDeviceProc(dp);
                return FALSE;
            }
            UnLock(lock);
        }
    }
    if (IoErr() == ERROR_NO_MORE_ENTRIES)
        return TRUE;               /* At present, a bug in DOS prevents this case, */
    else                           /* so DoAllAssigns() always returns FALSE.      */
        return FALSE;
