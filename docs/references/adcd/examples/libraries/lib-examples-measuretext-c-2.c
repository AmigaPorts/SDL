/* Source: ADCD 2.1
 * Section: lib-examples-measuretext-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-measuretext-c.md
 */

    count = 0;


    while(count < actual)
    {
      crrts = 0;

      while ( ((buffer[count] < myfont->tf_LoChar) ||    /* skip non-printable characters, but */
               (buffer[count] > myfont->tf_HiChar)) &&   /* account for newline characters.    */
               (count < actual) )
      {
        if (buffer[count] == '\012') crrts++; /* is this character a newline?  if it is, bump */
        count++;                               /* up the newline count.                        */
      }

      if (crrts > 0)                  /* if there where any newlines, be sure to display them. */
      {
        Move(myrp, w->BorderLeft, myrp->cp_y + (crrts * (myfont->tf_YSize + 1)));
        EOP();                                          /* did we go past the end of the page? */
      }

      printable = count;
      while ( (buffer[printable] >= myfont->tf_LoChar) &&      /* find the next non-printables */
              (buffer[printable] <= myfont->tf_HiChar) &&
              (printable < actual) )
      {
        printable++;
      }                                  /* print the string of printable characters wrapping  */
      while (count < printable)          /* lines to the beginning of the next line as needed. */
      {
        /* how many characters in the current string of printable characters will fit */
        /* between the rastport's current X position and the edge of the window?      */
        fit = TextFit(  myrp,                &(buffer[count]),
                        (printable - count), &resulttextent,
                        NULL,                1,
                        (w->Width  - (myrp->cp_x + w->BorderLeft + w->BorderRight)),
                        myfont->tf_YSize + 1  );
        if ( fit == 0 )
        {
            /* nothing else fits on this line, need to wrap to the next line.         */
            Move(myrp, w->BorderLeft, myrp->cp_y + myfont->tf_YSize + 1);
        }
        else
        {
           Text(myrp, &(buffer[count]), fit);
           count += fit;
        }
        EOP();
      }

      if (mytask->tc_SigRecvd & SIGBREAKF_CTRL_C)        /* did the user hit CTRL-C (the shell */
      {                                                  /* window has to receive the CTRL-C)? */
        aok = FALSE;
        VPrintf("Ctrl-C Break\n", NULL);
        count = BUFSIZE + 1;
      }
    }
