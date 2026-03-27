/* Source: ADCD 2.1
 * Section: lib-examples-menulayout-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-menulayout-c.md
 */

    {
    case 0:      /* Project Menu */
        switch (itemNum)
            {
            case NOITEM: printf("Project Menu\n");        break;
            case 0:      printf("New\n");                 break;
            case 1:      printf("Open\n");                break;
            case 2:      printf("Save\n");                break;
            case 3:      printf("Save As\n");             break;
            case 4:      printf("Print ");
                switch (subNum)
                    {
                    case NOSUB: printf("Item\n");  break;
                    case 0:     printf("NLQ\n");   break;
                    case 1:     printf("Draft\n"); break;
                    }
                break;
            case 5:      printf("About\n");               break;
            case 6:      printf("Quit\n");   done = TRUE; break;
            }
        break;





    case 1:      /* Edit Menu */
        switch (itemNum) {
            case NOITEM: printf("Edit Menu\n"); break;
            case 0:      printf("Cut\n");       break;
            case 1:      printf("Copy\n");      break;
            case 2:      printf("Paste\n");     break;
            case 3:      printf("Erase\n");     break;
            case 4:      printf("Undo\n");      break;
            }
        break;
    case 2:      /* Settings Menu */
        switch (itemNum) {
            case NOITEM: printf("Settings Menu\n"); break;
            case 0:      printf("Sound\n");            break;
            case 1:      printf("Auto Save\n");        break;
            case 2:      printf("Have Your Cake\n");   break;
            case 3:      printf("Eat It Too\n");       break;
            }
        break;
    case NOMENU: /* No menu selected, can happen with IDCMP_MENUHELP */
        printf("no menu\n");
        break;
    }
