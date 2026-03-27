/* Source: ADCD 2.1
 * Section: lib-examples-lines-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-lines-c.md
 */

    {
    InitBitMap(bigBitMap, myscreen->BitMap.Depth, WIDTH_SUPER, HEIGHT_SUPER);

    allocatedBitMaps = TRUE;
    for (planeNum = 0;
         (planeNum < myscreen->BitMap.Depth) && (allocatedBitMaps == TRUE);
             planeNum++)
        {
        bigBitMap->Planes[planeNum] = AllocRaster(WIDTH_SUPER, HEIGHT_SUPER);
        if (NULL == bigBitMap->Planes[planeNum])
            allocatedBitMaps = FALSE;
        }

    /* Only open the window if the bitplanes were successfully
    ** allocated.  Fail silently if they were not.
    */
    if (TRUE == allocatedBitMaps)
        {
        /* OpenWindowTags() and OpenWindowTagList() are only available
        ** when the library version is at least V36.  Under earlier
        ** versions of Intuition, use OpenWindow() with a NewWindow
        ** structure.
        */
        if (NULL != (Win = OpenWindowTags(NULL,
                WA_Width,  150,
                WA_Height, 4 * (myscreen->WBorTop + myscreen->Font->ta_YSize + 1),
                WA_MaxWidth,  WIDTH_SUPER,
                WA_MaxHeight, HEIGHT_SUPER,
                WA_IDCMP, IDCMP_GADGETUP | IDCMP_GADGETDOWN |
                    IDCMP_NEWSIZE | IDCMP_INTUITICKS | IDCMP_CLOSEWINDOW,
                WA_Flags, WFLG_SIZEGADGET | WFLG_SIZEBRIGHT | WFLG_SIZEBBOTTOM |
                    WFLG_DRAGBAR | WFLG_DEPTHGADGET | WFLG_CLOSEGADGET |
                    WFLG_SUPER_BITMAP | WFLG_GIMMEZEROZERO | WFLG_NOCAREREFRESH,
                WA_Gadgets, &(SideGad),
                WA_Title, &vers[6], /* take title from version string */
                WA_PubScreen, myscreen,
                WA_SuperBitMap, bigBitMap,
                TAG_DONE)))
            {
            /* set-up the window display */
            SetRast(Win->RPort,0); /* clear the bitplanes */
            SetDrMd(Win->RPort,JAM1);
