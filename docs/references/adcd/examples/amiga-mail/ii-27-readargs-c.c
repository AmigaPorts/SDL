/* Source: ADCD 2.1
 * Section: ii-27-readargs-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-27-readargs-c.md
 */

    UWORD x;
    UBYTE **sourcefiles;

    /* Need to ask DOS for a RDArgs structure */
    if (myrda = (struct RDArgs *)AllocDosObject(DOS_RDARGS, NULL))
    {
        /* set up my parameters for ReadArgs() */

        /* use the following command line */
        myrda->RDA_Source.CS_Buffer = "file1 file2 file3 D=1 Link file4 file5\n";
        myrda->RDA_Source.CS_Length = (LONG)StrLen(myrda->RDA_Source.CS_Buffer);

        /* parse my command line */
        if (ReadArgs(TEMPLATE, result, myrda))
        {
            /*start printing out the results */

            /* We don't need to check if there is a value in
            ** result[OPT_SOURCE] because the ReadArgs() template
            ** requires (using the /A modifier) that there be
            ** file names, so ReadArgs() will either fill in a
            ** value or ReadArgs() will fail.
            */
            sourcefiles = (UBYTE **)result[OPT_SOURCE];
            /* VPrintf() is a lot like Printf() except it's in
            ** ROM, and the arguments are referenced from an
            ** array rather than being extracted from the stack.
            */
            VPrintf("Files specified:\n", NULL);
            for (x=0; sourcefiles[x]; x++)
                VPrintf("\t%s\n", (LONG *)&sourcefiles[x]);

            /* Is there something in the "DebugLevel" option?
            ** If there is, print it.
            */
            if (result[OPT_DEBUG])
                VPrintf("Debugging Level = %ld\n", (LONG *)result[OPT_DEBUG]);

            /* If the link toggle was present, say something about it. */
            if (result[OPT_LINK])
                VPrintf("linking...\n", NULL);
            FreeArgs(myrda);
        }
        FreeDosObject(DOS_RDARGS, myrda);
    }
