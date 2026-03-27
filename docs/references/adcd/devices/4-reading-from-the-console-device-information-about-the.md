---
title: 4 / Reading from the Console Device / Information About The Input Stream
manual: devices
chapter: devices
section: 4-reading-from-the-console-device-information-about-the
functions: []
libraries: []
---

# 4 / Reading from the Console Device / Information About The Input Stream

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For the most part, keys whose keycaps are labeled with ANSI-standard
characters will ordinarily be translated into their ASCII-equivalent
character by the console device through the use of its keymap. Keymap
information can be found in the "[Keymap Library](libraries/34-keymap-library.md)" chapter of the Amiga
ROM Kernel Reference Manual: Libraries.

For keys other than those with normal ASCII equivalents, an escape
sequence is generated and inserted into your input stream.  For example,
in the default state (no raw input events selected)  the function, arrow
and special keys (reserved for 101 key keyboards) will cause the sequences
shown in the next table to be inserted in the input stream.


```c
                      SPECIAL KEY REPORT SEQUENCES

     Key        Unshifted Sends     Shifted Sends
     ---        ---------------     -------------
     F1            <CSI>0~            <CSI>10~
     F2            <CSI>1~            <CSI>11~
     F3            <CSI>2~            <CSI>12~
     F4            <CSI>3~            <CSI>13~
     F5            <CSI>4~            <CSI>14~
     F6            <CSI>5~            <CSI>15~
     F7            <CSI>6~            <CSI>16~
     F8            <CSI>7~            <CSI>17~
     F9            <CSI>8~            <CSI>18~
     F10           <CSI>9~            <CSI>19~
     F11           <CSI>20~           <CSI>30~ (101 key keyboard)
     F12           <CSI>21~           <CSI>31~ (101 key keyboard)
     HELP          <CSI>?~            <CSI>?~  (same sequence for both)
     Insert        <CSI>40~           <CSI>50~ (101 key keyboard)
     Page Up       <CSI>41~           <CSI>51~ (101 key keyboard)
     Page Down     <CSI>42~           <CSI>52~ (101 key keyboard)
     Pause/Break   <CSI>43~           <CSI>53~ (101 key keyboard)
     Home          <CSI>44~           <CSI>54~ (101 key keyboard)
     End           <CSI>45~           <CSI>55~ (101 key keyboard)

     Arrow keys:
     Up            <CSI>A             <CSI>T
     Down          <CSI>B             <CSI>S
     Left          <CSI>D             <CSI>A   (notice the space
     Right         <CSI>C             <CSI>@    after <CSI>)
```
