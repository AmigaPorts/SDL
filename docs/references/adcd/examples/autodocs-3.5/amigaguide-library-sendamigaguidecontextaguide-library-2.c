/* Source: ADCD 2.1
 * Section: amigaguide-library-sendamigaguidecontextaguide-library
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/amigaguide-library-sendamigaguidecontextaguide-library.md
 */

        struct [IntuiMessage](../Includes_and_Autodocs_3._guide/node05E0.html#line762) *imsg;

        ...

        case RAWKEY:
            switch (imsg->Code)
            {
                case 95:
                    /* bring up help on a particular subject */
                    SendAmigaGuideContext(handle, NULL);
                    break;
                ...
            }
            break;

        ...
