/* Source: ADCD 2.1
 * Section: the-shownote-server-application
 * Library: amiga-mail
 * ADCD reference: amiga-mail/the-shownote-server-application.md
 */

    struct sockaddr_in sockaddr;

    memset( &sockaddr, 0, len ); /* clear sockaddr */
    sockaddr.sin_family = AF_INET;
    sockaddr.sin_port = 8769;
    sockaddr.sin_addr.s_addr = INADDR_ANY;
