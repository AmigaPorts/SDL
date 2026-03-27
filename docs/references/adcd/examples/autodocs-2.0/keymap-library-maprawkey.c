/* Source: ADCD 2.1
 * Section: keymap-library-maprawkey
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/keymap-library-maprawkey.md
 */

    ...
    #define BUFFERLEN       80    /* length of longest expected mapping /*
    char buffer[BUFFERLEN];
    struct [InputEvent](../Includes_and_Autodocs_2._guide/node0051.html#line198) ie;
    ...
        KeymapBase = OpenLibrary("keymap.library", 0);
        ...
        ie.ie_Class = IECLASS_RAWKEY;
        ie.ie_SubClass = 0;
        for (;;) {
            WaitPort(window->UserPort);
            while (im = (struct [IntuiMessage](../Includes_and_Autodocs_2._guide/node00D4.html#line679) *) GetMsg(window->UserPort)) {
                switch (im->Class) {
                    case RAWKEY:
                        ie.ie_Code = im->Code;
                        ie.ie_Qualifier = im->Qualifier;
                        /* recover dead key codes & qualifiers */
                        ie.ie_EventAddress = (APTR *) *im->IAddress;
                        actual = MapRawKey(&ie, buffer, BUFFERLEN, 0);
                        for (i = 0; i < actual; i++)
                            ReportChar(buffer[i]);
                        break;
                    ...
                }
                ...
            }
        }
