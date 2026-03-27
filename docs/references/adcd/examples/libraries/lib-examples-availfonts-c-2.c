/* Source: ADCD 2.1
 * Section: lib-examples-availfonts-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-availfonts-c.md
 */

    if (aok)
    {
      if (myfont = OpenDiskFont(&(afont->taf_Attr)))
      {
        SetAPen(&myrp, mydrawinfo->dri_Pens[BACKGROUNDPEN]);   /* Print the TextFont attributes. */
        RectFill( &myrp, stringwidth, mywin->BorderTop + 4,
                  mywin->Width - (mywin->BorderRight + 1), myrect.MinY - 2 );

        SetAPen(&myrp, mydrawinfo->dri_Pens[TEXTPEN]);
        Move( &myrp, stringwidth + mywin->BorderLeft,
              mywin->BorderTop + 4 + (myrp.Font->tf_Baseline) );
        Text( &myrp, (UBYTE *)myfont->tf_Message.mn_Node.ln_Name,
              StrLen((UBYTE *)myfont->tf_Message.mn_Node.ln_Name) );

        Move(&myrp, stringwidth + mywin->BorderLeft, myrp.cp_y + fontheight); /* Print the      */
        sprintf(buf, "%d\0", myfont->tf_YSize);                               /* font's Y Size. */
        Text(&myrp, buf, StrLen(buf));

        Move(&myrp, stringwidth + mywin->BorderLeft, myrp.cp_y + fontheight); /* Print the X DPI */
        dpi = GetTagData( TA_DeviceDPI, 0L,
                          ((struct TextFontExtension *)(myfont->tf_Extension))->tfe_Tags);
        if (dpi)
        {
            sprintf(buf, "%d\0", ((dpi & 0xFFFF0000)>>16));
            Text(&myrp, buf, StrLen(buf));
        }
        else Text(&myrp, "nil", 3L);

        Move(&myrp, stringwidth + mywin->BorderLeft, myrp.cp_y + fontheight); /* Print the Y DPI */
        if (dpi)
        {
            sprintf(buf, "%d\0", (dpi & 0x0000FFFF));
            Text(&myrp, buf, StrLen(buf));
        }
        else Text(&myrp, "nil", 3L);

        Move(&myrp, stringwidth + mywin->BorderLeft, myrp.cp_y + fontheight);     /* Print the */
        sprintf(buf, "%d\0", x);                                                   /* entrynum. */
        Text(&myrp, buf, StrLen(buf));

        SetFont(mycliprp, myfont);
        old_region = InstallClipRegion(mywin->WLayer, new_region); /* Install clipping rectangle */

        SetRast(mycliprp, mydrawinfo->dri_Pens[BACKGROUNDPEN]);
        Move( mycliprp, myrect.MinX, myrect.MaxY - (myfont->tf_YSize - myfont->tf_Baseline) );
        Text(mycliprp, alphabetstring, alphabetcharcount);

        Delay(100);

        new_region = InstallClipRegion(mywin->WLayer, old_region);  /* Remove clipping rectangle */

        while (mymsg = (struct IntuiMessage *)GetMsg(mywin->UserPort))
        {
            aok = FALSE;
            x = afh->afh_NumEntries;
            ReplyMsg((struct Message *)mymsg);
        }



        if (mytask->tc_SigRecvd & SIGBREAKF_CTRL_C)        /* Did the user hit CTRL-C (the shell */
        {                                                  /* window has to receive the CTRL-C)? */
            aok = FALSE;
            x = afh->afh_NumEntries;
            VPrintf("Ctrl-C Break\n", NULL);
        }
        CloseFont(myfont);
      }
    }
    afont++;
