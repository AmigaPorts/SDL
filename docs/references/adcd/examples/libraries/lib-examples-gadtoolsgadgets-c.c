/* Source: ADCD 2.1
 * Section: lib-examples-gadtoolsgadgets-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-gadtoolsgadgets-c.md
 */

    {
    case MYGAD_SLIDER:
        /* Sliders report their level in the IntuiMessage Code field: */
        printf("Slider at level %ld\n", code);
        *slider_level = code;
        break;
    case MYGAD_STRING1:
        /* String gadgets report GADGETUP's */
        printf("String gadget 1: '%s'.\n",
                ((struct StringInfo *)gad->SpecialInfo)->Buffer);
        break;
    case MYGAD_STRING2:
        /* String gadgets report GADGETUP's */
        printf("String gadget 2: '%s'.\n",
                ((struct StringInfo *)gad->SpecialInfo)->Buffer);
        break;
    case MYGAD_STRING3:
        /* String gadgets report GADGETUP's */
        printf("String gadget 3: '%s'.\n",
                ((struct StringInfo *)gad->SpecialInfo)->Buffer);
        break;
    case MYGAD_BUTTON:
        /* Buttons report GADGETUP's (button resets slider to 10) */
        printf("Button was pressed, slider reset to 10.\n");
        *slider_level = 10;
        GT_SetGadgetAttrs(my_gads[MYGAD_SLIDER], win, NULL,
                            GTSL_Level, *slider_level,
                            TAG_END);
        break;
    }
