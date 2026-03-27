---
title: Devices/Dev_examples/Read_BattClock.c
manual: devices
chapter: devices
section: devices-dev-examples-read-battclock-c
functions: [Amiga2Date]
libraries: [utility.library]
---

# Devices/Dev_examples/Read_BattClock.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Read_BattClock.c
 *
 * Example of reading the BattClock and converting its output to
 * a useful measure of time by calling the Amiga2Date() utility function.
 *
 * Compile with SAS C 5.10  lc -b1 -cfistq -v -y -L
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <dos/dos.h>
#include <utility/date.h>
#include <resources/battclock.h>

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/battclock_protos.h>
#include <clib/utility_protos.h>

#include <stdio.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

VOID main(VOID);

struct Library *UtilityBase = NULL;
struct Library *BattClockBase;

VOID main(VOID)
{
UBYTE *Days[] ={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};
UBYTE *Months[] = {"January","February","March","April","May","June",
```c
                   "July","August","September","October","November","December"};
```
UBYTE *ampm;
ULONG AmigaTime;
struct ClockData MyClock;

if (UtilityBase = (struct Library *)OpenLibrary("utility.library",33))

```c
    {
    if (BattClockBase= OpenResource(BATTCLOCKNAME))
        {
        /* Get number of seconds till now */
        AmigaTime = ReadBattClock();

        /* Convert to a ClockData structure */
        Amiga2Date(AmigaTime,&MyClock);

        printf("\nRobin, tell everyone the BatDate and BatTime");

        /* Print the Date */
        printf("\n\nOkay Batman, the BatDate is ");
        printf("%s, %s %d, %d",Days[MyClock.wday],Months[MyClock.month-1],
                               MyClock.mday,MyClock.year);

        /* Convert military time to normal time and set AM/PM */
        if (MyClock.hour < 12)
            ampm = "AM";        /* hour less than 12, must be morning */
        else
            {
            ampm = "PM";         /* hour greater than 12,must be night */
            MyClock.hour -= 12;  /* subtract the extra 12 of military */
            };

        if (MyClock.hour == 0)
            MyClock.hour = 12;   /* don't forget the 12s */

        /* Print the time */
        printf("\n             the BatTime is ");
        printf("%d:%02d:%02d %s\n\n",MyClock.hour,MyClock.min,MyClock.sec,ampm);
        }
    else
       printf("Error: Unable to open the %s\n",BATTCLOCKNAME);

    /* Close the utility library */
    CloseLibrary(UtilityBase);
    }
```
else
```c
    printf("Error: Unable to open utility.library\n");
```
}

---

## See Also

- [Amiga2Date — utility.library](../autodocs/utility.library.md#amiga2date)
