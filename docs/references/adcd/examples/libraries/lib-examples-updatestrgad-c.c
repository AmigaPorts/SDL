/* Source: ADCD 2.1
 * Section: lib-examples-updatestrgad-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-updatestrgad-c.md
 */

    {
    /* Load a value into the string gadget buffer.
    ** This will be displayed when the gadget is first created.
    */
    strcpy(strBuffer, "START");

    if (win = OpenWindowTags(NULL,
                            WA_Width, 400,
                            WA_Height, 100,
                            WA_Title,"Activate Window, Enter Text",
                            WA_Gadgets, &strGad,
                            WA_CloseGadget, TRUE,
                            WA_IDCMP, IDCMP_ACTIVEWINDOW |
                                IDCMP_CLOSEWINDOW | IDCMP_GADGETUP,
                            TAG_END))
        {
        handleWindow(win,&strGad);

        CloseWindow(win);
        }
    CloseLibrary(IntuitionBase);
    }
