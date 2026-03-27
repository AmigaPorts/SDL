# 5 / Forming and Playing a Sound / Creating the Waveform Data


The waveform used as an example in this section is a simple sine wave,
which produces a pure tone. To conserve memory, you normally define only
one full cycle of a waveform in memory. For a steady, unchanging sound,
the values at the waveform's beginning and ending points and the trend or
slope of the data at the beginning and end should be closely related. This
ensures that a continuous repetition of the waveform sounds like a
continuous stream of sound.

Sound data is organized as a set of eight-bit data items; each item is a
sample from the waveform. Each data word retrieved for the audio channel
consists of two samples. Sample values can range from -128 to +127.

As an example, the data set shown below produces a close approximation to
a sine wave.

   About the sample data.
   ----------------------
   The data is stored in byte address order with the first digitized
```c
    [amplitude](../Hardware_Manual_guide/node00D6.html#line33)  value at the lowest byte address, the second at the next
```
   byte address, and so on. Also, note that the first byte of data must
   start at a word-address boundary.  This is because the audio DMA
   retrieves one word (16 bits) at a time and uses the sample it reads
   as two bytes of data.

To use audio channel 0, write the address of "audiodata" into AUD0LC,
where the audio data is organized as shown below.  For simplicity,
"AUDxLC" in the table below stands for the combination of the two actual
location registers ( [AUDxLCH and AUDxLCL](../Hardware_Manual_guide/node00DB.html) ).  For the  [audio DMA](../Hardware_Manual_guide/node00F2.html#line17)  channels
to be able to retrieve the data, the data address to which AUD0LC points
must be somewhere in chip RAM.



```c
    Table 5-1: Sample Audio Data Set for Channel 0


     audiodata --->  AUD0LC *        100      98
                     AUD0LC + 2 **    92      83
                     AUD0LC + 4       71      56
                     AUD0LC + 6       38      20
                     AUD0LC + 8        0     -20
                     AUD0LC + 10     -38     -56
                     AUD0LC + 12     -71     -83
                     AUD0LC + 14     -92     -83
                     AUD0LC + 16    -100     -98
                     AUD0LC + 18     -92     -83
                     AUD0LC + 20     -71     -56
                     AUD0LC + 22     -38     -20
                     AUD0LC + 24       0      20
                     AUD0LC + 26      38      56
                     AUD0LC + 28      71      83
                     AUD0LC + 30      92      98
     Notes:
     ------
     * Audio data is located on a word-address boundary.
     ** AUD0LC stands for  [AUD0LCL and AUD0LCH](../Hardware_Manual_guide/node00DB.html) .
```
