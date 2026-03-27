---
title: 14 / Low-Level Access Commands / Limitations For Synced Reads And Writes
manual: devices
chapter: devices
section: 14-low-level-access-commands-limitations-for-synced-reads
functions: []
libraries: []
---

# 14 / Low-Level Access Commands / Limitations For Synced Reads And Writes

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

There is a delay between the index pulse and the start of bits coming in
from the drive (e.g. dma started). It is in the range of 135-200
microseconds. This delay breaks down as follows: 55 microseconds for
software interrupt overhead (this is the time from interrupt to the write
of the DSKLEN register); 66 microsecs for one horizontal line delay
(remember that disk I/O is synchronized with Agnus' display fetches). The
last variable (0-65 microseconds) is an additional scan line since DSKLEN
is poked anywhere in the horizontal line. This leaves 15 microseconds
unaccounted for. In short, you will almost never get bits within the first
135 microseconds of the index pulse, and may not get it until 200
microseconds. At 4 microsecs/bit, this works out to be between 4 and 7
bytes of user data delay.

   Forewarned is Forearmed.
   ------------------------
   Amiga, Inc. may make enhancements to the disk format in the
   future. Amiga, Inc. intends to provide compatibility within the
   trackdisk device.  Anyone who uses these raw routines is bypassing
   this upward-compatibility and does so at her own risk.

