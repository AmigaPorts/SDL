/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    class = message->Class;
    code = message->Code;

    /* When we're through with a message, reply */
    ReplyMsg((struct Message *)message);

    /* See what events occurred */
    switch (class) {
        case IDCMP_CLOSEWINDOW:
            done = TRUE;
            break;
        case IDCMP_MENUHELP:
            /*
