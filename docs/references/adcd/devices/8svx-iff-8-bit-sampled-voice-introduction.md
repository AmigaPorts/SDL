---
title: 8SVX IFF 8-Bit Sampled Voice / Introduction
manual: devices
chapter: devices
section: 8svx-iff-8-bit-sampled-voice-introduction
functions: []
libraries: []
---

# 8SVX IFF 8-Bit Sampled Voice / Introduction

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This is the IFF supplement for FORM "8SVX".  An 8SVX is an IFF "data
section" or "[FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)" (which can be an IFF file or a part of one) containing
a digitally sampled audio voice consisting of 8-bit samples.  A voice can
be a one-shot sound or - with repetition and pitch scaling - a musical
instrument.  "[EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md)" is Electronic Arts' standard interchange file
format.  [See [EA IFF 85](devices/a-quick-introduction-to-iff-what-is-iff.md) Standard for Interchange Format Files.]

The 8SVX format is designed for playback hardware that uses 8-bit samples
attenuated by a volume control for good overall signal-to-noise ratio.  So
a FORM 8SVX stores 8-bit samples and a volume level.

A similar data format (or two) will be needed for higher resolution
samples (typically 12 or 16 bits).  Properly converting a high resolution
sample down to 8 bits requires one pass over the data to find the minimum
and maximum values and a second pass to scale each sample into the range
-128 through 127. So it's reasonable to store higher resolution data in a
different [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) type and convert between them.

For instruments, FORM 8SVX can record a repeating waveform optionally
preceded by a startup transient waveform.  These two recorded signals can
be pre-synthesized or sampled from an acoustic instrument.  For many
instruments, this representation is compact.  FORM 8SVX is less practical
for an instrument whose waveform changes from cycle to cycle like a
plucked string, where a long sample is needed for accurate results.

FORM 8SVX can store an "envelope" or "amplitude contour" to enrich musical
notes.  A future voice [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md) could also store amplitude, frequency, and
filter modulations.

FORM 8SVX is geared for relatively simple musical voices, where one
waveform per octave is sufficient, the waveforms for the different octaves
follow a factor-of-two size rule, and one envelope is adequate for all
octaves.  You could store a more general voice as a LIST containing one or
more [FORM](devices/a-quick-introduction-to-iff-what-does-an-iff-file-look-like.md)s 8SVX per octave.  A future voice FORM could go beyond one
"one-shot" waveform and one "repeat" waveform per octave.

Section 2 defines the required property sound header "[VHDR](devices/standard-data-and-property-chunks-required-property-vhdr.md)", optional
properties name "[NAME](devices/standard-data-and-property-chunks-optional-text-chunks.md)", copyright "[(c)](devices/standard-data-and-property-chunks-optional-text-chunks.md)", and author "[AUTH](devices/standard-data-and-property-chunks-optional-text-chunks.md)", the optional
annotation data chunk "[ANNO](devices/standard-data-and-property-chunks-optional-text-chunks.md)", the required data chunk "[BODY](devices/standard-data-and-property-chunks-data-chunk-body.md)", and optional
envelope chunks "[ATAK](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md)" and "[RLSE](devices/standard-data-and-property-chunks-optional-data-chunks-atak.md)".  These are the "standard" chunks.
Specialized chunks for private or future needs can be added later, e.g.,
to hold a frequency contour or Fourier series coefficients.  The 8SVX
syntax is summarized in [Appendix A](devices/8svx-iff-8-bit-sampled-voice-appendix-a-quick-reference.md) as a regular expression and in
[Appendix B](devices/8svx-iff-8-bit-sampled-voice-appendix-b-8svx-example.md) as an example box diagram.  [Appendix C](devices/8svx-iff-8-bit-sampled-voice-appendix-c-fibonacci-delta.md) explains the optional
Fibonacci-delta compression algorithm.

 [Reference](devices/8svx-iff-8-bit-sampled-voice-introduction-reference.md) 

