/* Source: ADCD 2.1
 * Section: lib-examples-compleximage-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-compleximage-c.md
 */

    {
    if (NULL != (scr = OpenScreenTags(NULL,
                        SA_Depth,       4,
                        SA_Pens,        &pens,
                        TAG_END)))
        {
        if (NULL != (win = OpenWindowTags(NULL,
                            WA_RMBTrap,      TRUE,
                            WA_CustomScreen, scr,
                            TAG_END)))
            {
            myImage.LeftEdge    = MYIMAGE_LEFT;
            myImage.TopEdge     = MYIMAGE_TOP;
            myImage.Width       = MYIMAGE_WIDTH;
            myImage.Height      = MYIMAGE_HEIGHT;
            myImage.Depth       = MYIMAGE_DEPTH;
            myImage.ImageData   = myImageData;
            myImage.PlanePick   = 0x3;              /* use first two bitplanes */
            myImage.PlaneOnOff  = 0x0;              /* clear all unused planes  */
            myImage.NextImage   = NULL;

            /* Draw the image into the first two bitplanes */
            DrawImage(win->RPort,&myImage,10,10);

            /* Draw the same image at a new location */
            DrawImage(win->RPort,&myImage,100,10);

            /* Change the image to use the second and fourth bitplanes,
            ** PlanePick is 1010 binary or 0xA,
            ** and draw it again at a different location
            */
            myImage.PlanePick = 0xA;
            DrawImage(win->RPort,&myImage,10,50);

            /* Now set all the bits in the first bitplane with PlaneOnOff.
            ** This will make all the bits set in the second bitplane
            ** appear as color 3 (0011 binary), all the bits set in the
            ** fourth bitplane appear as color 9 (1001 binary) and all
            ** other pixels will be color 1 (0001 binary.  If there were
            ** any points in the image where both bits were set, they
            ** would appear as color 11 (1011 binary).
            ** Draw the image at a different location.
            */
            myImage.PlaneOnOff = 0x1;
            DrawImage(win->RPort,&myImage,100,50);

            /* Wait a bit, then quit.
            ** In a real application, this would be an event loop, like the
            ** one described in the Intuition Input and Output Methods chapter.
            */
            Delay(200);

            CloseWindow(win);
            }
        CloseScreen(scr);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
