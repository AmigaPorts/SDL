/* Source: ADCD 2.1
 * Section: lib-examples-lines-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-lines-c.md
 */

    {
    case UP_DOWN_GADGET:
        tmp = HEIGHT_SUPER - Win->GZZHeight;
        tmp = tmp * SideGadInfo.VertPot;
        tmp = tmp / MAXPROPVAL;
        dY = tmp - LAYERYOFFSET(Win);
        break;
    case LEFT_RIGHT_GADGET:
        tmp = WIDTH_SUPER - Win->GZZWidth;
        tmp = tmp * BotGadInfo.HorizPot;
        tmp = tmp / MAXPROPVAL;
        dX = tmp - LAYERXOFFSET(Win);
        break;
    }
