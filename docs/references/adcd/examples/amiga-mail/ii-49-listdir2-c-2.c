/* Source: ADCD 2.1
 * Section: ii-49-listdir2-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-49-listdir2-c.md
 */

    LONG            neededfiletype = (LONG) hook->h_Data;
    BOOL            success = TRUE;

    if (neededfiletype != 0)
    {
        if (data->ed_Type > 0 && neededfiletype < 0)
            success = FALSE;
        if (data->ed_Type < 0 && neededfiletype > 0)
            success = FALSE;
    }
    return (success);
