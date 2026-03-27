# Background / MIDI Instruments


As mentioned above, A [SMUS](../Devices_Manual_guide/node02AB.html) score can also ask for MIDI instruments.  This
is done by putting the MIDI channel and preset numbers in an INS1 chunk
with the instrument name.  Some programs will honor these requests while
others will just find instruments by name.

MIDI Recorder and sequencer programs may simply transcribe the MIDI
channel and preset commands in a recording session.  For this purpose,
set-MIDI-channel and set-MIDI-preset events can be embedded in a [SMUS](../Devices_Manual_guide/node02AB.html)
score's tracks.  Most programs should ignore these events.  An editor
program that wants to exchange scores with such programs should recognize
these events.  It should let the user change them to the more general
set-instrument events.

