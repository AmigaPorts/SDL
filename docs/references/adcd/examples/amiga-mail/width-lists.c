/* Source: ADCD 2.1
 * Section: width-lists
 * Library: amiga-mail
 * ADCD reference: amiga-mail/width-lists.md
 */

    if (ObtainInfo(ge, OT_WidthList, &widthlist, TAG_END) == OTERR_Success)
    {
        for (widthentry = (struct GlyphWidthEntry *) widthlist->mlh_Head;
            widthentry->gwe_Node.mln_Succ;
            widthentry = (struct GlyphWidthEntry *)
            widthentry->gwe_Node.mln_Succ)
        {
            printf("$%lx: %ld.%ld\n",
                widthentry->gwe_Code,
                widthentry->gwe_Width>>16,
                ((widthentry->gwe_Width&0xffff)*10000)>>16);
        }
        ReleaseInfo(ge, OT_WidthList, widthlist, TAG_END);
    }
