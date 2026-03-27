/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

            */
            printf("IDCMP_MENUHELP: Help on ");
            processMenus(code,done);
            break;
        case IDCMP_MENUPICK:
            for ( selection = code; selection != MENUNULL;
                  selection = (ItemAddress(FirstMenu,(LONG)selection))->NextSelect)
                {
                printf("IDCMP_MENUPICK: Selected ");
                done = processMenus(selection,done);
                }
            break;
        }
    }
