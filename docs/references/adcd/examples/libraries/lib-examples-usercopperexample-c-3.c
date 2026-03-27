/* Source: ADCD 2.1
 * Section: lib-examples-usercopperexample-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-usercopperexample-c.md
 */

        /*  Allocate memory for the Copper list.  */
        /*  Make certain that the initial memory is cleared.  */
        uCopList = (struct UCopList *)
                AllocMem(sizeof(struct UCopList), MEMF_PUBLIC|MEMF_CLEAR);

        if (NULL == uCopList)
                ret_val = ERROR_NO_FREE_STORE;
        else
        {
                /*  Initialize the Copper list buffer.  */
                CINIT(uCopList, NUMCOLORS);

                scanlines_per_color = screen->Height/NUMCOLORS;

                /*  Load in each color.  */
                for (i=0; i<NUMCOLORS; i++)
                        {
                        CWAIT(uCopList, (i*scanlines_per_color), 0);
                        CMOVE(uCopList, custom.color[0], spectrum[i]);
                        }

                CEND(uCopList); /*  End the Copper list  */

                viewPort = ViewPortAddress(window);     /*  Get a pointer to the ViewPort.  */
                Forbid();       /*  Forbid task switching while changing the Copper list.  */
                viewPort->UCopIns=uCopList;
                Permit();       /*  Permit task switching again.  */

                /*  Enable user copper list clipping for this ViewPort.  */
                (VOID) VideoControl( viewPort->ColorMap, uCopTags );

                RethinkDisplay();       /*  Display the new Copper list.  */

                return(ret_val);
        }
