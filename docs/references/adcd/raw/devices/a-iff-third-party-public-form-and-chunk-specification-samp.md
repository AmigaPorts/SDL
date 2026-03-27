# A / IFF Third Party Public Form and Chunk Specification / SAMP.doc


Sampled sound format


                    IFF FORM "SAMP" Sampled Sound
 Date:   Dec 3,1989
 From:   Jim Fiore and Jeff Glatt, dissidents

The form "SAMP" is a file format used to store sampled sound data in some
ways like the current standard, "8SVX". Unlike "8SVX", this new format is
not restricted to 8 bit sample data. There can be more than one waveform
per octave, and the lengths of different waveforms do not have to be
factors of 2. In fact, the lengths (waveform size) and playback mapping
(which musical notes each waveform will "play") are independently
determined for each wave- form. Furthermore, this format takes into
account the MIDI sample dump stan- dard (the defacto standard for musical
sample storage), while also incorpo- rating the ability to store Amiga
specific info (for example, the sample data that might be sent to an audio
channel which is modulating another channel).

Although this form can be used to store "sound effects" (typically oneShot
sounds played at a set pitch), it is primarily intended to correct the
many deficiencies of the "8SVX" form in regards to musical sampling.
Because the emphasis is on musical sampling, this format relies on the
MIDI (Musical Instrument Digital Interface) method of describing "sound
events" as does virtually all currently manufactured, musical samplers. In
addition, it at- tempts to incorporate features found on many professional
music samplers, in anticipation that future Amiga models will implement 16
bit sampling, and thus be able to achieve this level of performance.
Because this format is more complex than "8SVX", programming examples to
demonstrate the use of this format have been included in both C and
assembly. Also, a library of func- tions to read and write SAMP files is
available, with example applications.

SEMANTICS: When MIDI literature talks about a sample, usually it means a
collection of many sample points that make up what we call a "wave".

 [Similarities and Differences from the 8SVX Form](../Devices_Manual_guide/node028F.html) 
 [The SAMP Header](../Devices_Manual_guide/node0290.html) 
 [The MHDR Chunk](../Devices_Manual_guide/node0291.html) 
 [The NAME Chunk](../Devices_Manual_guide/node0292.html) 
 [The BODY Chunk](../Devices_Manual_guide/node0293.html) 
 [Structure of an Individual Sample Point](../Devices_Manual_guide/node0294.html) 
 [The Waveheader Explained](../Devices_Manual_guide/node0295.html) 
 [MIDI Velocity vs. Amiga Channel Volume](../Devices_Manual_guide/node0296.html) 
 [An EGpoint (Envelope Generator)](../Devices_Manual_guide/node0297.html) 
 [Additional User Data Section](../Devices_Manual_guide/node0298.html) 
 [Converting Midi Sample Dump to SAMP](../Devices_Manual_guide/node0299.html) 
 [Interpreting the Playmode](../Devices_Manual_guide/node029A.html) 
 [Making A Transpose Table](../Devices_Manual_guide/node029B.html) 
 [Making the Velocity Table](../Devices_Manual_guide/node029C.html) 
 [The Instrument Type](../Devices_Manual_guide/node029D.html) 
 [The Order of the Chunks](../Devices_Manual_guide/node029E.html) 
 [Filename Conventions](../Devices_Manual_guide/node029F.html) 
 [Why Does Anyone Need Such a Complicated File?](../Devices_Manual_guide/node02A0.html) 

