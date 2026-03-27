---
title: 36 Translator Library
manual: libraries
chapter: libraries
section: 36-translator-library
functions: []
libraries: []
---

# 36 Translator Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

This chapter describes the translator library which, together with the
narrator device, provides the Amiga's text-to-speech capability. To fully
understand how speech is produced on the Amiga, you should also read the
"[Narrator Device](devices/8-narrator-device.md)" chapter of the Amiga ROM Kernel Reference Manual:
Devices.

The translator library provides a single function, [Translate()](libraries/36-translator-library-using-the-translate-function.md), that
converts an English language string into a phonetic string. You may then
pass this phonetic string to the narrator device which will say the string
using the Amiga's audio hardware. The two subsystems may also be used
individually.  You don't have to use the narrator to say the phonetic
strings; you could use them instead for phonetic analysis or some other
special purpose.

 [Opening the Translator Library](libraries/36-translator-library-opening-the-translator-library.md)    [Closing the Translator Library](libraries/36-translator-library-closing-the-translator-library.md) 
 [Using the Translate Function](libraries/36-translator-library-using-the-translate-function.md)      [Additional Notes About Translate](libraries/36-translator-library-additional-notes-about-translate.md) 

