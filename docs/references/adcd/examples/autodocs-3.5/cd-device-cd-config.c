/* Source: ADCD 2.1
 * Section: cd-device-cd-config
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/cd-device-cd-config.md
 */

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
       [CD_INFO](../Includes_and_Autodocs_3._guide/node00A9.html) command.  Valid values for caddyless Commodore CD-ROM drives
       are 75 and 150 (normal speed and double speed).  All other values are
       invalid.  You should always make sure the drive is capable of the
       configuration you are requesting by either using the [CD_INFO](../Includes_and_Autodocs_3._guide/node00A9.html) command,
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
