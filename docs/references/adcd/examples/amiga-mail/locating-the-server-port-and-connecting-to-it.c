/* Source: ADCD 2.1
 * Section: locating-the-server-port-and-connecting-to-it
 * Library: amiga-mail
 * ADCD reference: amiga-mail/locating-the-server-port-and-connecting-to-it.md
 */

    struct servent *servptr;
    char servnam[] = "note";

    if ((servptr = getservbyname( servnam, "tcp" )) == NULL)
    {
        printf("%s not in inet:db/services list!",servnam);
        FinalExit( RETURN_ERROR );
    }
    serv.sin_port = servptr->s_port;


    /*
    ** This tells the system the socket in question is an Internet socket
    */

    serv.sin_family = AF_INET;
