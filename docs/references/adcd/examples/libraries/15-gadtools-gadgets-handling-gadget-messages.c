/* Source: ADCD 2.1
 * Section: 15-gadtools-gadgets-handling-gadget-messages
 * Library: libraries
 * ADCD reference: libraries/15-gadtools-gadgets-handling-gadget-messages.md
 */

    imsg = GT_GetIMsg(win->UserPort);
    object = imsg->IAddress;
    class = imsg->Class;
    code = imsg->Code;
    GT_ReplyIMsg(imsg);
    switch (class)
        {
        case IDCMP_MOUSEMOVE:
            if (object == slidergad)
                {
                printf("Slider at level %ld\n", code);
                }
            ...
            break;
        ...
        }
