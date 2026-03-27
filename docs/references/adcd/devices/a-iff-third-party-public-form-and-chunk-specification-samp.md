---
title: A / IFF Third Party Public Form and Chunk Specification / SAMP.doc
manual: devices
chapter: devices
section: a-iff-third-party-public-form-and-chunk-specification-samp
functions: []
libraries: []
---

# A / IFF Third Party Public Form and Chunk Specification / SAMP.doc

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Sampled sound format


                    IFF FORM "SAMP" Sampled Sound
 Date:   Dec 3,1989
 From:   Jim Fiore and Jeff Glatt, dissidents

The form "SAMP" is a file format used to store sampled sound data in some
ways like the current standard, "8SVX". Unlike "8SVX", this new format is
not restricted to 8 bit sample data. There can be more than one waveform
per octave, and the lengths of different waveforms do not have to be
factors of 2. In fact, the lengths (waveform size) and playback mapping
(which musical notes each waveform will "play") are independently
determined for each wave- form. Furthermore, this format takes into
account the MIDI sample dump stan- dard (the defacto standard for musical
sample storage), while also incorpo- rating the ability to store Amiga
specific info (for example, the sample data that might be sent to an audio
channel which is modulating another channel).

Although this form can be used to store "sound effects" (typically oneShot
sounds played at a set pitch), it is primarily intended to correct the
many deficiencies of the "8SVX" form in regards to musical sampling.
Because the emphasis is on musical sampling, this format relies on the
MIDI (Musical Instrument Digital Interface) method of describing "sound
events" as does virtually all currently manufactured, musical samplers. In
addition, it at- tempts to incorporate features found on many professional
music samplers, in anticipation that future Amiga models will implement 16
bit sampling, and thus be able to achieve this level of performance.
Because this format is more complex than "8SVX", programming examples to
demonstrate the use of this format have been included in both C and
assembly. Also, a library of func- tions to read and write SAMP files is
available, with example applications.

SEMANTICS: When MIDI literature talks about a sample, usually it means a
collection of many sample points that make up what we call a "wave".

 [Similarities and Differences from the 8SVX Form](devices/samp-doc-similarities-and-differences-from-the-8svx-form.md) 
 [The SAMP Header](devices/samp-doc-the-samp-header.md) 
 [The MHDR Chunk](devices/samp-doc-the-mhdr-chunk.md) 
 [The NAME Chunk](devices/samp-doc-the-name-chunk.md) 
 [The BODY Chunk](devices/samp-doc-the-body-chunk.md) 
 [Structure of an Individual Sample Point](devices/samp-doc-structure-of-an-individual-sample-point.md) 
 [The Waveheader Explained](devices/samp-doc-the-waveheader-explained.md) 
 [MIDI Velocity vs. Amiga Channel Volume](devices/samp-doc-midi-velocity-vs-amiga-channel-volume.md) 
 [An EGpoint (Envelope Generator)](devices/samp-doc-an-egpoint-envelope-generator.md) 
 [Additional User Data Section](devices/samp-doc-additional-user-data-section.md) 
 [Converting Midi Sample Dump to SAMP](devices/samp-doc-converting-midi-sample-dump-to-samp.md) 
 [Interpreting the Playmode](devices/samp-doc-interpreting-the-playmode.md) 
 [Making A Transpose Table](devices/samp-doc-making-a-transpose-table.md) 
 [Making the Velocity Table](devices/samp-doc-making-the-velocity-table.md) 
 [The Instrument Type](devices/samp-doc-the-instrument-type.md) 
 [The Order of the Chunks](devices/samp-doc-the-order-of-the-chunks.md) 
 [Filename Conventions](devices/samp-doc-filename-conventions.md) 
 [Why Does Anyone Need Such a Complicated File?](devices/samp-doc-why-does-anyone-need-such-a-complicated-file.md) 

