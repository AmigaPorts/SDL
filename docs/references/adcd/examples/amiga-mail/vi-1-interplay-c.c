/* Source: ADCD 2.1
 * Section: vi-1-interplay-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/vi-1-interplay-c.md
 */

    {
    /* Get an audio channel at the highest priority */
    if( pIOA_1=SiezeChannel() )
      {
      mport1 = pIOA_1->ioa_Request.io_Message.mn_ReplyPort;
      pIOA_1->ioa_Data = playbuffer1;

      /* Get a 2nd MsgPort and 2nd IOAudio structure for double-buffering */
      pIOA_2 = AllocMem(sizeof(struct IOAudio),MEMF_PUBLIC | MEMF_CLEAR );
      mport2 = CreatePort(0,0);
      if( pIOA_2 && mport2 )
          {
          /* The 2 IOAudio requests should be initialized the same */
          /* except for the buffer and the reply port they use.    */
          *pIOA_2 = *pIOA_1;
          pIOA_2->ioa_Request.io_Message.mn_ReplyPort = mport2;
          pIOA_2->ioa_Data = playbuffer2;

          /* Default is to use interleaving, not averaging */
          mainplay.USE_SUMMING = FALSE;

          /* Parse the 8SVX file and fill in the InterPlay structure */
          errormsg = Parse8svx( argv[1] , &mainplay );

          /* If a second file name was given by the user then this is */
          /* an interleave request, so parse the 2nd 8SVX file.       */
          if( argc>=3 && !errormsg )
              {
              errormsg = Parse8svx( argv[2] , &otherplay );
              mainplay.next_iplay = &otherplay;

              /* If the SUM keyword was given in the command line, set the */
              /* SUMMING flag so that averaging, not interleaving, is used.*/
              if( (argc == 4) &&
                  ( !strcmp(argv[3],"SUM\0") || !strcmp(argv[3],"sum\0") )  )
                  mainplay.USE_SUMMING = TRUE;
              }
          else
              otherplay.sample_done = 1;

          if(!errormsg) /* File names given parsed OK? */
              {
              /* Fill up the buffer for the first request. */
              FillAudio( &mainplay, pIOA_1);

              /* Is there enough data to double-buffer ? */
              if(!mainplay.sample_done || !otherplay.sample_done)
                  {
                  /* OK, enough data to double-buffer; fill up 2nd request */
                  FillAudio( &mainplay, pIOA_2 );
                  BeginIO((struct IORequest *) pIOA_1 );
                  BeginIO((struct IORequest *) pIOA_2 );

                  /* Initial state of double-buffering variables */
                  aswitch=0; pIOA=pIOA_2; mport=mport1;

                  /*---------------------*/
                  /*  M A I N   L O O P  */
                  /*---------------------*/
                  while(!mainplay.sample_done || !otherplay.sample_done)
                      {
                      wakemask=Wait( (1 << mport->mp_SigBit) |
                                               SIGBREAKF_CTRL_C  );

                      if( wakemask & SIGBREAKF_CTRL_C )
                          {
                          otherplay.sample_done = 1;
                          mainplay.sample_done = 1;
                          }

                      while((msg=GetMsg(mport))==NULL){}

                      /* Toggle double-buffering variables */
                      if  (aswitch) {aswitch=0;pIOA=pIOA_2;mport=mport1;}
                      else          {aswitch=1;pIOA=pIOA_1;mport=mport2;}

                      FillAudio( &mainplay, pIOA );
                      BeginIO((struct IORequest *) pIOA );
                      }

                  wakemask=Wait( 1 << mport->mp_SigBit );
                  while((msg=GetMsg(mport))==NULL){}

                  if  (aswitch) {aswitch=0;pIOA=pIOA_2;mport=mport1;}
                  else          {aswitch=1;pIOA=pIOA_1;mport=mport2;}

                  wakemask=Wait( 1 << mport->mp_SigBit );
                  while((msg=GetMsg(mport))==NULL){}
                  }
              else
                  {
                  /* Only enough data to fill up one buffer */
                  BeginIO((struct IORequest *) pIOA_1 );
                  wakemask=Wait( 1 << mport1->mp_SigBit );
                  while((msg=GetMsg(mport1))==NULL){}
                  }
              }
          else
              /* One or the other of the files had a problem in Parse8svx() */
              printf(errormsg);

          /* Free the memory used for the 8SVX files in Parse8svx() */
          if(mainplay.next_iplay)
              EndParse( &otherplay );
          EndParse( &mainplay );

          }
      else printf("Couldn't get memory for a second IOAudio and MsgPort\n");

      /* Free the ports and memory used by the 2 IOAudio requests */
      if(mport2) DeletePort(mport2);
      if(pIOA_2) FreeMem( pIOA_2, sizeof(struct IOAudio) );

      ReleaseChannel(pIOA_1);
      }
    else printf("Couldn't get a channel on the audio device\n");
    }
