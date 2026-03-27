/* Source: ADCD 2.1
 * Section: identifying-network-events-and-talking-to-the-client
 * Library: amiga-mail
 * ADCD reference: amiga-mail/identifying-network-events-and-talking-to-the-client.md
 */

    struct hostname *hent;
    struct in_addr sad;
    char *dd_addr, *hname, rname[80];


    /*
    ** Get the internet address out of the sockaddr_in structure and then
    ** create a dotted-decimal format string from it.
    */

    sad = saddr.sin_addr;
    dd_addr = inet_ntoa(sad.s_addr);

    /*
    ** Use the internet address to find out the machine's name
    */

    if ( !( hent = gethostbyaddr( (char *) &sad.s_addr,
                                  sizeof(struct in_addr),
                                  AF_INET )))
    {
        AppPanic("Client resolution:\nAddress not in hosts db!", 0 );
    }
    hname = hent->h_name;
