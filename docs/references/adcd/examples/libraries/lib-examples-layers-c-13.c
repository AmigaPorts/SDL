/* Source: ADCD 2.1
 * Section: lib-examples-layers-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-layers-c.md
 */

    {
    if (NULL != (LayersBase = OpenLibrary("layers.library",33L)))
        {
        runNewView();

        CloseLibrary((struct Library *)LayersBase);
        }
    CloseLibrary((struct Library *)GfxBase);
    }
