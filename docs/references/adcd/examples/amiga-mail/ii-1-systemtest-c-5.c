/* Source: ADCD 2.1
 * Section: ii-1-systemtest-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/ii-1-systemtest-c.md
 */

    {
    if(result == SYSTEMFAIL)
        printf("*** SystemTest: could not start process for command\n");
    else if(result == WINDOWFAIL)
        printf("*** SystemTest: can't open con: for command\n");
    else
        printf("*** SystemTest: command (if synchronous) returned %ld\n",result);
    }
