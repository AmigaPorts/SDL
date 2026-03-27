/* Source: ADCD 2.1
 * Section: 27-run-time-name-binding-of-mode-information
 * Library: libraries
 * ADCD reference: libraries/27-run-time-name-binding-of-mode-information.md
 */

    struct NameInfo query;

    /* fill the buffer with Mode dimension information */

    if(GetDisplayInfoData(handle, (UBYTE *)&query,sizeof(query),
       DTAG_NAME,NULL)))
    {
        printf("%s", query.Name);
    }
