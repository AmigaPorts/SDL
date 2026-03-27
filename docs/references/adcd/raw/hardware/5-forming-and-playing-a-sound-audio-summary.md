# 5 / Forming and Playing a Sound / Audio Summary


These are the steps necessary to produce a steady tone:

   1. Define the waveform.
   2. Create the data set containing the pairs of data samples (data
```c
      words). Normally, a data set contains the definition of one
      waveform.
```
   3. Set the location registers:


```c
          [AUDxLCH](../Hardware_Manual_guide/node00DB.html)  (high three bits)
          [AUDxLCL](../Hardware_Manual_guide/node00DB.html)  (low fifteen bits)
```
   4. Set the length register,  [AUDxLEN](../Hardware_Manual_guide/node00DB.html#line26) , to the number of data words to
```c
      be retrieved before starting at the address currently in  [AUDxLC](../Hardware_Manual_guide/node00DA.html#line24) .
```
   5. Set the volume register,  [AUDxVOL](../Hardware_Manual_guide/node00DC.html) .
   6. Set the period register,  [AUDxPER](../Hardware_Manual_guide/node00DF.html#line34) 
   7. Start the audio DMA by writing a 1 into bit 9,  [DMAEN](../Hardware_Manual_guide/node00E0.html#line7)  , along with

```c
      a 1 in the  [SET/CLR](../Hardware_Manual_guide/node0166.html)  bit and a 1 in the position of the  [AUDxEN](../Hardware_Manual_guide/node00E0.html#line7)  bit
      of the channel or channels you want to start.
```
