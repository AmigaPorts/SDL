/* Source: ADCD 2.1
 * Section: lib-examples-lines-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-lines-c.md
 */

            doDrawStuff();

            /* process the window, return on IDCMP_CLOSEWINDOW */
            doMsgLoop();

            CloseWindow(Win);
            }
        }

    for (planeNum = 0; planeNum < myscreen->BitMap.Depth; planeNum++)
        {
        /* free only the bitplanes actually allocated... */
        if (NULL != bigBitMap->Planes[planeNum])
            FreeRaster(bigBitMap->Planes[planeNum], WIDTH_SUPER, HEIGHT_SUPER);
        }
    FreeMem(bigBitMap,sizeof(struct BitMap));
    }
