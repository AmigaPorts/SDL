# 5 / Producing High-quality Sound / Making Waveform Transitions


To avoid unpleasant sounds when you change from one waveform to another,
you need to make the transitions smooth. You can avoid "clicks" by making
sure the waveforms start and end at approximately the same value. You can
avoid "pops" by starting a waveform only at a zero-crossing point. You can
avoid "thumps" by arranging the average  [amplitude](../Hardware_Manual_guide/node00D6.html#line33)  of each wave to be
about the same value. The average  [amplitude](../Hardware_Manual_guide/node00D6.html#line33)  is the sum of the bytes in
the waveform divided by the number of bytes in the waveform.

