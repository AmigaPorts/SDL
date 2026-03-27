---
title: 4 / Writing to the Console Device / Hints For Writing Text
manual: devices
chapter: devices
section: 4-writing-to-the-console-device-hints-for-writing-text
functions: []
libraries: []
---

# 4 / Writing to the Console Device / Hints For Writing Text

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

256 Is A Nice Round Number
--------------------------
   You must keep in mind that the console device locks all layers while
   writing text.  To avoid, problems with this, it is best to send
   smaller rather larger numbers of character to be written.  We
   recommend no more than 256 bytes per write as the optimum size

Turn Off The Cursor
-------------------
   If your console is attached to a V1.2/1.3 SuperBitmap window, you
   will not see a cursor rendered. For output speed and compatibility
   with future OS versions which may visibly render the cursor, you
   should send the cursor-off sequence (ESC[0 p) whenever you open or
   reset (ESCc) a SuperBitmap window's console.

