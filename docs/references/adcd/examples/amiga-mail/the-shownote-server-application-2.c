/* Source: ADCD 2.1
 * Section: the-shownote-server-application
 * Library: amiga-mail
 * ADCD reference: amiga-mail/the-shownote-server-application.md
 */

    /*
    ** Open the initial socket on which incoming messages will queue for
    ** handling.  While the server is iterative, I do it this way so that
    ** SIGBREAKF_CTRL_C will continue to function.
    */

    int snum;

    if ((snum = socket( AF_INET, SOCK_STREAM, 0 )) == -1)
    {
        AppPanic("Socket Creation:",errno);
    }
