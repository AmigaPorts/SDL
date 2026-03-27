/* Source: ADCD 2.1
 * Section: expansion-library-findconfigdev
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/expansion-library-findconfigdev.md
 */

    /* to find all configdevs of the proper type */
    struct [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) *cd = NULL;

    while( cd = FindConfigDev( cd, MANUFACTURER, PRODUCT ) ) {
            /* do something with the returned [ConfigDev](../Includes_and_Autodocs_2._guide/node00FC.html#line33) */
    }
