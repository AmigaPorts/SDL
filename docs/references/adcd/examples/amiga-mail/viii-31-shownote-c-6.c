/* Source: ADCD 2.1
 * Section: viii-31-shownote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-shownote-c.md
 */

    struct NetNote in;              /* Buffer for incoming packets */

    struct sockaddr_in saddr;       /* Socket address from accept() */
    struct in_addr sad;             /* Internet address component */

    struct hostent *hent;           /* Internet host information */

    int nsock,                      /* New socket from accept() */
        len,                        /* Length of addr from accept() */
        retv;                       /* Return value from DoER call */

    char rname[80],                 /* Buffer for titlebar string */
         *hname,                    /* Ptr to the hostname */
         *dd_addr;                  /* Ptr to the dotted-decimal address */

    /*
    ** We accept() the attempted connection on socket 'sock'
    ** which also yields the addr of the remote machine.  Then we
    ** attempt to convert the name to something meaningful.
    **
    ** First, we clear the stuff...
    */


    bzero( (char *)&rname, 80);
    bzero( (char *)&saddr, sizeof(struct sockaddr_in) );
    bzero( (char *)&sad, sizeof(struct in_addr) );
    len = sizeof(struct sockaddr_in);


    /*
    ** Then we accept the connection on the socket
    */
    /* Bug fixed 1/93: line below checked for wrong return value. Sorry Dale! */
    if (!(nsock = accept( sock, (struct sockaddr *)&saddr, &len )))
    {
        AppPanic("Accept:",errno);
    }

    /*
    ** Break the internet address out of the sockaddr_in structure and then
    ** create a dotted-decimal format string from it, for later use
    */

    sad = saddr.sin_addr;
    dd_addr = inet_ntoa(sad.s_addr);

    /*
    ** Use the internet address to find out the machine's name
    */

    if ( !(hent =
            gethostbyaddr( (char *)&sad.s_addr,
                           sizeof(struct in_addr),
                           AF_INET )))
    {
        AppPanic("Client resolution:\nAddress not in hosts db!", 0 );
    }
    hname = hent->h_name;

    /*
    ** Form the string which goes into the title bar using name & address
    */

    sprintf( rname, "FROM: %s (%s)", hname, dd_addr );



    /*
    ** Okay, now the waiting packet needs to be removed from the connected
    ** socket that accept() gave back to us.  Verify its of type NN_MSG and
    ** if not, set return type to NN_ERR.  If it is, then display it and
    ** return an NN_ACK message.
    */

    recv( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    if (in.nn_Code == NN_MSG)
    {
        DisplayBeep(NULL);
        DisplayBeep(NULL);
        retv = DoER( rname, (char *)&in.nn_Text, (char *)&in.nn_Button );
        in.nn_Code = NN_ACK;
        in.nn_Retval = retv;
    }
    else
    {
        in.nn_Code = NN_ERR;
    }

    /*
    ** Having dealt with the message one way or the other, send the message
    ** back at the remote, then disconnect from the remote and return.
    */

    send( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    s_close( nsock );
