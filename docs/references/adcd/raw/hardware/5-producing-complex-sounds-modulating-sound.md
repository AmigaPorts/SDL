# 5 / Producing Complex Sounds / Modulating Sound


To provide more complex audio effects, you can use one audio channel to
modulate another. This increases the range and type of effects that can be
produced. You can modulate a channel's frequency or  [amplitude](../Hardware_Manual_guide/node00D6.html#line33) , or do
both types of modulation on a channel at the same time.

 [Amplitude](../Hardware_Manual_guide/node00D6.html#line33)  modulation affects the  [volume](../Hardware_Manual_guide/node00DC.html)  of the waveform. It is often
used to produce vibrato or tremolo effects. Frequency modulation affects
the  [period](../Hardware_Manual_guide/node00DD.html)  of the waveform. Although the basic waveform itself remains
the same, the pitch is increased or decreased by frequency modulation.

The system uses one channel to modulate another when you attach two
channels. The attach bits in the ADKCON register control how the data from
an audio channel is interpreted (see the table below). Normally, each
channel produces sound when it is enabled. If the "attach"  bit for an
audio channel is set, that channel ceases to produce sound and its data is
used to modulate the sound of the next higher-numbered channel. When a
channel is used as a modulator, the words in its data set are no longer
treated as two individual bytes. Instead, they are used as "modulator"
words. The data words from the modulator channel are written into the
corresponding registers of the modulated channel each time the
 [period register](../Hardware_Manual_guide/node00DF.html#line34)  of the modulator channel times out.

To modulate only the  [amplitude](../Hardware_Manual_guide/node00D6.html#line33)  of the audio output, you must attach a
channel as a volume modulator. Define the modulator channel's data set as
a series of words, each containing  [volume](../Hardware_Manual_guide/node00DC.html)  information in the following
format:


                    Bits      Function
                    ----      --------
                    15 - 7    Not used
                    6 - 0     Volume information, V6 - V0
To modulate only the frequency, you must attach a channel as a period
modulator. Define the modulator channel's data set as a series of words,
each containing  [period](../Hardware_Manual_guide/node00DD.html)  information in the following format:


                    Bits      Function
                    ----      --------
                    15 - 0    Period information, P15 - P0
If you want to modulate both  [period](../Hardware_Manual_guide/node00DD.html)  and  [volume](../Hardware_Manual_guide/node00DC.html)  on the same channel,
you need to attach the channel as both a period and volume modulator. For
instance, if channel 0 is used to modulate both the  [period](../Hardware_Manual_guide/node00DD.html)  and frequency
of channel 1, you set two attach bits -- bit 0 to modulate the  [volume](../Hardware_Manual_guide/node00DC.html) 
and bit 4 to modulate the  [period](../Hardware_Manual_guide/node00DD.html) . When  [period](../Hardware_Manual_guide/node00DD.html)  and  [volume](../Hardware_Manual_guide/node00DC.html)  are both
modulated, words in the modulator channel's data set are defined
alternately as  [volume](../Hardware_Manual_guide/node00DC.html)  and  [period](../Hardware_Manual_guide/node00DD.html)  information.

The sample set of data in Table 5-4 shows the differences in
interpretation of data when a channel is used directly for audio, when it
is attached as volume modulator, when it is attached as a period
modulator, and when it is attached as a modulator of both  [volume](../Hardware_Manual_guide/node00DC.html)  and
 [period](../Hardware_Manual_guide/node00DD.html) .


             Table 5-4: Data Interpretation in Attach Mode


           Independent        Modulating
   Data       (not               Both              Modulating  Modulating
   Words   Modulating)      Period and Volume      Period Only Volume Only
   -----   -----------      -----------------      ----------- -----------
   Word 1  |data|data|  |volume for other channel|  |period|    |volume|
   Word 2  |data|data|  |period for other channel|  |period|    |volume|
   Word 3  |data|data|  |volume for other channel|  |period|    |volume|
   Word 4  |data|data|  |period for other channel|  |period|    |volume|


The lengths of the data sets of the modulator and the modulated channels
are completely independent.

Channels are attached by the system in a predetermined order, as shown in
Table 5-5. To attach a channel as a modulator, you set its attach bit to
1. If you set either the  [volume](../Hardware_Manual_guide/node00DC.html)  or  [period](../Hardware_Manual_guide/node00DD.html)  attach bits for a channel,
that channel's audio output will be disabled; the channel will be attached
to the next higher channel, as shown in Table 5-5. Because an attached
channel always modulates the next higher numbered channel, you cannot
attach channel 3. Writing a 1 into channel 3's modulate bits only disables
its audio output.



```c
             Table 5-5: Channel Attachment for Modulation


                        ADKCON Register
                        ---------------
        Bit    Name     Function
        ---    ----     --------
         7    ATPER3    Use audio channel 3 to modulate nothing
                          (disables audio output of channel 3)
         6    ATPER2    Use audio channel 2 to modulate period
                          of channel 3
         5    ATPER1    Use audio channel 1 to modulate period
                          of channel 2
         4    ATPER0    Use audio channel 0 to modulate period
                          of channel 1
         3    ATVOL3    Use audio channel 3 to modulate nothing
                          (disables audio output of channel 3)
         2    ATVOL2    Use audio channel 2 to modulate volume
                          of channel 3
         1    ATVOL1    Use audio channel 1 to modulate volume
                          of channel 2
         0    ATVOL0    Use audio channel 0 to modulate volume
                          of channel 1
```
