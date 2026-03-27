---
title: SAMP.doc / Structure of an Individual Sample Point
manual: devices
chapter: devices
section: samp-doc-structure-of-an-individual-sample-point
functions: []
libraries: []
---

# SAMP.doc / Structure of an Individual Sample Point

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Even though the next generation of computers will probably have 16 bit
audio, and 8 bit sampling will quickly disappear, this spec has sizes
expressed in BYTES. (ie LoopStart, WaveSize, etc.) This is because each
successive address in RAM is a byte to the 68000, and so calculating
address offsets will be much easier with all sizes in BYTES. The Midi
sample dump, on the other hand, has sizes expressed in WORDS. What this
means is that if you have a 16 bit wave, for example, the WaveSize is the
total number of BYTES, not WORDS, in the wave.

Also, there is no facility for storing a compression type. This is because
sample data should be stored in linear format (as per the MIDI spec).
Currently, all music samplers, regardless of their internal method of
playing sample data must transmit and expect to receive sample dumps in a
linear format. It is up to each device to translate the linear format into
its own compression scheme. For example, if you are using an 8 bit
compression scheme that yields a 14 bit linear range, you should convert
each sample data BYTE to a decom- pressed linear WORD when you save a
sound file. Set the MHDR's Format to 14. It is up to the application to do
its own compression upon loading a file. The midi spec was set up this way
because musical samplers need to pass sample data between each other, and
computers (via a midi interface). Since there are almost as many data
compression schemes on the market as there are musical products, it was
decided that all samplers should expect data received over midi to be in
LINEAR format. It seems logical to store it this way on disc as well.
Therefore, any software program "need not know" how to decompress another
software program's SAMP file. When 16 bit sampling is eventually
implemented there won't be much need for compression on playback anyway.
The continuation Flag solves the problem of disc storage as well.

Since the 68000 can only perform math on BYTES, WORDS, or LONGS, it has
been decided that a sample point should be converted to one of these sizes
when saved in SAMP as follows:

 ORIGINAL significant bits          SAMP sample point size
 ­­­­­­­­­­­­­­­­­­­­­­­­­          ­­­­­­­­­­­­­­­­­­­­­­

          8                                 BYTE
          9 to 16                           WORD
          17 to 28                          LONG
Furthermore, the significant bits should be left-justified since it is
easier to perform math on the samples.

So, for example, an 8 bit sample point (like 8SVX) would be saved as a
BYTE with all 8 bits being significant. The MHDR's Format = 8. No
conversion is necessary.

A 12 bit sample point should be stored as a WORD with the significant bits
being numbers 4 to 15. (i.e shift the 12-bit WORD 4 places to the left).
Bits 0, 1, 2 and 3 may be zero (unless some 16-bit math was performed and
you wish to save these results). The MHDR's Format = 12. In this way, the
sample may be loaded and manipulated as a 16-bit wave, but when
transmitted via midi, it can be converted back to 12 bits (rounded and
shifted right by 4).

A 16 bit sample point would be saved as a WORD with all 16 bits being
significant. The MHDR's Format = 16. No conversion is necessary.

