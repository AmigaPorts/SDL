/* Source: ADCD 2.1
 * Section: viii-31-shownote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-shownote-c.md
 */

    struct EasyStruct easy =    {
                                sizeof(struct EasyStruct),
                                NULL,
                                NULL,
                                NULL,
                                NULL
                                };

    int retval = 0;

    if (IntuitionBase)
    {
        if (titletxt)
        {
            easy.es_Title = titletxt;
        }
        else
        {
            easy.es_Title = APPNAME;
        }

        if (msgtxt)
        {
            easy.es_TextFormat = msgtxt;
        }
        else
        {
            easy.es_TextFormat = "Null message text!\nIsnt it?";
        }

        if (btntxt)
        {
            easy.es_GadgetFormat = btntxt;
        }
        else
        {
            easy.es_GadgetFormat = "Take off, eh!";
        }

        retval = EasyRequest( NULL, &easy, NULL, NULL );
        return (retval);
    }
