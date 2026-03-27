/* Source: ADCD 2.1
 * Section: 29-graphics-library-and-text-what-fonts-are-available
 * Library: libraries
 * ADCD reference: libraries/29-graphics-library-and-text-what-fonts-are-available.md
 */

    afSize = AvailFonts(afh, 0L, AFF_MEMORY|AFF_DISK|AFF_SCALED|
                                                     AFF_TAGGED);
    do
    {
        afh = (struct AvailFontsHeader *) AllocMem(afSize, 0);
        if (afh)
        {
            afShortage = AvailFonts(afh, afSize, AFF_MEMORY|AFF_DISK|
                                                 AFF_SCALED|AFF_TAGGED);
            if (afShortage)
            {
                FreeMem(afh, afSize);
                afSize += afShortage;
            }
        }
        else
        {
            fail("AllocMem of AvailFonts buffer afh failed\n");
            break;
        }
    } while (afShortage); /* if (afh) non-zero here, then:             */
                          /* 1. it points to a valid AvailFontsHeader, */
                          /* 2. it must have FreeMem(afh, afSize)      */
                          /* called for it after use. */
