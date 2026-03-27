# 8SVX IFF 8-Bit Sampled Voice / Introduction


This is the IFF supplement for FORM "8SVX".  An 8SVX is an IFF "data
section" or "[FORM](../Devices_Manual_guide/node01C7.html#line51)" (which can be an IFF file or a part of one) containing
a digitally sampled audio voice consisting of 8-bit samples.  A voice can
be a one-shot sound or - with repetition and pitch scaling - a musical
instrument.  "[EA IFF 85](../Devices_Manual_guide/node01C5.html)" is Electronic Arts' standard interchange file
format.  [See [EA IFF 85](../Devices_Manual_guide/node01C5.html) Standard for Interchange Format Files.]

The 8SVX format is designed for playback hardware that uses 8-bit samples
attenuated by a volume control for good overall signal-to-noise ratio.  So
a FORM 8SVX stores 8-bit samples and a volume level.

A similar data format (or two) will be needed for higher resolution
samples (typically 12 or 16 bits).  Properly converting a high resolution
sample down to 8 bits requires one pass over the data to find the minimum
and maximum values and a second pass to scale each sample into the range
-128 through 127. So it's reasonable to store higher resolution data in a
different [FORM](../Devices_Manual_guide/node01C7.html#line51) type and convert between them.

For instruments, FORM 8SVX can record a repeating waveform optionally
preceded by a startup transient waveform.  These two recorded signals can
be pre-synthesized or sampled from an acoustic instrument.  For many
instruments, this representation is compact.  FORM 8SVX is less practical
for an instrument whose waveform changes from cycle to cycle like a
plucked string, where a long sample is needed for accurate results.

FORM 8SVX can store an "envelope" or "amplitude contour" to enrich musical
notes.  A future voice [FORM](../Devices_Manual_guide/node01C7.html#line51) could also store amplitude, frequency, and
filter modulations.

FORM 8SVX is geared for relatively simple musical voices, where one
waveform per octave is sufficient, the waveforms for the different octaves
follow a factor-of-two size rule, and one envelope is adequate for all
octaves.  You could store a more general voice as a LIST containing one or
more [FORM](../Devices_Manual_guide/node01C7.html#line51)s 8SVX per octave.  A future voice FORM could go beyond one
"one-shot" waveform and one "repeat" waveform per octave.

Section 2 defines the required property sound header "[VHDR](../Devices_Manual_guide/node02CD.html)", optional
properties name "[NAME](../Devices_Manual_guide/node02CE.html)", copyright "[(c)](../Devices_Manual_guide/node02CE.html)", and author "[AUTH](../Devices_Manual_guide/node02CE.html)", the optional
annotation data chunk "[ANNO](../Devices_Manual_guide/node02CE.html)", the required data chunk "[BODY](../Devices_Manual_guide/node02D0.html)", and optional
envelope chunks "[ATAK](../Devices_Manual_guide/node02CF.html)" and "[RLSE](../Devices_Manual_guide/node02CF.html)".  These are the "standard" chunks.
Specialized chunks for private or future needs can be added later, e.g.,
to hold a frequency contour or Fourier series coefficients.  The 8SVX
syntax is summarized in [Appendix A](../Devices_Manual_guide/node02D2.html) as a regular expression and in
[Appendix B](../Devices_Manual_guide/node02D5.html) as an example box diagram.  [Appendix C](../Devices_Manual_guide/node02D6.html) explains the optional
Fibonacci-delta compression algorithm.

 [Reference](../Devices_Manual_guide/node02CA.html) 

