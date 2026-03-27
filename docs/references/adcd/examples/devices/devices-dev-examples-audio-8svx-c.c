/* Source: ADCD 2.1
 * Section: devices-dev-examples-audio-8svx-c
 * Library: devices
 * ADCD reference: devices/devices-dev-examples-audio-8svx-c.md
 */

    {
    AIOptr1->ioa_Length=length[y];         /* No double buffering needed */
    BeginIO((struct IORequest *)AIOptr1);  /* Begin the sample, wait for */
    wakebit=0L;                            /* it to finish, then quit.   */
    wakebit=Wait(1 << port1->mp_SigBit);
    while((msg=GetMsg(port1))==0){};
    }
