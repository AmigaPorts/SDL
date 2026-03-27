# 5 / Forming and Playing a Sound / Selecting the Data Output Rate


The pitch of the sound produced by the waveform depends upon its
frequency. To tell the system what frequency to use, you need to specify
the sampling period. The sampling period specifies the number of system
clock  [ticks](../Hardware_Manual_guide/node00F0.html#line65) , or timing intervals, that should elapse between each sample
(byte of audio data) fed to the  [digital-to-analog converter](../Hardware_Manual_guide/node00D6.html#line68)  in the audio
channel. There is a  [period register](../Hardware_Manual_guide/node00DF.html#line34)  for each audio channel. The value of
the  [period register](../Hardware_Manual_guide/node00DF.html#line34)  is used for count-down purposes; each time the
register counts down to 0, another sample is retrieved from the waveform
data set for output. In units, the period value represents clock ticks per
sample. The minimum period value you should use is 124 ticks per sample
NTSC (123 PAL) and the maximum is 65535. These limits apply to both PAL and
NTSC machines. For high-quality sound, there are other constraints on the
sampling period (see the section called  [Producing High-quality Sound](../Hardware_Manual_guide/node00E8.html) ).

   The period is inversely proportional to the frequency.
   ------------------------------------------------------
   A low period value corresponds to a higher frequency sound and a
   high period value corresponds to a lower frequency sound.

 [Limitations on Selection of Sampling Period](../Hardware_Manual_guide/node00DE.html) 
 [Specifying the Period Value](../Hardware_Manual_guide/node00DF.html) 

