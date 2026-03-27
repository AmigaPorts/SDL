/* Source: ADCD 2.1
 * Section: lib-examples-displayalert-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-displayalert-c.md
 */

    {
    if (DisplayAlert(RECOVERY_ALERT, alertMsg, 52))
        printf("Alert returned TRUE\n");
    else
        printf("Alert returned FALSE\n");

    CloseLibrary(IntuitionBase);
    }
