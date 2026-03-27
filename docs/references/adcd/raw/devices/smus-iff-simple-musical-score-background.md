# SMUS IFF Simple Musical Score / Background


Here's some background information on score representation in general and
design choices for [SMUS](../Devices_Manual_guide/node02AB.html).

First, we'll borrow some terminology from the Structured Sound Synthesis
Project.  [See the [SSSP reference](../Devices_Manual_guide/node02AC.html#line8).]  A "musical note" is one kind of
scheduled event.  Its properties include an event duration, an event
delay, and a timbre object.  The event duration tells the scheduler how
long the note should last. The event delay tells how long after starting
this note to wait before starting the next event.  The timbre object
selects sound driver data for the note; an "instrument" or "timbre".  A
"rest" is a sort of a null event.  Its only property is an event delay.

 [Classical Event Durations](../Devices_Manual_guide/node02AE.html) 
 [Tracks](../Devices_Manual_guide/node02AF.html) 
 [Instrument Registers](../Devices_Manual_guide/node02B0.html) 
 [MIDI Instruments](../Devices_Manual_guide/node02B1.html) 

