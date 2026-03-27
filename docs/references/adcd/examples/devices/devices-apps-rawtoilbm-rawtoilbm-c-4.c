/* Source: ADCD 2.1
 * Section: devices-apps-rawtoilbm-rawtoilbm-c
 * Library: devices
 * ADCD reference: devices/devices-apps-rawtoilbm-rawtoilbm-c.md
 */

    {
    if(s&&(*s)) printf("%s\n",s);
    if ((fromWB)&&(*s))    /* Wait so user can read messages */
        {
        printf("\nPRESS RETURN TO EXIT\n");
        while(getchar() != '\n');
        }
    cleanup();
    exit(e);
    }
