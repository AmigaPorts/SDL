/* Source: ADCD 2.1
 * Section: iv-101-dt-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/iv-101-dt-c.md
 */

      {
      if(argc > 1 ) /* CLI only, at least one argument please. */
         {
         /* Attempt to make an 8svx sound object from the file name the user */
         /* specified in the command line.  For a list of possible error     */
         /* returns, see the Autodocs for NewDTObjectA().  The group ID tag  */
         /* will allow only sound datatype files to be accepted for the call.*/
         if (dtobject = NewDTObject(argv[1], DTA_GroupID, GID_SOUND,
                                             TAG_END) )
            {
            mydtt.MethodID     = DTM_TRIGGER; /* Fill in the dtTrigger struct */
            mydtt.dtt_GInfo    = NULL;
            mydtt.dtt_Function = STM_PLAY;
            mydtt.dtt_Data     = NULL;

            /* The return value of the DTM_TRIGGER method used with the 8svx */
            /* sound datatype is undefined in V39.  This is likely to change */
            /* in future versions of the Amiga operating system.             */
            dores = DoDTMethodA(dtobject, NULL, NULL, &mydtt);

            /* Let the 8svx sound finish playing.  Currently (V39) there is  */
            /* no programmatic way to find out when it is finished playing.  */
            Wait(SIGBREAKF_CTRL_C);

            DisposeDTObject(dtobject);
            }
         else printf("Couldn't create new object or not a sound data file\n");

         }
      else printf("Give a file name too.\n");

      CloseLibrary(DataTypesBase);
      }
