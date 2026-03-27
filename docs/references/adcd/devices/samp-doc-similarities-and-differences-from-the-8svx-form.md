---
title: SAMP.doc / Similarities and Differences from the 8SVX Form
manual: devices
chapter: devices
section: samp-doc-similarities-and-differences-from-the-8svx-form
functions: []
libraries: []
---

# SAMP.doc / Similarities and Differences from the 8SVX Form

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Like "8SVX", this new format uses headers to separate the various sections
of the sound file into chunks. Some of the chunks are exactly the same
since there wasn't a need to improve them. The chunks that remain
unchanged are as follows:

   "(c) "
   "AUTH"
   "ANNO"

Since these properties are all described in the original "8SVX" document,
please refer to that for a description of these chunks and their uses.
Like the "8SVX" form, none of these chunks are required to be in a sound
file. If they do appear, they must be padded out to an even number of
bytes.

Furthermore, two "8SVX" chunks no longer exist as they have been incorpo-
rated into the "BODY" chunk. They are:

   "ATAK"
   "RLSE"

Since each wave can be completely different than the other waves in the
sound file (one wave might be middle C on a piano, and another might be a
snare drum hit), it is necessary for each wave to have its own envelope
description, and name.

The major changes from the "8SVX" format are in the "MHDR", "NAME", and
"BODY" chunks.

