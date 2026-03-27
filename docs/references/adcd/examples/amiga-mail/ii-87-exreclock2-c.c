/* Source: ADCD 2.1
 * Section: ii-87-exreclock2-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-87-exreclock2-c.md
 */

    BPTR fh;

    if (DOSBase->lib_Version >= 37)   /* Record locking was introduced in Release 2, */
    {                                 /* but the standard startup code will open any */
                                      /* version of dos.library, so we have to ex-   */
                                      /* plicitly check the version number of DOS.   */

        if (fh = Open("t:testRLock", MODE_READWRITE))     /* Open the file, creating */
        {                                                 /*        it if necessary. */
            if (DOSTRUE == LockRecord(fh,           /* Lock the record as exclusive, */
                                      RECORDOFFSET, /* and do not wait if it is not  */
                                      RECORDSIZE,   /* available immediately.        */
                                      REC_EXCLUSIVE_IMMED, 0))
            {
                LONG error = RECORDOFFSET;

                                     /* If the record is beyond the end of the file, */
                if (Seek(fh, 0, OFFSET_END) < RECORDOFFSET)    /* lengthen the file. */
                    error = SetFileSize(fh, RECORDOFFSET, OFFSET_BEGINNING);

                if (error == RECORDOFFSET)    /* If there was no error with the file */
                {                             /*                file size, continue. */
                    if (Seek(fh, RECORDOFFSET, OFFSET_BEGINNING) < 0)
                        PrintFault(IoErr(), "Seek() error");

                    if (Write(fh, string, RECORDSIZE) < 0)
                        PrintFault(IoErr(), "Write() error");
                    else
                        PutStr("Write successful, ");
                }
                PutStr("Waiting 10 seconds...\n");
                TimeDelay(UNIT_VBLANK, 10, 0);       /* Amiga.lib function that puts */
                          /* a task to sleep for a given amount of time.  This waits */
                          /* 10 seconds before unlocking the record to give the user */
                          /* a chance to start a second copy of this example.        */
                UnLockRecord(fh, RECORDOFFSET, RECORDSIZE);
            }
            else PrintFault(IoErr(), "Record Lock Failed");
            Close(fh);
        }
        else PrintFault(IoErr(), "Open Failed");
    }
    else PutStr("Need dos.library V37 or greater.\n");
