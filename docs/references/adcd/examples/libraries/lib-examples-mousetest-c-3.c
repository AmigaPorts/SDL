/* Source: ADCD 2.1
 * Section: lib-examples-mousetest-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-mousetest-c.md
 */

    {
    case SELECTDOWN:
        printf("Left Button Down at X%ld Y%ld", msg->MouseX, msg->MouseY);
        if(DoubleClick(tv->LeftSeconds, tv->LeftMicros, msg->Seconds, msg->Micros))
            printf(" DoubleClick!");
        else
            {
            tv->LeftSeconds = msg->Seconds;
            tv->LeftMicros  = msg->Micros;
            tv->RightSeconds = 0;
            tv->RightMicros  = 0;
            }
        break;
    case SELECTUP:
        printf("Left Button Up   at X%ld Y%ld", msg->MouseX, msg->MouseY);
        break;
    case MENUDOWN:
        printf("Right Button down at X%ld Y%ld", msg->MouseX, msg->MouseY);
        if(DoubleClick(tv->RightSeconds, tv->RightMicros, msg->Seconds, msg->Micros))
            printf(" DoubleClick!");
        else
            {
            tv->LeftSeconds = 0;
            tv->LeftMicros  = 0;
            tv->RightSeconds = msg->Seconds;
            tv->RightMicros  = msg->Micros;
            }
        break;
    case MENUUP:
        printf("Right Button Up   at X%ld Y%ld", msg->MouseX, msg->MouseY);
        break;
    }
