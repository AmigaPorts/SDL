/* Source: ADCD 2.1
 * Section: locating-the-server-port-and-connecting-to-it
 * Library: amiga-mail
 * ADCD reference: amiga-mail/locating-the-server-port-and-connecting-to-it.md
 */

    /*
    ** Initialize the socket
    */

    if ( (sock = socket( AF_INET, SOCK_STREAM, 0 )) < 0 )
    {
        printf("socket gen: %s\n", strerror(errno));
        FinalExit( RETURN_ERROR );
    }
