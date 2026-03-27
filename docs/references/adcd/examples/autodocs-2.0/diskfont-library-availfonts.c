/* Source: ADCD 2.1
 * Section: diskfont-library-availfonts
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/diskfont-library-availfonts.md
 */

     int afShortage, afSize;
     struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104) *afh;

     ...

     afSize = 400;
     do {
         afh = (struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104) *) AllocMem(afSize, 0);
         if (afh) {
             afShortage = AvailFonts(afh, afSize, AFF_MEMORY|AFF_DISK);
             if (afShortage) {
                 FreeMem(afh, afSize);
                 afSize += afShortage;
             }
         }
         else {
             fail("AllocMem of [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) buffer afh failedn");
             break;
         }
     }
         while (afShortage);

     /*
      * if (afh) non-zero here, then:
      * 1. it points to a valid [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104)
      * 2. it must have FreeMem(afh, afSize) called for it after use
      */
