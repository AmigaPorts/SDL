/* Source: ADCD 2.1
 * Section: v-15-cliptext-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-15-cliptext-c.md
 */

    if (myfile = Open((UBYTE *)args[FILE_NAME], MODE_OLDFILE) )   /* Open the file to display. */
    {
      if (DiskfontBase = OpenLibrary("diskfont.library", 37L))          /* Open the libraries. */
      {
        if (IntuitionBase = OpenLibrary("intuition.library", 37L))
        {
          if (GfxBase = OpenLibrary("graphics.library", 37L))
          {
            if (LayersBase = OpenLibrary("layers.library", 37L))
            {
              if (mywin = OpenWindowTags(NULL,                            /* Open that window. */
                     WA_MinWidth,     100,     /* This application wants to hear about three   */
                     WA_MinHeight,    100,     /* things: 1) When the user clicks the window's */
                     WA_SmartRefresh, TRUE,    /* close gadget, 2) when the user starts to     */
                     WA_SizeGadget,   TRUE,    /* resize the window, 3) and when the user has  */
                     WA_CloseGadget,  TRUE,    /* finished resizing the window.                */
                     WA_IDCMP,       IDCMP_CLOSEWINDOW | IDCMP_NEWSIZE | IDCMP_SIZEVERIFY,
                     WA_DragBar,     TRUE,
                     WA_DepthGadget, TRUE,
                     WA_Title,       (ULONG)args[FILE_NAME],
                     TAG_END))
              {
                tagitem[0].ti_Tag = OT_DeviceDPI;

                /* See if there is a non-zero value in the XASP or YASP fields. Diskfont.library */
                /* will get a divide by zero GURU if you give it a zero XDPI or YDPI value.      */

                /* if there is a zero value in one of them... */
                if (  ( (*(ULONG *)args[XASP]) == 0) || ( (*(ULONG *)args[YASP]) == 0)  )
                {
                  /* ...then use the aspect ratio of the current display as a default... */
                  mymodeid = GetVPModeID(&(mywin->WScreen->ViewPort));
                  if (GetDisplayInfoData( NULL, (UBYTE *)&mydi,
                                          sizeof(struct DisplayInfo), DTAG_DISP, mymodeid))
                  {
                    mydefaultXASP = mydi.Resolution.x;
                    mydefaultYASP = mydi.Resolution.y;
                    printf("XAsp = %ld    YAsp = %ld\n", mydefaultXASP, mydefaultYASP);
                    /* Notice that the X and Y get _swapped_ to keep the look of the    */
                    /* font glyphs the same using screens with different aspect ratios. */
                    args[YASP]    = (LONG)&mydefaultXASP;
                    args[XASP]    = (LONG)&mydefaultYASP;
                  }
                  else /* ...unless something is preventing us from getting the screen  */
                       /* screens resolution.  In that case, forget about the DPI tag.  */
                       tagitem[0].ti_Tag = TAG_END;
                }
                /* Here we have to put the X and Y DPI into the OT_DeviceDPI tags data field.  */
                /* THESE ARE NOT REAL X AND Y DPI VALUES FOR THIS FONT OR DISPLAY. They only   */
                /* serve to supply the diskfont.library with values to calculate the aspect    */
                /* ratio.  The X value gets stored in the upper word of the tag value and the Y*/
                /* DPI gets stored in the lower word.  Because ReadArgs() stores the _address_ */
                /* of integers it gets from the command line, you have to dereference the      */
                /* pointer it puts into the argument array, which results in some ugly casting.*/

                tagitem[0].ti_Data = (ULONG)( ( (UWORD) *( (ULONG *)args[XASP] ) << 16) |
                                               ((UWORD) *( (ULONG *)args[YASP]) ) );
                tagitem[1].ti_Tag = TAG_END;

                myta.tta_Name = (STRPTR)args[FONT_NAME];           /* Set up the TTextAttr     */
                myta.tta_YSize = *((LONG *)args[FONT_SIZE]);       /* structure to match the   */
                myta.tta_Style = FSF_TAGGED;                       /* font the user requested. */
                myta.tta_Flags = 0L;
                myta.tta_Tags = tagitem;

                if (myfont = OpenDiskFont(&myta))       /* open that font */
                {
                 /* This is for the layers.library clipping region that gets attached to the   */
                 /* window.  This prevents the application from unnecessarily rendering beyond */
                  myrectangle.MinX = mywin->BorderLeft; /* the bounds of the inner part of     */
                  myrectangle.MinY = mywin->BorderTop;  /* the window.  For now, you can       */
                  myrectangle.MaxX = mywin->Width -     /* ignore the layers stuff if you are  */
                      (mywin->BorderRight + 1);         /* just interested in learning about   */
                  myrectangle.MaxY = mywin->Height -    /* using text.  For more information   */
                      (mywin->BorderBottom + 1);        /* on clipping regions and layers, see */
                                                        /* the Layers chapter of this manual.  */

                  if (new_region = NewRegion())                           /* more layers stuff */
                  {
                    if (OrRectRegion(new_region, &myrectangle));     /* Even more layers stuff */
                    {
                      InstallClipRegion(mywin->WLayer, new_region);
                      /* Obtain a pointer to the window's rastport and set up some of the      */
                      myrp = mywin->RPort;    /* rastport attributes. This example obtains the */
                      SetFont(myrp, myfont);  /* text pen for the window's screen using        */
                      if (mydrawinfo =GetScreenDrawInfo(mywin->WScreen)) /* GetScreenDrawInfo()*/
                      {
                        SetAPen(myrp, mydrawinfo->dri_Pens[TEXTPEN]);
                        FreeScreenDrawInfo(mywin->WScreen, mydrawinfo);
                      }
                      SetDrMd(myrp, (BYTE)(*((LONG *)args[JAM_MODE])));

                      MainLoop();
                    }
                    DisposeRegion(new_region);
                  }
                  CloseFont(myfont);
                }
                CloseWindow(mywin);
              }
              CloseLibrary(LayersBase);
            }
            CloseLibrary(GfxBase);
          }
          CloseLibrary(IntuitionBase);
        }
        CloseLibrary(DiskfontBase);
      }
      Close(myfile);
    }
    FreeArgs(myrda);
