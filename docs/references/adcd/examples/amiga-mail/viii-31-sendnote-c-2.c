/* Source: ADCD 2.1
 * Section: viii-31-sendnote-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/viii-31-sendnote-c.md
 */

    /*
    ** If you used the above code, you would remove this line:
    */

    serv.sin_port = 8769;

    /*
    ** This tells the system the socket in question is an Internet socket
    */

    serv.sin_family = AF_INET;

    /*
    ** Initialize the socket
    */

    if ( (sock = socket( AF_INET, SOCK_STREAM, 0 )) < 0 )
    {
        printf("socket gen: %s\n", strerror(errno));
        FinalExit( RETURN_ERROR );
    }

    /*
    ** Connect the socket to the remote socket, which belongs to the
    ** server, and which will "wake up" the server.
    */

    if ( connect( sock,
                  (struct sockaddr *)&serv,
                  sizeof(struct sockaddr) ) < 0 )
    {
        printf("connect: %s\n", strerror(errno));
        s_close( sock );
        FinalExit( RETURN_ERROR );
    }

    /*
    ** Compose the message packet for transmission
    */

    out.nn_Code = NN_MSG;
    strcpy( (char *)&out.nn_Text, text );
    strcpy( (char *)&out.nn_Button, button );

    /*
    ** Send the packet to the remote system
    */

    send( sock, (char *)&out, sizeof(struct NetNote), 0 );

    printf("\nMessage sent to %s...waiting for answer...\n", hostnam );

    /*
    ** Wait for either acknowledge or error.  This is a potential hang
    ** location if the server is mortally wounded.
    */

    recv( sock, (char *)&out, sizeof(struct NetNote), 0 );

    /*
    ** Evaluate the packet returned to us
    */

    if (out.nn_Code == NN_ACK)
    {
        printf("Response:  Button %ld pressed.\n\n", out.nn_Retval );
    }
    else
    {
        puts("Error during message send...please try again later!");
        FinalExit( RETURN_ERROR );
    }

    /*
    ** Since ReadArgs() was called inside the main() function, the pointer
    ** to the buffer it created needs to be deallocated inside main().
    */

    if (rdargs)
    {
        FreeArgs( rdargs );
    }

    FinalExit( RETURN_OK );
