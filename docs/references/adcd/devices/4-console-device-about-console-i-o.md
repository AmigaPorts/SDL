---
title: 4 Console Device / About Console I/O
manual: devices
chapter: devices
section: 4-console-device-about-console-i-o
functions: []
libraries: []
---

# 4 Console Device / About Console I/O

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The console device may be thought of as a kind of terminal. You send
character streams to the console device; you also receive them from the
console device. These streams may be characters, control sequences or a
combination of the two.

Console I/O is closely associated with the Amiga Intuition interface; a
console must be tied to a window that is already opened.  From the Window
data structure, the console device determines how many characters it can
display on a line and how many lines of text it can display in a window
without clipping at any edge.

You can open the console device many times, if you wish. The result of
each open call is a new console unit. AmigaDOS and Intuition see to it
that only one window is currently active and its console, if any, is the
only one (with a few exceptions) that receives notification of input
events, such as keystrokes. Later in this chapter you will see that other
Intuition events can be sensed by the console device as well.

   Introducing...
   --------------
   For this entire chapter the characters "<CSI>" represent the
   control sequence introducer. For output you may use either the
   two-character sequence  <Esc>[ (0x1B 0x5B) or the one-byte value
   0x9B. For input you will receive 0x9B unless the sequence has been
   typed by the user.

 [Exec Functions And The Console Device](devices/4-about-console-i-o-exec-functions-and-the-console-device.md) 
 [General Console Screen Output](devices/4-about-console-i-o-general-console-screen-output.md) 
 [Console Keyboard Input](devices/4-about-console-i-o-console-keyboard-input.md) 

