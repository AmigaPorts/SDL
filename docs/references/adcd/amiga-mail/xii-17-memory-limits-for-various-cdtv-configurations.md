---
title: XII-17: Memory Limits for Various CDTV Configurations
manual: amiga-mail
chapter: amiga-mail
section: xii-17-memory-limits-for-various-cdtv-configurations
functions: [AvailMem]
libraries: [exec.library]
---

# XII-17: Memory Limits for Various CDTV Configurations

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Adam Levin-Delson


RAM space is at a premium in the CDTV, so for the developer who is
creating CDTV titles, it is important to know what the limits of
system memory are.  This is especially true for developers who want
their titles to work on a variety of CDTV/A500 configurations.  To
help assist developers in making titles work on the maximum number of
configurations, the following chart shows a variety of hardware
configurations capable of playing CDTV discs.

For comparison purposes, all machines were allowed to boot far enough
to open the Workbench screen (in the default size) and a CLI/Shell
window.  This represents a reasonable starting point for developers
to estimate if their application will fit into a CDTV's memory (To
properly ascertain the amount of free memory in a particular
CDTV/A500(+) at run time, use the Exec library's AvailMem()
function).  These results are not guaranteed for any particular
configuration, they can and will change depending upon many
variables, including additional hardware, overscan or interlaced
screens, etc.  Use this information only as a guideline.  Do not
assume that these result will remain constant in future releases of
the OS.


    WARNING:
    --------
    A title that consumes too much memory on a current configuration
    may not work in the future if a new release of the OS consumes
    even a little more memory.
Important note about Workbench V1.3 and V 2.0.  Under 1.3, the
Workbench screen and initial CLI always open upon booting with an
AmigaDOS disc.  Under 2.0, the system only opens the Workbench screen
when necessary,  and only opens an initial CLI if the
Startup-sequence attempts to output text.  The C:Avail program first
calculates the amount of free RAM and then prints out the results.
Under 2.0, this means the amount of memory printed by Avail would
differ from the amount of memory actually free by the amount needed
to create the Workbench screen and initial CLI.


             NTSC/ 1.3/
  Machine     PAL  2.0  Peripherals  *  Avail   In-Use  Maximum  Largest
  -------    ----  ---  -----------  -  -----   ------  -------  -------
  CDTV       NTSC  1.3  internal HD  c  799448  240704  1040152  797312
                        floppy
  CDTV       NTSC  1.3  floppy       c  886688  153464  1040152  710472
  CDTV       NTSC  2.0  floppy       c  840616  206936  1047552  689200
  CDTV       NTSC  1.3  SCSI card    c  881248  158904  1040152  704904
  CDTV       NTSC  1.3  floppy       c  878824  161328  1040152  878624
  CDTV       PAL   2.0  floppy       c  807528  239992  1047520  792880
  CDTV       PAL   2.0  none         c  828784  218768  1047552  824736
  CDTV       PAL   1.3  floppy       c  877936  162216  1040152  710552
  CDTV       PAL   1.3  internal HD  c  790488  249664  1040152  788352
                        floppy
  A500/570   NTSC  1.3  internal FD  c  466256  56976   523232   466208
                                     f  412728  104160  516888   412552
                                     t  878984  161136  1040120  466208
  A500/570   PAL   1.3  internal FD  c  457296  65936   523232   457248
                                     f  412704  104184  516888   412064
                                     t  870000  170120  1040120  457248
  A500+/570  PAL   2.0  internal FD  c  809744  237776  1047520  795144
  A500+      PAL   2.0  internal FD  c  839688  207864  1047552  838648
  CDTV       NTSC  1.3  floppy       c  886688  153464  1040152  710472
  CDTV       NTSC  2.0  floppy       c  840616  206936  1047552  689200
  CDTV       NTSC  1.3  SCSI card    c  881248  158904  1040152  704904
  CDTV       NTSC  1.3  floppy       c  878824  161328  1040152  878624
  CDTV       PAL   2.0  floppy       c  807528  239992  1047520  792880
  CDTV       PAL   2.0  none         c  828784  218768  1047552  824736
  CDTV       PAL   1.3  floppy       c  877936  162216  1040152  710552
  A500/570   NTSC  1.3  internal     c  466256  56976   523232   466208
                        floppy       f  412728  104160  516888   412552
                                     t  878984  161136  1040120  466208
  A500/570   PAL   1.3  internal     c  457296  65936   523232   457248
                        floppy       f  412704  104184  516888   412064
                                     t  870000  170120  1040120  457248
  A500+/570  PAL   2.0  internal     c  809744  237776  1047520  795144
                        floppy
  A500+      PAL   2.0  internal     c  839688  207864  1047552  838648


                        floppy
  * c=chip; f=fast; t=total
  FD = Floppy Drive; HD = Hard Drive

---

## See Also

- [AvailMem — exec.library](../autodocs/exec.library.md#availmem)
