/* Source: ADCD 2.1
 * Section: lib-examples-vsprite-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-vsprite-c.md
 */

    {
    if (NULL == (IntuitionBase = (struct IntuitionBase *)OpenLibrary(INTUITIONNAME,37L)))
        return_code = RETURN_FAIL;
    else
        {
        if (NULL == (win = OpenWindow(&myNewWindow)))
            return_code = RETURN_WARN;
        else
            {
            InitRastPort(&myRPort);
            myRPort = win->WScreen->RastPort;       /* Copy the structure. */
            do_VSprite(win, &myRPort);
            CloseWindow(win);
            }
        CloseLibrary((struct Library *)IntuitionBase);
        }
    CloseLibrary((struct Library *)GfxBase);
    }
