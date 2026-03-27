/* Source: ADCD 2.1
 * Section: devices-dev-examples-audio-8svx-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-audio-8svx-c.md
 */

    {
    length[y]-=102400;                    /* It's a real long sample so  */
    AIOptr1->ioa_Length=51200L;           /* double buffering is needed  */
    AIOptr2->ioa_Length=51200L;
    BeginIO((struct IORequest *)AIOptr1); /* Start up the first 2 blocks */
    BeginIO((struct IORequest *)AIOptr2);
    Aptr=AIOptr1;
    port=port1;                           /* Set the switch... */

    while(length[y]>0)
      {                                   /* Wait() for one IO to finish */
      wakebit=Wait(1 << port->mp_SigBit); /* reuse the IO block & queue  */
      while((msg=GetMsg(port))==0){};     /* it up again while the 2nd IO*/
                                          /* block plays.Switch & repeat */
      /* Set length of next IO block */
      if (length[y]<=51200)
          Aptr->ioa_Length=length[y];
      else
          Aptr->ioa_Length=51200L;

      /* Copy sample fragment from read buffer to chip memory */
      CopyMem(psample[y],Aptr->ioa_Data,Aptr->ioa_Length);

      /* Adjust size and pointer of read buffer*/
      length[y]-=Aptr->ioa_Length;
      psample[y]+=51200;

      BeginIO((struct IORequest *)Aptr);

      if (Aptr==AIOptr1)
          {
          Aptr=AIOptr2;                /* This logic handles switching  */
          port=port2;                  /* between the 2 IO blocks and   */
          }                            /* the 2 ports we are using.     */
      else
          {
          Aptr=AIOptr1;
          port=port1;
          }
      }

    /*-------------------------------------------------*/
    /* OK we are at the end of the sample so just wait */
    /* for the last two parts of the sample to finish  */
    /*-------------------------------------------------*/
    wakebit=Wait(1 << port->mp_SigBit);
    while((msg=GetMsg(port))==0){};
    if (Aptr==AIOptr1)
        {
        Aptr=AIOptr2;                  /* This logic handles switching  */
        port=port2;                    /* between the 2 IO blocks and   */
        }                              /* the 2 ports we are using.     */
    else
        {
        Aptr=AIOptr1;
        port=port1;
        }
    wakebit=Wait(1 << port->mp_SigBit);
    while((msg=GetMsg(port))==0){};
    }
