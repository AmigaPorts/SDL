---
title: lib_examples/samplebase.h
manual: libraries
chapter: libraries
section: lib-examples-samplebase-h
functions: []
libraries: []
---

# lib_examples/samplebase.h

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* samplebase.h -- C include file defining sample.library base */

#ifndef SAMPLE_BASE_H
#define SAMPLE_BASE_H

#ifndef  EXEC_TYPES_H
#include  <exec/types.h>
#endif   EXEC_TYPES_H

#ifndef  EXEC_LIBRARIES_H
#include <exec/libraries.h>
#endif   EXEC_LIBRARIES_H

/* library data structures-- Note that the library base begins with a library node */

struct SampleBase {
   struct Library LibNode;
   UBYTE  Flags;
   UBYTE  pad;
   /* We are now longword aligned */
   ULONG  SysLib;
   ULONG  DosLib;
   ULONG  SegList;
   };

#define SAMPLENAME   "sample.library"

#endif  /* SAMPLE_BASE_H */

