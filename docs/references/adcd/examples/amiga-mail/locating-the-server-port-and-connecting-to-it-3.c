/* Source: ADCD 2.1
 * Section: locating-the-server-port-and-connecting-to-it
 * Library: amiga-mail
 * ADCD reference: amiga-mail/locating-the-server-port-and-connecting-to-it.md
 */

    /*
    ** Connect the socket to the remote socket, which belongs to the
    ** server, and which will "wake up" the server.
    */

    if ( connect( sock,
                  (struct sockaddr *) &serv,
                  sizeof(struct sockaddr) ) < 0 )
    {
        printf("connect: %s\n", strerror(errno));
        s_close( sock );
        FinalExit( RETURN_ERROR );
    }
