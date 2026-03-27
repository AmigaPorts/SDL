---
title: 4 Console Device / Selecting Raw Input Events
manual: devices
chapter: devices
section: 4-console-device-selecting-raw-input-events
functions: []
libraries: []
---

# 4 Console Device / Selecting Raw Input Events

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If the keyboard information - including "cooked" keystrokes - does not
give you enough information about input events, you can request additional
information from the console driver.

The command to SET RAW EVENTS is formatted as:


```c
    <CSI>[event-types-separated-by-semicolons]{
```
If, for example, you need to know when each key is pressed and released,
you would request "RAW keyboard input." This is done by writing
"<CSI>1{" to the console.  In a single SET RAW EVENTS request, you can
ask the console to set up for multiple event types at one time.  You must
send multiple numeric parameters, separating them by semicolons (;). For
example, to ask for gadget pressed, gadget released, and close gadget
events, write:


```c
    <CSI>7;8;11{
```
You can reset, that is, delete from reporting, one or more of the raw
input event types by using the RESET RAW EVENTS command, in the same
manner as the SET RAW EVENTS was used to establish them in the first
place.  This command stream is formatted as:


```c
    <CSI>[event-types-separated-by-semicolons]}
```
So, for example, you could reset all of the events set in the above
example by transmitting the command sequence:


```c
    <CSI>7;8;11}
```
   The Read Stream May Not Be Dry.
   -------------------------------
   There could still be pending RAW INPUT EVENTS in your read stream
   after turning off one or more RAW INPUT EVENTS.

The following table lists the valid raw input event types.


```c
                      RAW INPUT EVENT TYPES
    Request                                        Request
    Number   Description              Number     Description
    -------  -----------              ------     -----------
      0      No-op (used internally)    11       Close Gadget
      1      RAW keyboard input *       12       Window resized
      2      RAW mouse input            13       Window refreshed
      3      Private Console Event      14       Preferences changed
      4      Pointer position           15       Disk removed
      5      (unused)                   16       Disk inserted
      6      Timer                      17       Active window
      7      Gadget pressed             18       Inactive window
      8      Gadget released            19       New pointer position (V36)
      9      Requester activity         20       Menu help (V36)
      10     Menu numbers               21       Window changed (V36)
                                                 (zoom, move)

      * Note:Intuition swallows all except the select button.
```
The event types-requester, window refreshed, active window, inactive
window, window resized and window changed-are dispatched to the console
unit which owns the window from which the events are generated, even if it
is not the active (selected ) window at the time the event is generated.
This ensures that the proper console unit is notified of those events. All
other events are dispatched to the active console unit (if it has
requested those events).

