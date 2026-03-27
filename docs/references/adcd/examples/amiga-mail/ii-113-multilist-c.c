/* Source: ADCD 2.1
 * Section: ii-113-multilist-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-113-multilist-c.md
 */

    if (DOSBase->dl_lib.lib_Version >= 37)
    {
        if (argc > 1)
        {
            (void) DoAllAssigns(argv[1], &ListContents);
        }
    }
