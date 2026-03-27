---
title: Standard Data and Property Chunks / Key Signature SEvent
manual: devices
chapter: devices
section: standard-data-and-property-chunks-key-signature-sevent
functions: []
libraries: []
---

# Standard Data and Property Chunks / Key Signature SEvent

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

An [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) SID_KeySig sets the key signature for the track.  Its data field
is a UBYTE number encoding a major key:

	data	key	music notation	data	key	music notation

	 0	 C maj
	 1	 G    	  #		  8	 F	  b
	 2	 D    	  ##		  9	 Bb	  bb
	 3	 A    	  ###		 10	 Eb	  bbb
	 4	 E    	  ####		 11	 Ab	  bbbb
	 5	 B    	  #####		 12	 Db	  bbbbb
	 6	 F#   	  ######	 13	 Gb	  bbbbbb
	 7	 C#    	  #######	 14	 Cb	  bbbbbbb

A SID_KeySig [SEvent](devices/standard-data-and-property-chunks-data-chunk-trak.md) changes the key for the following notes in that track.
C major is the default key in every track before the first SID_KeySig
SEvent.

