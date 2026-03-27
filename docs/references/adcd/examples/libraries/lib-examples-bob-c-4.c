/* Source: ADCD 2.1
 * Section: lib-examples-bob-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-bob-c.md
 */

        {
        if (NULL == (IntuitionBase = (struct IntuitionBase *)OpenLibrary(INTUITIONNAME,37L)))
                return_code = RETURN_FAIL;
        else
                {
                if (NULL == (win = OpenWindow(&myNewWindow)))
                        return_code = RETURN_FAIL;
                else
                        {
                        do_Bob(win);
                        CloseWindow(win);
                        }
                CloseLibrary((struct Library *)IntuitionBase);
                }
        CloseLibrary((struct Library *)GfxBase);
        }
