---
title: A / IFF Third Party Public Form & Chunk Specification / 8SVXSEQN.FADE.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-chunk-specification-8svxseqn
functions: []
libraries: []
---

# A / IFF Third Party Public Form & Chunk Specification / 8SVXSEQN.FADE.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Looping chunks for 8SVX form


                          SEQN and FADE Chunks

       Multiple Loop Sequencing in the '8SVX' IFF 8-bit Sample Voice
       -------------------------------------------------------------
           Registered by Peter Norman, RamScan Software Pty Ltd.
Sound samples are notorious for demanding huge amounts of memory.

While earlier uses of digital sound on the Amiga were mainly in the form
of short looping waveforms for use as musical instruments, many people
today wish to record several seconds (even minutes) of sound. This of
course eats memory.

Assuming that quite often the content of these recordings is music, and
that quite often music contains several passages which repeat at given
times, "verse1 .. chorus ..  verse2 .. chorus .." etc, a useful extention
has been added to the 8SVX list of optional data chunks. It's purpose is
to conserve memory by having the computer repeat sections rather than
having several instances of a similar sound or musical passage taking up
valuable sample space.

The 'SEQN' chunk has been created to define "Multiple" loops or sections
within a single octave 8SVX MONO or STEREO waveform.

It is intended that a sampled sound player program which supports this
chunk will play sections of the waveform sequentially in an order that the
SEQN chunk specifies. This means for example, if an identical chorus
repeats throughout a recording, rather than have this chorus stored
several times along the waveform, it is only necessary to have one copy of
the chorus stored in the waveform.

A "SEQeNce" of definitions can then be set up to have the computer loop
back and repeat the chorus at the required time. The remaining choruses
stored in the waveform will no longer be necessary and can be removed.

E.g., if we had a recording of the following example, we would find that
there are several parts which simply repeat. Substantial savings can be
made by having the computer repeat sections rather than have them stored
in memory.

 [EXAMPLE](devices/8svxseqn-fade-doc-example.md) 
 [Chunk Definitions](devices/8svxseqn-fade-doc-chunk-definitions.md) 

