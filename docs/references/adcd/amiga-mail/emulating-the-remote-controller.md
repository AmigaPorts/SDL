---
title: Emulating the Remote Controller
manual: amiga-mail
chapter: amiga-mail
section: emulating-the-remote-controller
functions: []
libraries: []
---

# Emulating the Remote Controller

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

One of the major differences between the A570 and the CDTV is the
remote controller.  The Amiga's keyboard, the mouse, and, optionally,
the joystick replace the remote controller.  Your title must take these
differences into account, and your input handling routines may require
modification.  The following section will discuss these differences,
and make additions to the CDTV User Interface Guidelines.

Here is a chart describing how Amiga keyboard and mouse actions should
correspond to the CDTV player's remote controller buttons.


    Remote Controller   Amiga Keyboard         Amiga Mouse/Joystick
    -----------------   --------------         --------------------
     cursor buttons      Cursor keys              Mouse movement
  (directional arrows)



       'A' button       Left Alt + Left Amiga,     Left button
                        Left Amiga key alone,
                        F9 function key,
                        'A' key on keyboard

       'B' button       Right Alt + Right Amiga    Right button
                        Right Amiga key alone,
                        F10 function key
                        'B' key on keyboard

       0-9 buttons      Keyboard 0-9
                        Keypad number keys

         ESCAPE         Esc and Help
         ENTER          Return or keypad Enter
         REW            F1
         PLAY           F2
         PAUSE          F3
         FF             F4
         STOP           F5
 [Cursor Buttons](amiga-mail/cursor-buttons.md)               [Escape Key](amiga-mail/escape-key.md)                      [Genlock](amiga-mail/genlock.md) 
 [The 'A' and 'B' Buttons](amiga-mail/the-a-and-b-buttons.md)      [Help Key](amiga-mail/help-key.md)                        [CD/TV](amiga-mail/cd-tv.md) 
 [0-9 Buttons](amiga-mail/0-9-buttons.md)                  [REW, PLAY, PAUSE, FF, STOP](amiga-mail/rew-play-pause-ff-stop.md)      [JOY/MOUSE](amiga-mail/joy-mouse.md) 

