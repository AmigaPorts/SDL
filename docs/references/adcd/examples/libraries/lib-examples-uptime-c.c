/* Source: ADCD 2.1
 * Section: lib-examples-uptime-c
 * Library: libraries
 * ADCD reference: libraries/lib-examples-uptime-c.md
 */

    /* Uses SAS C getreg() */

    #include <exec/types.h>
    #include <exec/memory.h>
    #include <dos/dos.h>
    #include <dos/dosextens.h>
    #include <dos/datetime.h>
    #include <utility/date.h>
    #include <dos.h>

    #include <clib/exec_protos.h>
    #include <clib/dos_protos.h>
    #include <clib/utility_protos.h>

    #include <stdlib.h>

    struct Library *UtilityBase;

    LONG main(void);

    LONG main(void)
    {
      struct InfoData *infodata;
      struct DeviceList *ramdevice;
      struct DateStamp *now;
      LONG currenttime, boottime;
      BPTR lock;
      LONG vargs[3];
      LONG rc = RETURN_FAIL;

      /* Fails silently if < 37 */
      if (UtilityBase = OpenLibrary("utility.library", 37))
      {
        if (infodata = AllocMem(sizeof(struct InfoData), MEMF_CLEAR))
        {
          if (now = AllocMem(sizeof(struct DateStamp), MEMF_CLEAR))
          {
            if (lock = Lock("RAM:", SHARED_LOCK))
            {
              if ((Info(lock, infodata)) == DOSTRUE)
              {
                /* Make C pointer */

                ramdevice = BADDR(infodata->id_VolumeNode);

                boottime = SMult32(ramdevice->dl_VolumeDate.ds_Days, 86400) +
                           SMult32(ramdevice->dl_VolumeDate.ds_Minute, 60) +
                           SDivMod32(ramdevice->dl_VolumeDate.ds_Tick,
                                     TICKS_PER_SECOND );

                DateStamp(now);

                currenttime = SMult32(now->ds_Days, 86400) +
                              SMult32(now->ds_Minute, 60) +
                              SDivMod32(now->ds_Tick, TICKS_PER_SECOND);

                currenttime -= boottime;

                if (currenttime > 0)
                {
                  vargs[0] = UDivMod32(currenttime, 86400);

                  vargs[1] = getreg(1);
                  vargs[1] = UDivMod32(vargs[1], 3600);

                  vargs[2] =getreg(1);
                  vargs[2] = UDivMod32(vargs[2], 60);

                  /*
                   * Passing the address of the array allows the VPrintf()
                   * function to access the array contents.  Keep in mind
                   * that VPrintf() does _NOT_ know how many elements are
                   * really valid in the final parameter, and will gleefully
                   * run past the valid arguments.
                   */
                  VFPrintf(Output(),
                           "up for %ld days, %ld hours, %ld minutes\n",
                           vargs );

                  rc = RETURN_OK;
                }
              }
              UnLock(lock);
            }
            FreeMem(now, sizeof(struct DateStamp));
          }
          FreeMem(infodata, sizeof(struct InfoData));
        }
        CloseLibrary(UtilityBase);
      }
      exit(rc);
    }
