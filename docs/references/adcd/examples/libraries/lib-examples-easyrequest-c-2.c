/* Source: ADCD 2.1
 * Section: lib-examples-easyrequest-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-easyrequest-c.md
 */

    {
    /* note in the variable substitution:
    **     the string goes in the first open variable (in body text).
    **     the number goes in the second open (gadget text).
    */
    answer = EasyRequest(NULL, &myES, NULL, "(Variable)", number);

    /* Process the answer.  Note that the buttons are numbered in
    ** a strange order.  This is because the rightmost button is
    ** always a negative reply.  The code can use this if it chooses,
    ** with a construct like:
    **
    **     if (EasyRequest())
    **          positive_response();
    */
    switch (answer)
        {
        case 1:
            printf("selected 'Yes'\n");
            break;
        case 2:
            printf("selected '%ld'\n", number);
            break;
        case 0:
            printf("selected 'No'\n");
            break;
        }

    CloseLibrary(IntuitionBase);
    }
