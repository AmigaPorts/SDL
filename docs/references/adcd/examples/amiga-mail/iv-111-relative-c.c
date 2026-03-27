/* Source: ADCD 2.1
 * Section: iv-111-relative-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-111-relative-c.md
 */

    if ( IntuitionBase = OpenLibrary("intuition.library",39) )
    {
      if ( customrelclass = initCustomRelClass() )
      {
        if ( gad = NewObject( customrelclass, NULL,
            GA_Left, 20,
            GA_Top, 20,
            GA_Width, 20,
            GA_Height, 20,
            GA_RelVerify, TRUE,
            GA_Immediate, TRUE,
            TAG_DONE ) )
        {
          if ( win = OpenWindowTags( NULL,
              WA_Title, "Custom Relativity Demo",
              WA_CloseGadget, TRUE,
              WA_DepthGadget, TRUE,
              WA_DragBar, TRUE,
              WA_SizeGadget, TRUE,
              WA_Gadgets, gad,
              WA_Activate, TRUE,
              WA_IDCMP, IDCMP_GADGETHELP | IDCMP_RAWKEY | IDCMP_CLOSEWINDOW |
                        IDCMP_GADGETDOWN | IDCMP_GADGETUP,
              WA_Width, 150,
              WA_Height, 150,
              WA_MinWidth, 50,
              WA_MinHeight, 50,
              WA_MaxWidth, ~0,
              WA_MaxHeight, ~0,
              WA_NoCareRefresh, TRUE,
              TAG_DONE ) )
          {
            BOOL terminated = FALSE;
            struct IntuiMessage *imsg;

            /* Turn on Gadget Help */
            HelpControl( win, HC_GADGETHELP );

            while (!terminated)
            {
              Wait (1 << win->UserPort->mp_SigBit);
              while (imsg = (struct IntuiMessage *) GetMsg(win->UserPort))
              {
                switch ( imsg->Class )
                {
                case IDCMP_CLOSEWINDOW:
                  terminated = TRUE;
                  break;

                case IDCMP_RAWKEY:
                  printf("RAWKEY %lx\n", imsg->Code);
                  break;

                case IDCMP_GADGETUP:
                  printf("Gadget Up\n");
                  break;

                case IDCMP_GADGETDOWN:
                  printf("Gadget Down\n");
                  break;

                case IDCMP_GADGETHELP:
                  if ( imsg->IAddress == NULL )
                  {
                    printf("Gadget Help: Mouse not over window\n");
                  }
                  else if ( imsg->IAddress == (APTR) win )
                  {
                    printf("Gadget Help: Mouse in window, not over a gadget\n");
                  }
                  else
                  {
                    /* Detect system gadgets.  Figure out by looking at
                     * system-gadget-type bits in GadgetType field:
                     */
                    LONG sysgtype =
                      ((struct Gadget *)imsg->IAddress)->GadgetType & GTYP_SYSTYPEMASK;
                    switch ( sysgtype )
                    {
                    case GTYP_SIZING:
                      printf("Gadget Help for window sizing gadget\n");
                      break;

                    case GTYP_WDRAGGING:
                      printf("Gadget Help for window drag-bar\n");
                      break;

                    case GTYP_WUPFRONT:
                      printf("Gadget Help for window depth gadget\n");
                      break;

                    case GTYP_WDOWNBACK:
                      printf("Gadget Help for window zoom gadget\n");
                      break;

                    case GTYP_CLOSE:
                      printf("Gadget Help for window close gadget\n");
                      break;

                    case 0:
                      /* In this example, we only have one gadget,
                       * so we know which one it is.  Normally, you'd
                       * have to figure that out here, using the
                       * usual techniques you already use for other
                       * gadget messages.
                       */
                      printf("Gadget Help for gadget, code 0x%x\n",
                          imsg->Code);
                      break;

                    default:
                      printf("Gadget Help on some other system gadget\n");
                      break;
                    }
                  }
                }
                ReplyMsg((struct Message *)imsg);
              }
            }
            CloseWindow( win );
          }
          DisposeObject( gad );
        }
        FreeClass( customrelclass );
      }
      CloseLibrary( IntuitionBase );
    }
    CloseLibrary( GfxBase );
