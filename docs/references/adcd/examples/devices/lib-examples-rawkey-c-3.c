/* Source: ADCD 2.1
 * Section: lib-examples-rawkey-c
 * Library: devices
 * ADCD reference: devices/lib-examples-rawkey-c.md
 */

    /* if high bit set, then this is a key up otherwise this is a key down */
    if (msg->Code & 0x80)
          printf("Key Up:   ");
    else
          printf("Key Down: ");

    print_qualifiers(msg->Qualifier);
    printf(" rawkey #%d maps to %d ASCII character(s)\n", 0x7F & msg->Code, numchars);
    for (char_pos = 0; char_pos < numchars; char_pos++) {
        realc = c = (*buffer)[char_pos];
        if ((c <= 0x1F)||((c >= 0x80)&&(c < 0xa0)))
            c = 0x7f;
        printf("  %3d ($%02x) = %c\n", realc, realc, c);
        }
    }
