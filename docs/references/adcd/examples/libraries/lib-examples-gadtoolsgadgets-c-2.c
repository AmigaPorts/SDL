/* Source: ADCD 2.1
 * Section: lib-examples-gadtoolsgadgets-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-gadtoolsgadgets-c.md
 */

    {
    case 'v':
        /* increase slider level, but not past maximum */
        if (++*slider_level > SLIDER_MAX)
            *slider_level = SLIDER_MAX;
        GT_SetGadgetAttrs(my_gads[MYGAD_SLIDER], win, NULL,
                            GTSL_Level, *slider_level,
                            TAG_END);
        break;
    case 'V':
        /* decrease slider level, but not past minimum */
        if (--*slider_level < SLIDER_MIN)
            *slider_level = SLIDER_MIN;
        GT_SetGadgetAttrs(my_gads[MYGAD_SLIDER], win, NULL,
                            GTSL_Level, *slider_level,
                            TAG_END);
        break;
    case 'c':
    case 'C':
        /* button resets slider to 10 */
        *slider_level = 10;
        GT_SetGadgetAttrs(my_gads[MYGAD_SLIDER], win, NULL,
                            GTSL_Level, *slider_level,
                            TAG_END);
        break;
    case 'f':
    case 'F':
        ActivateGadget(my_gads[MYGAD_STRING1], win, NULL);
        break;
    case 's':
    case 'S':
        ActivateGadget(my_gads[MYGAD_STRING2], win, NULL);
        break;
    case 't':
    case 'T':
        ActivateGadget(my_gads[MYGAD_STRING3], win, NULL);
        break;
    }
