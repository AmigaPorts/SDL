/* Source: ADCD 2.1
 * Section: identifying-network-events-and-talking-to-the-client
 * Library: amiga-mail
 * ADCD reference: amiga-mail/identifying-network-events-and-talking-to-the-client.md
 */

    int nsock;
    struct NetNote in;

    /*
    ** Okay, now the waiting packet needs to be removed from the connected
    ** socket that accept() gave back to us.  Verify its of type NN_MSG and
    ** if not, set return type to NN_ERR.  If it is, then display it and
    ** return an NN_ACK message.
    */

    recv( nsock, (char *)&in, sizeof(struct NetNote), 0 );
    if (in.nn_Code == NN_MSG)
    {
        DisplayBeep(NULL);  /* DisplayBeep() to get the user's attention */
        DisplayBeep(NULL);
        retv = DoER( rname, (char *)&in.nn_Text, (char *)&in.nn_Button );
        in.nn_Code = NN_ACK;
        in.nn_Retval = retv;
    }
    else
    {
        in.nn_Code = NN_ERR;
    }
