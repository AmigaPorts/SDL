---
title: 4 Intuition Windows / Communicating with Intuition
manual: libraries
chapter: libraries
section: 4-intuition-windows-communicating-with-intuition
functions: []
libraries: []
---

# 4 Intuition Windows / Communicating with Intuition

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Intuition can notify an application when the user moves the mouse, makes a
menu choice, selects an application gadget or changes the window's size.
To find out about user activity from Intuition, there are two methods:

  * Use the Intuition Direct Communications Message Port (IDCMP) system.

    Input events are received as standard Exec messages at a port
    Intuition creates for your window.
  * Use the console.device to receive all input events as character

    sequences.
 [The IDCMP](libraries/4-communicating-with-intuition-the-idcmp.md)             [The IDCMP And The Active Window](libraries/4-communicating-with-intuition-the-idcmp-and-the-active.md) 
 [The Console Device](libraries/4-communicating-with-intuition-the-console-device.md)    [The IDCMP And Gadgets](libraries/4-communicating-with-intuition-the-idcmp-and-gadgets.md) 

