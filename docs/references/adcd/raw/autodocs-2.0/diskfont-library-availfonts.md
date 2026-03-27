# diskfont.library/AvailFonts



NAME

```c
     [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) -- Inquire available memory & disk fonts.
```
SYNOPSIS

```c
     error = AvailFonts(buffer, bufBytes, flags);
                        A0      D0        D1

     LONG AvailFonts( struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104) *buffer, LONG bufBytes,
             ULONG flags );
```
FUNCTION

```c
     [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) fills a user supplied buffer with the structure,
     described below, that contains information about all the
     fonts available in memory and/or on disk.  Those fonts
     available on disk need to be loaded into memory and opened
     via [OpenDiskFont](../Includes_and_Autodocs_2._guide/node01F7.html), those already in memory are accessed via
     [OpenFont](../Includes_and_Autodocs_2._guide/node0462.html).  The [TextAttr](../Includes_and_Autodocs_2._guide/node00A8.html#line66) structure required by the open calls
     is part of the information [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) supplies.

     When [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) fails, it returns the number of extra bytes
     it needed to complete the command.  Add this number to your
     current buffer size, allocate a new buffer, and try again.
```
INPUTS

```c
     buffer - memory to be filled with struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104)
             followed by an array of [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) elements, which
             contains entries for the available fonts and their
             names.

     bufBytes - the number of bytes in the buffer
     flags - AFF_MEMORY is set to search memory for fonts to fill
             the structure, AFF_DISK is set to search the disk for
             fonts to fill the structure.  AFF_SCALED is set to
             not filter out memory fonts that are not designed.
             Any combination may be specified.  AFF_TAGGED is set
             to fill the buffer with [TAvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line99) elements instead
             of [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) elements.
```
RESULTS

```c
     buffer - filled with struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104) followed by the
             [T]AvailFonts elements, There will be duplicate entries
             for fonts found both in memory and on disk, differing
             only by type.  The existence of a disk font in the
             buffer indicates that it exists as an entry in a font
             contents file -- the underlying font file has not been
             checked for validity, thus an [OpenDiskFont](../Includes_and_Autodocs_2._guide/node01F7.html) of it may
             fail.
     error - if non-zero, this indicates the number of bytes needed
             for [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) in addition to those supplied.  Thus
             structure elements were not returned because of
             insufficient bufBytes.
```
EXAMPLE

```c
     int afShortage, afSize;
     struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104) *afh;

     ...

     afSize = 400;
     do {
         afh = (struct [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104) *) AllocMem(afSize, 0);
         if (afh) {
             afShortage = AvailFonts(afh, afSize, AFF_MEMORY|AFF_DISK);
             if (afShortage) {
                 FreeMem(afh, afSize);
                 afSize += afShortage;
             }
         }
         else {
             fail("AllocMem of [AvailFonts](../Includes_and_Autodocs_2._guide/node0102.html#line94) buffer afh failedn");
             break;
         }
     }
         while (afShortage);

     /*
      * if (afh) non-zero here, then:
      * 1. it points to a valid [AvailFontsHeader](../Includes_and_Autodocs_2._guide/node0102.html#line104)
      * 2. it must have FreeMem(afh, afSize) called for it after use
      */
```
