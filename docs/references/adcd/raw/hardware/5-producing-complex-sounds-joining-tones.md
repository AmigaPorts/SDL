# 5 / Producing Complex Sounds / Joining Tones


Tones are joined by writing the  [location](../Hardware_Manual_guide/node00DB.html)  and  [length registers](../Hardware_Manual_guide/node00DB.html#line26) ,
starting the audio output, and rewriting the registers in preparation for
the next audio waveform that you wish to connect to the first one. This is
made easy by the timing of the  [audio interrupts](../Hardware_Manual_guide/node016B.html)  and the existence of
back-up registers. The  [location](../Hardware_Manual_guide/node00DB.html)  and  [length registers](../Hardware_Manual_guide/node00DB.html#line26)  are read by the
DMA channel before audio output begins. The DMA channel then stores the
values in back-up registers.

Once the original registers have been read by the DMA channel, you can
change their values without disturbing the operation you started with the
original register contents. Thus, you can write the contents of these
registers, start an audio output, and then rewrite the registers in
preparation for the next waveform you want to connect to this one.

 [Interrupts](../Hardware_Manual_guide/node016B.html)  occur immediately after the audio DMA channel has read the
 [location](../Hardware_Manual_guide/node00DB.html)  and  [length registers](../Hardware_Manual_guide/node00DB.html#line26)  and stored their values in the back-up
registers. Once the  [interrupt](../Hardware_Manual_guide/node016B.html)  has occurred, you can rewrite the
registers with the location and length for the next waveform segment. This
combination of back-up registers and  [interrupt](../Hardware_Manual_guide/node016B.html)  timing lets you keep one
step ahead of the audio DMA channel, allowing your sound output to be
continuous and smooth.

If you do not rewrite the registers, the current waveform will be
repeated. Each time the  [length counter](../Hardware_Manual_guide/node00F2.html#line17)  reaches zero, both the  [location](../Hardware_Manual_guide/node00DB.html) 
and  [length registers](../Hardware_Manual_guide/node00DB.html#line26)  are reloaded with the same values to continue the
audio output.

 [Audio DMA Example](../Hardware_Manual_guide/node00E5.html) 

