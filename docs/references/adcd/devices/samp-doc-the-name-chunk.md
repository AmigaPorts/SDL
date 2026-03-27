---
title: SAMP.doc / The NAME Chunk
manual: devices
chapter: devices
section: samp-doc-the-name-chunk
functions: []
libraries: []
---

# SAMP.doc / The NAME Chunk

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

   #define ID_NAME MakeID('N','A','M','E')

If a NAME chunk is included in the file, then EVERY wave must have a name.
Each name is NULL-terminated. The first name is for the first wave, and it
is immediately followed by the second wave's name, etc. It is legal for a
wave's name to be simply a NULL byte. For example, if a file contained 4
waves and a name chunk, the chunk might look like this:


              CNOP 0,2
   Name       dc.b 'NAME'
   sizeOfName dc.l 30

```c
              dc.b 'Snare Drum',0  ;wave 1
              dc.b 'Piano 1',0     ;wave 2
              dc.b 'Piano A4',0    ;wave 3
              dc.b 0               ;wave 4
              dc.b 0
```
NAME chunks should ALWAYS be padded out to an even number of bytes. (Hence
the extra NULL byte in this example). The chunk's size should ALWAYS be
even consequently. DO NOT USE the typical IFF method of padding a chunk
out to an even number of bytes, but allowing an odd number size in the
header.

