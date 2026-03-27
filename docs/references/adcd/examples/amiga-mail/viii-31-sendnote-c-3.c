/* Source: ADCD 2.1
 * Section: viii-31-sendnote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-sendnote-c.md
 */

    if (SockBase)
    {
        cleanup_sockets();
        CloseLibrary(SockBase);
    }
