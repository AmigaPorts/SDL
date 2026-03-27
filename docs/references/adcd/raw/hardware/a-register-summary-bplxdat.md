# A Register Summary / BPLxDAT


                          Agnus/
                  Read/   Denise/
Register Address  Write   Paula         Function
-------- -------  -----   -------       --------
BPLxDAT    110      W       D     Bitplane x data (parallel-to-serial

```c
                                      convert)

                 These registers receive the DMA data fetched from
                 RAM by the bitplane address pointers described
                 above.  They may also be written by either
                 microprocessor.  They act as a six-word parallel-
                 to-serial buffer for up to six memory bitplanes
                 (x=1-6).  The parallel-to-serial conversion is
                 triggered whenever bitplane #1 is written,
                 indicating the completion of all bitplanes for
                 that word (16 pixels).  The MSB is output first,
                 and is, therefore, always on the left.
```
