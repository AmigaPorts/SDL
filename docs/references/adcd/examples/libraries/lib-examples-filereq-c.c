/* Source: ADCD 2.1
 * Section: lib-examples-filereq-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-filereq-c.md
 */

    struct FileRequester *fr;

    if (AslBase = OpenLibrary("asl.library", 37L))
    {
        if (fr = (struct FileRequester *)
            AllocAslRequest(ASL_FileRequest, frtags))
        {
            if (AslRequest(fr, NULL))
            {
                printf("PATH=%s  FILE=%s\n", fr->rf_Dir, fr->rf_File);
                printf("To combine the path and filename, copy the path\n");
                printf("to a buffer, add the filename with Dos AddPart().\n");
            }
            FreeAslRequest(fr);
        }
        else printf("User Cancelled\n");

        CloseLibrary(AslBase);
    }
