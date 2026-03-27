---
title: SAMP.doc / Additional User Data Section
manual: devices
chapter: devices
section: samp-doc-additional-user-data-section
functions: []
libraries: []
---

# SAMP.doc / Additional User Data Section

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There is a provision for storing user data for each wave. This is where an
application can store Amiga hardware info, or other, application specific
info. The waveHeader's USERtype tells what kind of data is stored. The
current types are:

   #define SPECIFIC 0
   #define VOLMOD   1
   #define PERMOD   2
   #define LOOPING  3

   SPECIFIC (0) - application specific data. It should be stored

```c
                  in a format that some application can immediately
                  recognize. (i.e. a "format within" the SAMP format)
                  If the USERtype is SPECIFIC, and an application
                  doesn't find some sort of header that it can re-
                  cognize, it should conclude that this data was
                  put there by "someone else", and ignore the data.
```
   VOLMOD (1) -   This data is for volume modulation of an Amiga

                  channel as described by the ADKCON register. This
                  data will be sent to the modulator channel of the
                  channel set to play the wave.
   PERMOD (2) -   This data is for period modulation of an Amiga

                  channel as described by the ADKCON register. This
                  data will be sent to the modulator channel of the
                  channel set to play the wave.
   LOOPING (3) -  This contains more looping points for the sample.

```c
                  There are some samplers that allow more than just
                  one loop (Casio products primarily). Additional
                  looping info can be stored in this format:

                 UWORD numOfLoops;  /* number of loop points to follow */

                 ULONG StartLoop1,  /* BYTE offset from the beginning of
                                      the sample to the start of loop1 */
                 EndLoop1,          /* BYTE offset from the beginning of
                                      the sample to the end of loop1 */

                 StartLoop2,        /* ...etc */
```
