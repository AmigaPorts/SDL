---
title: cd.device/CD_CONFIG
manual: autodocs-3.5
chapter: autodocs-3.5
section: cd-device-cd-config
functions: [OpenDevice]
libraries: [exec.library]
---

# cd.device/CD_CONFIG

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   NAME

       CD_CONFIG -- Set drive preferences
   IO REQUEST

```c
       io_Device       preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Unit         preset by the call to [OpenDevice()](autodocs-3.5/cd-device-opendevice.md)
       io_Command      CD_CONFIG
       io_Data         pointer to first entry of TagList
       io_Length       0
```
   RESULTS

```c
       io_Error        0 for success, or an error code as defined in
                       [<devices/cd.h>](autodocs-3.5/include-devices-cd-h.md)
```
   FUNCTION

```c
       This command sets one or more of the configuration items.
       The configuration items are:

       TAGCD_PLAYSPEED                 Default: 75
       TAGCD_READSPEED                 Default: 75 (do not count on this)
       TAGCD_READXLSPEED               Default: 75
       TAGCD_SECTORSIZE                Default: 2048
       TAGCD_XLECC                     Default: 1 (on)
       TAGCD_EJECTRESET                Default: can be 0 (off) or 1 (on)

       The speed settings are described in the number of frames (sectors)
       per second.  All CD-ROM drives are capable of the 75 frames/second
       rate.  Some drives are capable of 150 frames/second, and some even
       more.  To determine the maximum frame rate of the drive, use the
       [CD_INFO](autodocs-3.5/cd-device-cd-info.md) command.  Valid values for caddyless Commodore CD-ROM drives
       are 75 and 150 (normal speed and double speed).  All other values are
       invalid.  You should always make sure the drive is capable of the
       configuration you are requesting by either using the [CD_INFO](autodocs-3.5/cd-device-cd-info.md) command,
       and/or by checking for an error condition after submitting your
       request.

       There are three different types of CD-ROM sectors.  Mode 1 sectors
       (2048 bytes), mode 2 form 1 sectors (2048 bytes), and mode 2 form 2
       sectors (2328 bytes).  Normally, disks are encoded in Mode 1 format.
       Mode 2 form 1 is basically the same as mode 1; however, the mode 2
       form 2 sector format contains no CD-ROM error correction information.
       In order to read information encoded in this sector format, the
       drive's sector size must be configured to 2328 byte sectors.

       Error correction (ECC) of the READXL command can be turned off or
       on with this command.  Error correction can be implemented in either
       hardware or software (depending on the CD-ROM drive).  When ECC is
       implemented in software, CPU usage can become bursty.  Errors rarely
       occur on CDs unless they have numerous scratches, but when they do
       occur, they will cause a loss of CPU bandwith.  When ECC is
       implemented in hardware, no CPU bandwidth is lost -- in this case,
       ECC will always be on no matter how you configure the drive because
       it is free.  The READXL command is used primarily for displaying
       movie-like data.  In this case, speed is essential and data integrety
       is not; however, if the CPU is not being utilized during an XL
       animation there is no need to disable ECC (since the bandwidth is
       there to be used).  The only time ECC should be disabled is when you
       are doing intense calculations in the background of a READXL command,
       AND your program is time-critical.  Do not forget to change this back
       when you are done!

       To make the computer reset when a CD is ejected (for an application
       that does not exit), use the TAGCD_EJECTRESET tag.  When possible,
       titles should be able to exit cleanly back to Workbench.  Error
       conditions should be monitored when doing disk I/O.
```
   EXAMPLE

```c
       /* Configure ReadXL for double-speed reading and turn off ECC when */
       /* the ReadXL command is used.                                     */

       struct [TagItem](autodocs-3.5/include-utility-tagitem-h.md) ConfigList[] = {

           { TAGCD_READXLSPEED, 150 },
           { TAGCD_XLECC,       0   },
           { TAG_END,           0   }
           };

           ior->io_Command = CD_CONFIG;
           ior->io_Data    = (APTR)&ConfigList;
           ior->io_Length  = 0;
           DoIO(ior);

           if (ior->io_Error) printf("Could not be configuredn");
```
   NOTES

```c
       Setting the configuration will not modify the behavior of a read or
       play command already in progress.

       This can be a very dangerous command.  If for instance you set
       TAGCD_SECTORSIZE to 2328, you will no longer be able to read any
       data encoded at 2048 byte sectors (e.g. the file system will not be
       able to read the disk anymore).  After you read any data stored with
       this sector format, you should immediately configure back to the
       original default value (even if the read failed -- the disk could
       be removed in the middle of your read).  You should NEVER use this
       command if you are not the exclusive owner of your disk.
```
   BUGS

```c
       TAG_IGNORE, TAG_MORE, and TAG_SKIP do not work.  Do not use these.

       When switching speeds from single to double (or double to single),
       If the drive is prefetching in single-speed the data you are going
       to use in double-speed, the drive will not switch to double-speed
       (and visa versa).  To avoid this problem, switch to the desired speed,
       begin reading at least 4k into the data (just read two bytes), then
       begin reading at the beginning.  This will force the prefetch buffer
       to clear and issue a new read command with the desired speed.
       (Fixed in 40.24).
```
   SEE ALSO

```c
       [CD_INFO](autodocs-3.5/cd-device-cd-info.md), [<utility/tagitem.h>](autodocs-3.5/include-utility-tagitem-h.md)
```

---

## See Also

- [OpenDevice — exec.library](../autodocs/exec.library.md#opendevice)
