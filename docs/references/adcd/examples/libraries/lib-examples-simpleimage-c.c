/* Source: ADCD 2.1
 * Section: lib-examples-simpleimage-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-simpleimage-c.md
 */

    {
    if (NULL != (win = OpenWindowTags(NULL,
                        WA_Width,       200,
                        WA_Height,      100,
                        WA_RMBTrap,     TRUE,
                        TAG_END)))
        {
        myImage.LeftEdge    = MYIMAGE_LEFT;
        myImage.TopEdge     = MYIMAGE_TOP;
        myImage.Width       = MYIMAGE_WIDTH;
        myImage.Height      = MYIMAGE_HEIGHT;
        myImage.Depth       = MYIMAGE_DEPTH;
        myImage.ImageData   = myImageData;
        myImage.PlanePick   = 0x1;              /* use first bit-plane     */
        myImage.PlaneOnOff  = 0x0;              /* clear all unused planes */
        myImage.NextImage   = NULL;

        /* Draw the 1 bit-plane image into the first bit-plane (color 1) */
        DrawImage(win->RPort,&myImage,10,10);

        /* Draw the same image at a new location */
        DrawImage(win->RPort,&myImage,100,10);

        /* Wait a bit, then quit.
        ** In a real application, this would be an event loop, like the
        ** one described in the Intuition Input and Output Methods chapter.
        */
        Delay(200);

        CloseWindow(win);
        }
    CloseLibrary((struct Library *)IntuitionBase);
    }
