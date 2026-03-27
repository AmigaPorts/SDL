/* Source: ADCD 2.1
 * Section: lib-examples-screen34to37-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-screen34to37-c.md
 */

      /* Fill in the tag list with the minimal pen specification */
      myscreen_tags[0].ti_Tag=SA_Pens;
      myscreen_tags[0].ti_Data=(ULONG) pens;
      myscreen_tags[1].ti_Tag=TAG_DONE;

      /* The screen is opened two bitplanes deep so that the
      ** new look will show-up better.
      **/
      myscreen_setup.LeftEdge=0;
      myscreen_setup.TopEdge=0;
      myscreen_setup.Width=640;              /* Smaller values here reduce   */
      myscreen_setup.Height=STDSCREENHEIGHT; /* drawing area and save memory.*/
      myscreen_setup.Depth=2;                /* Two planes means 4 colors.   */
      myscreen_setup.DetailPen=0;            /* Normal V34 pen colors.       */
      myscreen_setup.BlockPen=1;
      myscreen_setup.ViewModes=HIRES;
      myscreen_setup.Type=CUSTOMSCREEN | NS_EXTENDED; /* Extended NewScreen flag */
      myscreen_setup.Font=NULL;
      myscreen_setup.DefaultTitle="My Screen";
      myscreen_setup.Gadgets=NULL;
      myscreen_setup.CustomBitMap=NULL;
      /* Attach the pen specification tags to the ExtNewScreen structure */
      myscreen_setup.Extension=myscreen_tags;

      if (NULL != (my_screen =
        OpenScreen((struct NewScreen *)&myscreen_setup)));
          {
          /* screen successfully opened */

          Delay(200L);  /* normally the program would be here */

          CloseScreen(my_screen);
          }
      CloseLibrary(IntuitionBase);
