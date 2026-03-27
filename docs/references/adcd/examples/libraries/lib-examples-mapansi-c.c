/* Source: ADCD 2.1
 * Section: lib-examples-mapansi-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mapansi-c.md
 */

    UBYTE               *string;
    UBYTE               *tmp1;
    UBYTE               *tmp2;
    UBYTE               iebuffer[6];            /* Space for two dead keys */
                                                /* + 1 key + qualifiers    */
    COUNT               i;
    LONG                rc = 0;


    openall();

    string = ";String converted to input events and sent to input device\n";

    InputEvent->ie_Class = IECLASS_RAWKEY;

    /* Turn each character into an InputEvent */
    tmp1 = string;

    while (*tmp1)
    {
        /* Convert one character, use default key map */
        i = MapANSI(tmp1, 1, iebuffer, 3, NULL);

        /* Make sure we start without deadkeys */
        InputEvent->ie_Prev1DownCode = InputEvent->ie_Prev1DownQual = 0;
        InputEvent->ie_Prev2DownCode = InputEvent->ie_Prev2DownQual = 0;

        tmp2 = iebuffer;

        switch (i)
        {
          case -2:
            printf("Internal error\n", NULL);
            rc = RETURN_FAIL;
            break;

          case -1:
            printf("Overflow\n", NULL);
            rc = RETURN_FAIL;
            break;

          case 0:
            printf("Can't generate code\n", NULL);
            break;

          case 3:
            InputEvent->ie_Prev2DownCode = *tmp2++;
            InputEvent->ie_Prev2DownQual = *tmp2++;
            /* FALL THROUGH */

          case 2:
            InputEvent->ie_Prev1DownCode = *tmp2++;
            InputEvent->ie_Prev1DownQual = *tmp2++;
            /* FALL THROUGH */

          case 1:
            InputEvent->ie_Code = *tmp2++;
            InputEvent->ie_Qualifier = *tmp2;
            break;
        }

        if (rc == RETURN_OK)
        {
            /* Send the key down event */
            AddIEvents(InputEvent);

            /* Create a key up event */
            InputEvent->ie_Code |= IECODE_UP_PREFIX;

            /* Send the key up event */
            AddIEvents(InputEvent);
         }

        if (rc != RETURN_OK)
            break;

        tmp1++;
    }

    closeall();
    exit(rc);
