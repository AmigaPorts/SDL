/* Source: ADCD 2.1
 * Section: lib-examples-eventloop-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-eventloop-c.md
 */

    {
    /* It is often convenient to copy the data out of the message.
    ** In many cases, this lets the application reply to the message
    ** quickly.  Copying the data is not required, if the code does
    ** not reply to the message until the end of the loop, then
    ** it may directly reference the message information anywhere
    ** before the reply.
    */
    class  = message->Class;
    code   = message->Code;
    mousex = message->MouseX;
    mousey = message->MouseY;

    /* The loop should reply as soon as possible.  Note that the code
    ** may not reference data in the message after replying to the
    ** message.  Thus, the application should not reply to the message
    ** until it is done referencing information in it.
    **
    ** Be sure to reply to every message received with GetMsg().
    */
    ReplyMsg((struct Message *)message);

    /* The class contains the IDCMP type of the message. */
    switch (class)
        {
        case IDCMP_CLOSEWINDOW:
            done = TRUE;
            break;
        case IDCMP_VANILLAKEY:
            printf("IDCMP_VANILLAKEY (%lc)\n",code);
            break;
        case IDCMP_RAWKEY:
            printf("IDCMP_RAWKEY\n");
            break;
        case IDCMP_DISKINSERTED:
            printf("IDCMP_DISKINSERTED\n");
            break;
        case IDCMP_DISKREMOVED:
            printf("IDCMP_DISKREMOVED\n");
            break;
        case IDCMP_MOUSEBUTTONS:
            /* the code often contains useful data, such as the ASCII
            ** value (for IDCMP_VANILLAKEY), or the type of button
            ** event here.
            */
            switch (code)
                {
                case SELECTUP:
                    printf("SELECTUP at %d,%d\n",mousex,mousey);
                    break;
                case SELECTDOWN:
                    printf("SELECTDOWN at %d,%d\n",mousex,mousey);
                    break;
                case MENUUP:
                    printf("MENUUP\n");
                    break;
                case MENUDOWN:
                    printf("MENUDOWN\n");
                    break;
                default:
                    printf("UNKNOWN CODE\n");
                    break;
                }
            break;
        default:
            printf("Unknown IDCMP message\n");
            break;
        }
    }
