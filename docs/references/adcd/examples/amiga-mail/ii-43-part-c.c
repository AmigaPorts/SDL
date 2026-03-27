/* Source: ADCD 2.1
 * Section: ii-43-part-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-43-part-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = OpenLibrary("dos.library", 37))
    {

        /*
         * Use a generous 256 byte buffer. Should suffice for everything but
         * extreme cases.
         */
        if (buffer = AllocMem(256, MEMF_CLEAR))
        {

            if (readargs = ReadArgs("PATH/A,FILENAME/A", rargs, NULL))
            {
                path = (UBYTE *) (rargs[0]);
                filename = (UBYTE *) (rargs[1]);

                error = GetPath(path, buffer, 255);
                if (error)
                    PrintFault(error, NULL);

                filepart = FilePart(path);
                pathpart = PathPart(path);

                vargs[0] = (LONG) path;
                vargs[1] = (LONG) filepart;
                vargs[2] = (LONG) pathpart;
                vargs[3] = (LONG) buffer;
                VFPrintf(Output(),
                         "Filename: %s\nFilepart: %s\nPathpart: %s\nPath: %s\n",
                         vargs);

                /* No requesters */
                process = (struct Process *) FindTask(NULL);
                wptr = process->pr_WindowPtr;
                process->pr_WindowPtr = (APTR) - 1L;

                /*
                 * Make sure this name is for real. This will weed out names
                 * like "dh0:/" and non-existent directories. (and also
                 * complain about non-mounted volumes.) It is tempting to look
                 * for trailing slashes and remove them but you shouldn't. You
                 * might misinterpret the users intention. Better to generate a
                 * warning and prompt for new input.
                 */
                if (lock = Lock(buffer, SHARED_LOCK))
                    UnLock(lock);
                else
                    PrintFault(IoErr(), buffer);

                /* Reset windowpointer */
                process->pr_WindowPtr = wptr;

                /*
                 * Normally we should respect the test for an invalid path. To
                 * show the results however, we blunder along...
                 *
                 * Add the filename to the path.
                 */
                if (AddPart(buffer, filename, 255))
                    vargs[0] = (LONG) buffer;
                else
                    vargs[0] = (LONG) "OVERFLOW";

                VFPrintf(Output(), "\nNew path: %s\n", vargs);

                FreeArgs(readargs);
            }
            else
                PrintFault(IoErr(), NULL);
            FreeMem(buffer, 256);
        }
        CloseLibrary(DOSBase);
    }
