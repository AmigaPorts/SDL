---
title: 8 Narrator Device
manual: devices
chapter: devices
section: 8-narrator-device
functions: []
libraries: []
---

# 8 Narrator Device

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chapter describes the narrator device which, together with the
translator library, provides all of the Amiga's text-to-speech functions.
The narrator device is used to produce high-quality human-like speech in
real time.


           NEW NARRATOR FEATURES FOR VERSION 2.0
   Feature        Description         Function
   -------        -----------         --------
   NDB_NEWIORB    Flag                Use V37 features
   NDB_WORDSYNC   Flag                Synchronize speech/mouth on words
   NDB_SYLSYNC    Flag                Synchronize speech/mouth on syllables
   F0enthusiasm   narrator_rb field   F0 excursion factor
   F0perturb      narrator_rb field   Amount of F0 perturbation
   F1adj          narrator_rb field   F1 adjustment in ±5% steps
   F2adj          narrator_rb field   F2 adjustment in ±5% steps
   F3adj          narrator_rb field   F3 adjustment in ±5% steps
   A1adj          narrator_rb field   A1 adjustment in decibels
   A2adj          narrator_rb field   A2 adjustment in decibels
   A3adj          narrator_rb field   A3 adjustment in decibels
   articulate     narrator_rb field   Transition time multiplier
   centralize     narrator_rb field   Degree of vowel centralization
   centphon       narrator_rb field   Pointer to central ASCII phon
   AVbias         narrator_rb field   Amplitude of voicing bias
   AFbias         narrator_rb field   Amplitude of frication bias
   priority       narrator_rb field   Priority while speaking

   Compatibility Warning:
   ----------------------
   The new features for the 2.0 narrator device are not backwards
   compatible.

 [Narrator Device Commands and Functions](devices/8-narrator-device-narrator-device-commands-and-functions.md) 
 [Device Interface](devices/8-narrator-device-device-interface.md) 
 [Writing to the Narrator Device](devices/8-narrator-device-writing-to-the-narrator-device.md) 
 [Reading from the Narrator Device](devices/8-narrator-device-reading-from-the-narrator-device.md) 
 [How to Write Phonetically for Narrator](devices/8-narrator-device-how-to-write-phonetically-for-narrator.md) 
 [A More Technical Explanation](devices/8-narrator-device-a-more-technical-explanation.md) 
 [Example Speech and Mouth Movement Program](devices/devices-dev-examples-full-narrator-c.md) 
 [Additional Information on the Narrator Device](devices/8-narrator-device-additional-information-on-the-narrator.md) 

