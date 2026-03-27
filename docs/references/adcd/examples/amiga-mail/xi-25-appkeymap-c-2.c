/* Source: ADCD 2.1
 * Section: xi-25-appkeymap-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/xi-25-appkeymap-c.md
 */

                                    /* Because we allocated each of our Lo and Hi    */
    rawkeynum = mykeys[i].RawCode;  /* array pairs as sequential memory, we can use  */
                                    /* the RAWKEY values directly  to index into our */
                                    /* sequential Lo/Hi array.                       */

    keymaptypes[rawkeynum] = mykeys[i].MapType;
    keymappings[rawkeynum] = mykeys[i].Map;

    bytenum = rawkeynum >> 3; /* These are for the Capsable + Repeatable bit tables. */
    bitnum = rawkeynum % 8;   /*    Careful--There's only a 1 bit entry per raw key! */

    if (mykeys[i].Capsable)
      capsables[bytenum] |= (1 << bitnum);          /* If capsable, set bit, else... */
    else
      capsables[bytenum] &= (~(1 << bitnum));       /*             ...clear the bit. */

    if (mykeys[i].Repeatable)
      repeatables[bytenum] |= (1 << bitnum);      /* If repeatable, set bit, else... */
    else
      repeatables[bytenum] &= (~(1 << bitnum));   /*               ...clear the bit. */
