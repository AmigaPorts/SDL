# 5 / Forming and Playing a Sound / Stopping the Audio Dma


You can stop the channel by writing a 0 into the  [AUDxEN](../Hardware_Manual_guide/node00E0.html#line7)  bit at any time.
However, you cannot resume the output at the same point in the waveform by
just writing a 1 in the bit again. Enabling an audio channel almost always
starts the data output again from the top of the list of data pointed to
by the  [location registers](../Hardware_Manual_guide/node00DB.html)  for that channel. If the channel is disabled
for a very short time (less than two  [sampling periods](../Hardware_Manual_guide/node00DD.html) ) it may stay on
and thus continue from where it left off.

The following example shows how to stop audio DMA for one channel.

STOPAUDCHAN0:

```c
        LEA     CUSTOM,a0
        MOVE.W  #(DMAF_AUD0),[DMACON](../Hardware_Manual_guide/node0170.html)(a0)
```
