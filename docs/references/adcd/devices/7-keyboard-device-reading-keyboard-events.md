---
title: 7 Keyboard Device / Reading Keyboard Events
manual: devices
chapter: devices
section: 7-keyboard-device-reading-keyboard-events
functions: []
libraries: []
---

# 7 Keyboard Device / Reading Keyboard Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Reading keyboard events is normally not done through direct access to the
keyboard device. (Higher level devices such as the input device and
console device are available for this.  See the chapter [Input Device](devices/6-input-device.md)
for more information on the intimate linkage between the input device and
the keyboard device.)  This section is provided primarily to show you the
component parts of a keyboard input event.

The keyboard matrix figure shown at the beginning of this chapter gives
the code value that each key places into the ie_Code field of the input
event for a key-down event. For a key-up event, a value of hexadecimal 80
is or'ed with the value shown above. Additionally, if either shift key is
down, or if the key is one of those in the numeric keypad, the qualifier
field of the keyboard input event will be filled in accordingly. In V34
and earlier versions of Kickstart, the keyboard device does not set the
numeric qualifier for the keypad keys "(", ")", "/", "*" and "+".

When you ask to read events from the keyboard, the call will not be
satisfied until at least one keyboard event is available to be returned.
The io_Length field must contain the number of bytes available in io_Data
to insert events into. Thus, you should use a multiple of the number of
bytes in an [InputEvent](autodocs-2.0/includes-devices-inputevent-h.md) (see example below).


```c
    Type-Ahead Processing.
    ----------------------
    The keyboard device can queue up several keystrokes without a task
    requesting a report of keyboard events. However, when the keyboard
    event buffer has been filled with no task interaction, additional
    keystrokes will be discarded.

     [Example Read Keyboard Event Program](devices/devices-dev-examples-keyboard-events-c.md) 
```
