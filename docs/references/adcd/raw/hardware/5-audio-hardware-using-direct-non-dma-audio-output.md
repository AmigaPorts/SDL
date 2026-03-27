# 5 Audio Hardware / Using Direct (Non-DMA) Audio Output


It is possible to create sound by writing audio data one word at a time to
the audio output addresses, instead of setting up a list of audio data in
memory. This method of controlling the output is more processor-intensive
and is therefore not recommended.

To use direct audio output, do not enable the DMA for the audio channel
you wish to use; this changes the timing of the  [interrupts](../Hardware_Manual_guide/node016B.html) . The normal
 [interrupt](../Hardware_Manual_guide/node016B.html)  occurs after a data address has been read; in direct audio
output, the  [interrupt](../Hardware_Manual_guide/node016B.html)  occurs after one data word has been output.

Unlike in the DMA-controlled automatic data output, in direct audio
output, if you do not write a new set of data to the output addresses
before two sampling intervals have elapsed, the audio output will cease
changing. The last value remains as an output of the
 [digital-to-analog converter](../Hardware_Manual_guide/node00D6.html#line68) .

The  [volume](../Hardware_Manual_guide/node00DC.html)  and  [period registers](../Hardware_Manual_guide/node00DF.html#line34)  are set as usual.

