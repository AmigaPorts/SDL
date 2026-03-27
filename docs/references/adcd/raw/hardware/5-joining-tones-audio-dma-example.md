# 5 / / Joining Tones / Audio DMA Example


This example details the system audio DMA action in a step-by-step
fashion.

Suppose you wanted to join together a sine and a triangle waveform,
end-to-end, for a special audio effect, alternating between them. The
following sequence shows the action of your program as well as its
interaction with the audio DMA system. The example assumes that the
 [period](../Hardware_Manual_guide/node00DD.html) ,  [volume](../Hardware_Manual_guide/node00DC.html) , and  [length](../Hardware_Manual_guide/node00DB.html#line26)  of the data set remains the same for the
sine wave and the triangle wave.


                         Interrupt Program
                         -----------------
If (wave = triangle)

```c
               write  [AUD0LCL](../Hardware_Manual_guide/node00DB.html)  with address of sine wave data.
```
Else if (wave = sine)

```c
               write  [AUD0LCL](../Hardware_Manual_guide/node00DB.html)  with address of triangle wave data.


                          Main Program
                          ------------
```
1. Set up  [volume](../Hardware_Manual_guide/node00DC.html) ,  [period](../Hardware_Manual_guide/node00DD.html) , and  [length](../Hardware_Manual_guide/node00DB.html#line26) .
2. Write  [AUD0LCL](../Hardware_Manual_guide/node00DB.html)  with address of sine wave data.
3. Start DMA.
4. Continue with something else.



                         System Response
                         ---------------
As soon as DMA starts,

   a. Copy to "back-up" length register from  [AUD0LEN](../Hardware_Manual_guide/node00DB.html#line26) .
   b. Copy to "back-up" location register from  [AUD0LCL](../Hardware_Manual_guide/node00DB.html)  (will be used
```c
      as a pointer showing current data word to fetch).
```
   c. Create an  [interrupt](../Hardware_Manual_guide/node016B.html)  for the 680x0 saying that it has completed
```c
      retrieving working copies of  [length](../Hardware_Manual_guide/node00DB.html#line26)  and  [location registers](../Hardware_Manual_guide/node00DB.html) .
```
   d. Start retrieving audio data each allocated DMA time slot.

