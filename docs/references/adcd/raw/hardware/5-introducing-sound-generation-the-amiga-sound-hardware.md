# 5 / Introducing Sound Generation / The Amiga Sound Hardware


The Amiga has four hardware sound channels. You can independently program
each of the channels to produce complex sound effects. You can also attach
channels so that one channel  [modulates](../Hardware_Manual_guide/node00E7.html)  the sound of another or combine
two channels for stereo effects.

Each audio channel includes an eight-bit  [digital-to-analog converter](../Hardware_Manual_guide/node00D6.html#line68) 
driven by a direct memory access (DMA) channel. The audio DMA can retrieve
two data samples during each horizontal video scan line. For simple,
steady tones, the DMA can automatically play a waveform repeatedly; you
can also program all kinds of complex sound effects.

There are two methods of basic sound production on the Amiga -- automatic
(DMA) sound generation and  [direct (non-DMA)](../Hardware_Manual_guide/node00EF.html)  sound generation. When you
use automatic sound generation, the system retrieves data automatically by
direct memory access.

