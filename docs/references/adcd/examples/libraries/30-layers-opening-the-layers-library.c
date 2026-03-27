/* Source: ADCD 2.1
 * Section: 30-layers-opening-the-layers-library
 * Library: libraries
 * ADCD reference: libraries/30-layers-opening-the-layers-library.md
 */

    struct Library *LayersBase;

    if (NULL != (LayersBase = OpenLibrary("layers.library",33L)))
        {
        /* use Layers library */

        CloseLibrary((struct Library *)LayersBase);
        }
