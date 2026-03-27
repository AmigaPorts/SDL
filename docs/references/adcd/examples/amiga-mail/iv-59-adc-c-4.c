/* Source: ADCD 2.1
 * Section: iv-59-adc-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-59-adc-c.md
 */

    int i;

    for (i = 0; i < amicount; ++i)
        if (!RemoveAppMenuItem(amenu[i]))
            warning("ADC: RemoveAppMenuItem failed!");
    amicount = 0;

    if (aicon)
    {
        if (!RemoveAppIcon(aicon))
            warning("ADC: RemoveAppIcon failed!");
        aicon = NULL;
    }

    if (awin)
    {
        if (!RemoveAppWindow(awin))
            warning("ADC: RemoveAppWindow Failed!");
        awin = NULL;
    }
    if (win)
        CloseWindow(win), win = NULL;

    if (aport)
        DeletePort(aport), aport = NULL;

    FreeRemember(&key, TRUE);

    if (GfxBase)        CloseLibrary(GfxBase),       GfxBase = NULL;
    if (IntuitionBase)  CloseLibrary(IntuitionBase), IntuitionBase = NULL;
    if (IconBase)       CloseLibrary(IconBase),      IconBase = NULL;
    if (WorkbenchBase)  CloseLibrary(WorkbenchBase), WorkbenchBase = NULL;

    exit(0);
