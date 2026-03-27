---
title: 10 / The Keyboard / Intuition Keyboard Shortcuts
manual: libraries
chapter: libraries
section: 10-the-keyboard-intuition-keyboard-shortcuts
functions: []
libraries: []
---

# 10 / The Keyboard / Intuition Keyboard Shortcuts

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

If Intuition sees a command key sequence that means nothing to it, the key
sequence is sent to the active window as usual. See the chapter on
"[Intuition Input and Output Methods](libraries/9-intuition-input-and-output-methods-intuition-input.md)" for how this works. This section and
the next section describe what Intuition does when it recognizes certain
special command key sequences.

It is recommended that programs abide by certain command key standards to
provide a consistent interface for Amiga users. The Amiga User Interface
Style Guide contains a complete list of the recommended standards.

There are a number of special keyboard shortcuts supported by Intuition.
These involve holding down the left Amiga key and simultaneously pressing
a another key.  These functions allow the user to do such things as move
the Workbench screen to the front using the keyboard.



        Table 10-2: Intuition Keyboard Shortcuts


      Keyboard Shortcut       Function Performed
      -----------------       ------------------

        left Amiga M      Move frontmost screen to back.

        left Amiga N      Move Workbench screen to front.

        left Amiga B      System requester cancel, or select the
                          rightmost button in the system requester.

        left Amiga V      System requester OK, or select the leftmost
                          button in the system requester.

     left Amiga + mouse   Screen drag from any point.  By holding down
       select button      the left Amiga key, the user may drag the
                          screen with the mouse from any part of the
                          screen or window on the screen.


    About System Keyboard Shortcuts
    -------------------------------
    Many of these keyboard commands may be remapped through the IControl
    Preferences editor.  Do not rely on the values reported here.
Intuition consumes these command key sequences for its own use.  That is,
it always detects these events and removes them from the input stream.
The application will not see the events.

