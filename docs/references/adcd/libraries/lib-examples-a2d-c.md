---
title: Lib_examples/a2d.c
manual: libraries
chapter: libraries
section: lib-examples-a2d-c
functions: [Amiga2Date, CheckDate, Date2Amiga, GetSysTime]
libraries: [timer.device, utility.library]
---

# Lib_examples/a2d.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* a2d.c - Execute me to compile me with SAS C 5.10
LC -b1 -cfis -j73 a2d.c
Blink FROM LIB:c.o,a2d.o TO a2d LIBRARY LIB:LC.lib,LIB:Amiga.lib
quit
*/

```c
    #include <exec/types.h>
    #include <exec/memory.h>
    #include <dos/datetime.h>
    #include <devices/timer.h>

    #include <clib/exec_protos.h>
    #include <clib/timer_protos.h>
    #include <clib/utility_protos.h>

    #include <stdio.h>

    LONG main(void);

    struct Library *TimerBase;
    struct Library *UtilityBase;

    LONG main(void)
    {
      struct ClockData *clockdata;
      struct timerequest *tr;
      struct timeval *tv;
      LONG seconds;

      if (UtilityBase = OpenLibrary("utility.library", 37))
      {
        if (tr = AllocMem(sizeof(struct timerequest), MEMF_CLEAR))
        {
          if (tv = AllocMem(sizeof(struct timeval), MEMF_CLEAR))
          {
            if (clockdata = AllocMem(sizeof(struct ClockData), MEMF_CLEAR))
            {
              if (!(OpenDevice("timer.device", UNIT_VBLANK, (struct IORequest *)tr, 0) ))
              {
                TimerBase = tr->tr_node.io_Device;

                GetSysTime(tv);

                printf("GetSysTime():\t%d %d\n", tv->tv_secs, tv->tv_micro);

                Amiga2Date(tv->tv_secs, clockdata);

                printf("Amiga2Date():  sec %d min %d hour %d\n", clockdata->sec,
                        clockdata->min, clockdata->hour);

                printf("               mday %d month %d year %d wday %d\n", clockdata->mday,
                       clockdata->month, clockdata->year, clockdata->wday);

                seconds = CheckDate(clockdata);

                printf("CheckDate():\t%ld\n", seconds);

                seconds = Date2Amiga(clockdata);

                printf("Date2Amiga():\t%ld\n", seconds);

                CloseDevice((struct IORequest *)tr);
              }
              FreeMem(clockdata, sizeof(struct ClockData));
            }
            FreeMem(tv, sizeof(struct timeval));
          }
          FreeMem(tr, sizeof(struct timerequest));
        }
        CloseLibrary(UtilityBase);
      }
    }
```

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
- [CheckDate — utility.library](../autodocs/utility.library.md#checkdate)
- [Date2Amiga — utility.library](../autodocs/utility.library.md#date2amiga)
- [GetSysTime — timer.device](../autodocs/timer.device.md#getsystime)
