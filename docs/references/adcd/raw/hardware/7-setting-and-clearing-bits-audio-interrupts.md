# 7 / / Setting and Clearing Bits / Audio Interrupts


Bits 10 - 7, AUD3 - 0, are assigned to the audio channels. They are called
AUD3, AUD2, AUD1, and AUD0 and are assigned to channels 3, 2, 1, and 0,
respectively.

This  [level 4 interrupt](../Hardware_Manual_guide/node016F.html)  signals "audio block done." When the audio DMA is
operating in  [automatic mode](../Hardware_Manual_guide/node00F2.html#line17) , this interrupt occurs when the last word in
an audio data stream has been accessed. In  [manual mode](../Hardware_Manual_guide/node00EF.html) , it occurs when
the  [audio data register](../Hardware_Manual_guide/node0013.html)  is ready to accept another word of data.

See Chapter 5, "Audio Hardware," for more information about
 [interrupt generation and timing](../Hardware_Manual_guide/node00F2.html) .

