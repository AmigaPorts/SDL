/* Source: ADCD 2.1
 * Section: lib-examples-doublebuffer-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-doublebuffer-c.md
 */

    {
    /* Calculate a position to place the object, these
    ** calculations insure the object will stay on the screen
    ** given the range of ktr and the size of the object.
    */
    xpos = ktr;
    if ((ktr % 100) >= 50)
        ypos = 50 - (ktr % 50);
    else
        ypos = ktr % 50;

    /* switch the bitmap so that we are drawing into the correct place */
    screen->RastPort.BitMap          = myBitMaps[toggleFrame];
    screen->ViewPort.RasInfo->BitMap = myBitMaps[toggleFrame];

    /* Draw the objects.
    ** Here we clear the old frame and draw a simple filled rectangle.
    */
    SetRast(&(screen->RastPort), 0);
    RectFill(&(screen->RastPort), xpos, ypos, xpos+100, ypos+100);

    /* update the physical display to match the newly drawn bitmap. */
    MakeScreen(screen); /* Tell intuition to do its stuff.          */
    RethinkDisplay();   /* Intuition compatible MrgCop & LoadView   */
                        /*               it also does a WaitTOF().  */

    /* switch the frame number for next time through */
    toggleFrame ^= 1;
    }
