/* Source: ADCD 2.1
 * Section: 33-controlling-parsing-propchunk-findprop
 * Library: libraries
 * ADCD reference: libraries/33-controlling-parsing-propchunk-findprop.md
 */

    struct StoredProperty *sp;      /* defined in iffparse.h */
    struct BitMapHeader *bmhd;      /* defined in IFF spec   */

    if (sp = FindProp(iff, ID_ILBM, ID_BMHD))
            {
            /* If property is BMHD, sp->sp_Data is ptr to data in BMHD */
            bmhd = (struct BitMapHeader *)sp->sp_Data;
            printf("BMHD: PageWidth      = %ld\n",bmhd->PageWidth);
            }
