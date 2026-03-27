/* Source: ADCD 2.1
 * Section: v-23-engine-c
 * Library: amiga-mail
 * ADCD reference: amiga-mail/v-23-engine-c.md
 */

    if (otfile = Open(otagname, MODE_OLDFILE))
    {
      if (ExamineFH(otfile, fib))
      {
        if (returnti = (struct TagItem *) AllocVec(fib->fib_Size, MEMF_CLEAR))
        {
          if (Read(otfile, (UBYTE *) returnti, fib->fib_Size))
          {
            if ((returnti->ti_Tag == OT_FileIdent)               /* Test to see if */
                && (returnti->ti_Data == (ULONG) fib->fib_Size)) /* the OTAG file  */
            {                                                    /* is valid.      */
              tip = returnti;
              while (ti = NextTagItem(&tip))     /* Step through and relocate tags */
              {
                if (ti->ti_Tag & OT_Indirect)
                {
                  ti->ti_Data = (ULONG) returnti + ti->ti_Data;
                }
              }
            }
          }
        }
      }
      Close(otfile);
    }
    FreeDosObject(DOS_FIB, fib);
