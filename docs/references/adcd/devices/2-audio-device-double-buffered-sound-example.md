---
title: 2 Audio Device / Double Buffered Sound Example
manual: devices
chapter: devices
section: 2-audio-device-double-buffered-sound-example
functions: []
libraries: []
---

# 2 Audio Device / Double Buffered Sound Example

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The program listed below demonstrates double buffering with the audio
device.  Run the program from the CLI.  It takes one parameter - the name
of an IFF 8SVX sample file to play on the Amiga's audio device. The
maximum size for a sample on the Amiga is 128K. However, by using
double-buffering and queueing up requests to the audio device, you can
play longer samples smoothly and without breaks.


```c
     [Audio_8SVX.c](devices/devices-dev-examples-audio-8svx-c.md) 
```
