/* Source: ADCD 2.1
 * Section: keymap-library-mapansi
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/keymap-library-mapansi.md
 */

    ...
    #include [<devices/inputevent.h>](../Includes_and_Autodocs_2._guide/node0051.html)

    #define STIMSIZE        3       /* two dead keys, one key */
    unsigned char rBuffer[STIMSIZE*2];
    ...
        KeymapBase = (struct [Library](../Includes_and_Autodocs_2._guide/node009C.html#line34) *) OpenLibrary("keymap.library", 0);
        ...
        event.ie_NextEvent = 0;
        event.ie_Class = IECLASS_RAWKEY;
        event.ie_SubClass = 0;

        /* prove keymap code completeness and MapANSI reversibility */
        for (code = 0; code < 256; code++) {
            buffer[0] = code;
            actual = MapANSI(buffer, 1, rBuffer, STIMSIZE, 0);
            r = rBuffer;
            event.ie_Prev2DownCode = 0;
            event.ie_Prev2DownQual = 0;
            event.ie_Prev1DownCode = 0;
            event.ie_Prev1DownQual = 0;
            switch (actual) {
                case -2:
                    printf("MapANSI internal error");
                    goto reportChar;
                case -1:
                    printf("MapANSI overflow error");
                    goto reportChar;
                case 0:
                    printf("MapANSI ungeneratable code");
                    goto reportChar;

                case 3:
                    event.ie_Prev2DownCode = *r++;
                    event.ie_Prev2DownQual = *r++;
                case 2:
                    event.ie_Prev1DownCode = *r++;
                    event.ie_Prev1DownQual = *r++;
                case 1:
                    event.ie_Code = *r++;
                    event.ie_Qualifier = *r;

                    actual = MapRawKey(&event, buffer, BUFFERLEN, 0);
                    if ((actual != 1) || (buffer[0] != code)) {
                        printf("MapANSI not reversible");
                        for (i = 0; i < actual; i++)
                            ReportChar(buffer[i]);
                        printf(" from");
    reportChar:
                        ReportChar(code);
                        printf("n");
                    }
            }
        }
    ...
