/* Source: ADCD 2.1
 * Section: devices-dev-examples-full-narrator-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-full-narrator-c.md
 */

     {
     /*
      *  (11)  Begin by breaking the English sentence up into lines of
      *        text in the window.  EngLine is an array containing a
      *        pointer to the start of each English text line.
      */

     English = EngStart[sentence] + strspn((UBYTE *)EngStart[sentence], " ");
     NumEngLines = 0;
     EngLine[NumEngLines++] = English;
     CharsLeft = strlen(English);
     while (CharsLeft > 51)
           {
           for (Offset = 51; *(English+Offset) != ' '; --Offset) ;
           EngBytes[NumEngLines-1] = Offset;
           English                += Offset + 1;
           *(English-1)            = '\0';
           EngLine[NumEngLines++]  = English;
           CharsLeft              -= Offset + 1;
           }
     EngBytes[NumEngLines-1] = CharsLeft;

     /*
      *  (12)   Clear the window and draw in the unhighlighted English text.
      */

     ClearWindow(TextWindow);

     HighLight.FrontPen = 1;
     HighLight.LeftEdge = 10;
     HighLight.TopEdge  = 20;

     for (i = 0; i < NumEngLines; ++i)
          {
          HighLight.IText = EngLine[i];
          PrintIText(TextWindow->RPort, &HighLight, 0, 0);
          HighLight.TopEdge += 10;
          }

     HighLight.TopEdge  = 20;
     HighLight.FrontPen = 3;
     HighLight.IText    = EngLine[0];

     /*
      *  (13)   Set up the write request with the address and length of
      *         the phonetic text to be spoken.  Also tell device to
      *         generate mouth shape changes and word sync events.
      */

     VoiceIO->message.io_Data   = PhonStart[sentence];
     VoiceIO->message.io_Length = strlen(VoiceIO->message.io_Data);
     VoiceIO->flags             = NDF_NEWIORB | NDF_WORDSYNC;
     VoiceIO->mouths            = 1;

    /*
     *  (14)   Send the write request to the device.  This is an
     *         asynchronous write, the device will return immediately.
     */

     SendIO(VoiceIO);

    /*
     *  (15)   Initialize some variables.
     */

     ScreenPos  = 0;
     LineNum    = 0;
     English    = EngLine[LineNum];
     OldEnglish = English;
     MouthIO->voice.message.io_Error = 0;

    /*
     *  (16)   Issue synchronous read requests.  For each request we
     *         check the sync field to see if the read returned a mouth
     *         shape change, a start of word sync event, or both.  We
     *         continue issuing read requests until we get a return code
     *         of ND_NoWrite, which indicates that the write has finished.
     */

     for (DoIO(MouthIO);MouthIO->voice.message.io_Error != ND_NoWrite;DoIO(MouthIO))
          {

          /*
           *  (17)   If bit 1 of the sync field is on, this is a start
           *         of word sync event.  In that case we highlight the
           *         next word.
           */

          if (MouthIO->sync & NDF_READWORD)
              {
              if ((Tempptr = strchr(English, ' ')) != NULL)
                  {
                  English = Tempptr + 1;
                  *(English-1) = '\0';
                  }
              PrintIText(TextWindow->RPort, &HighLight, 0, 0);
              WordLength      = strlen(OldEnglish) + 1;
              HighLight.IText = English;
              OldEnglish      = English;
              ScreenPos      += WordLength;

              if (ScreenPos >= EngBytes[LineNum])
                  {
                  HighLight.LeftEdge   = 10;
                  HighLight.TopEdge   += 10;
                  ScreenPos            = 0;
                  English = OldEnglish = EngLine[++LineNum];
                  HighLight.IText      = English;
                  }
              else
                  HighLight.LeftEdge += 10*WordLength;
              }

          /*
           *  (18)   If bit 0 of the sync field is on, this is a mouth
           *         shape change event.  In that case we update the face.
           */

          if (MouthIO->sync & NDF_READMOUTH)
              UpdateFace();


          }


     /*
      *  (19)   The write has finished (return code from last read equals
      *         ND_NoWrite).  We must wait on the write I/O request to
      *         remove it from the message port.
      */

     WaitIO(VoiceIO);

     }
