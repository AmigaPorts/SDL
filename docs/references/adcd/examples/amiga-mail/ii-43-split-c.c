/* Source: ADCD 2.1
 * Section: ii-43-split-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-43-split-c.md
 */

    /* Fail silently if < 37 */
    if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
    {

        /* See the DOS Autodocs for more information about ReadArgs() */
        if (readargs = ReadArgs("FILE/A,BUFFERSIZE/A/N", rargs, NULL))
        {
            filename = (UBYTE *) rargs[0];
            buffersize = *((LONG *) rargs[1]);
            if (buffersize < 1 || buffersize > 4096)
                buffersize = BUFFERSIZE;

            if (buffer = AllocMem(buffersize, MEMF_CLEAR))
            {
                position = SplitName(filename, ':', buffer, position, buffersize);

                vargs[0] = position;
                vargs[1] = (LONG) buffer;
                VFPrintf(Output(), "Devicename: position: %ld Buffer: %s\n", vargs);

                if (position == -1)
                    position = 0;

                do
                {
                    position =
                        SplitName(filename, '/', buffer, position, buffersize);
                    vargs[0] = position;
                    vargs[1] = (LONG) buffer;
                    VFPrintf(Output(),
                             "Path component: position: %ld Buffer: %s\n",
                             vargs);
                } while (position != -1);
                FreeMem(buffer, buffersize);
            }
            FreeArgs(readargs);

        }
        else
            PrintFault(IoErr(), NULL);
        CloseLibrary((struct Library *) DOSBase);
    }
