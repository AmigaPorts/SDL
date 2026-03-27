---
title: Chunk Formats / DLTA Chunk / Format for method 4
manual: devices
chapter: devices
section: chunk-formats-dlta-chunk-format-for-method-4
functions: []
libraries: []
---

# Chunk Formats / DLTA Chunk / Format for method 4

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The DLTA chunk is modified slightly to have 16 long pointers at the start.
The first 8 are as before - pointers to the start of the data for each of
the bitplanes (up to a theoretical max of 8 planes).  The next 8 are
pointers to the start of the offset/numbers data list.  If there is only
one list of offset/numbers for all planes, then the pointer to that list
is repeated in all positions so the playback code need not even be aware
of it.  In fact, one could get fancy and have some bitplanes share lists
while others have different lists, or no lists (the problems in these
schemes lie in the generation, not in the playback).

The best way to show the use of this format is in a sample playback
routine.

   SetDLTAshort(bm,deltaword)
   struct BitMap *bm;
   WORD *deltaword;
   {
```c
      int i;
      LONG *deltadata;
      WORD *ptr,*planeptr;
      register int s,size,nw;
      register WORD *data,*dest;

      deltadata = (LONG *)deltaword;
      nw = bm->BytesPerRow >>1;

      for (i=0;i<bm->Depth;i++) {
         planeptr = (WORD *)(bm->Planes[i]);
         data = deltaword + deltadata[i];
         ptr  = deltaword + deltadata[i+8];
         while (*ptr != 0xFFFF) {
            dest = planeptr + *ptr++;
            size = *ptr++;
            if (size < 0) {
               for (s=size;s<0;s++) {
                  *dest = *data;
                  dest += nw;
               }
               data++;
            }
            else {
               for (s=0;s<size;s++) {
                  *dest = *data++;
                  dest += nw;
               }
            }
         }
      }
      return(0);
```
   }

The above routine is for short word vertical compression with run length
compression.  The most efficient way to support the various options is to
replicate this routine and make alterations for, say, long word or XOR.
The variable nw indicates the number of words to skip to go down the
vertical column.  This one routine could easily handle horizontal
compression by simply setting nw=1.  For ultimate playback speed, the
core, at least, of this routine should be coded in assembly language.

