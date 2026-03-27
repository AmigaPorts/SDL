# Standard Data and Property Chunks / Dynamic Mark SEvent


An [SEvent](../Devices_Manual_guide/node02B7.html#line29) SID_Dynamic represents a dynamic mark like ppp and fff in Common
Music Notation.  Its data field is a MIDI key velocity number 0 through
127. This sets a "volume control" for following notes in the track.  This
"track volume control" is scaled by the overall score volume in the [SHDR](../Devices_Manual_guide/node02B3.html)
chunk.  The default dynamic level is 127 (full volume).

