/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    /* get a LayerInfo structure */
    if (NULL != (theLayerInfo = NewLayerInfo()))
        {
        if (NULL != (theColorMap = GetColorMap(4)))
            {
            colorpalette = (UWORD *)theColorMap->ColorTable;
            for(ktr = 0; ktr < 4; ktr++)
                *colorpalette++ = colortable[ktr];

            if (NULL != (theBitMap = allocBitMap(SCREEN_D, SCREEN_W, SCREEN_H)))
                {
                InitView(&theView);
                InitVPort(&theViewPort);

                theView.ViewPort = &theViewPort;

                theViewPort.DWidth   = SCREEN_W;
                theViewPort.DHeight  = SCREEN_H;
                theViewPort.RasInfo  = &theRasInfo;
                theViewPort.ColorMap = theColorMap;

                theRasInfo.BitMap   = theBitMap;
                theRasInfo.RxOffset = 0;
                theRasInfo.RyOffset = 0;
                theRasInfo.Next     = NULL;

                MakeVPort(&theView, &theViewPort);
                MrgCop(&theView);
                LoadView(&theView);
                WaitTOF();

                startLayers(theLayerInfo, theBitMap);

                /* put back the old view, wait for it to become
                ** active before freeing any of our display
                */
                LoadView(oldview);
                WaitTOF();

                /* free dynamically created structures */
                FreeVPortCopLists(&theViewPort);
                FreeCprList(theView.LOFCprList);

                disposeBitMap(theBitMap, SCREEN_D, SCREEN_W, SCREEN_H);
                }
            FreeColorMap(theColorMap);       /* free the color map */
            }
        DisposeLayerInfo(theLayerInfo);
        }
    }
