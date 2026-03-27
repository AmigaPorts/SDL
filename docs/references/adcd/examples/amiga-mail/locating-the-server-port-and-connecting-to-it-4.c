/* Source: ADCD 2.1
 * Section: locating-the-server-port-and-connecting-to-it
 * Library: amiga-mail
 * ADCD reference: amiga-mail/locating-the-server-port-and-connecting-to-it.md
 */

    send( sock, (char *)&out, sizeof(struct NetNote), 0 );

    printf("\nMessage sent to %s...waiting for answer...\n", hostnam );

    /*
    ** Wait for either acknowlegde or error.
    */

    recv( sock, (char *)&out, sizeof(struct NetNote), 0 );
