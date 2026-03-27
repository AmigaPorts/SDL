# D / Errors / Audio--Corrupted Samples


The bit data for audio samples must be in Chip RAM.  Check your compiler
manual for directives or flags which will place your audio sample data in
Chip RAM.  Or dynamically allocate Chip RAM and copy or load the audio
sample there.

