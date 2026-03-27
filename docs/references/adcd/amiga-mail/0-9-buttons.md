---
title: 0-9 Buttons
manual: amiga-mail
chapter: amiga-mail
section: 0-9-buttons
functions: []
libraries: []
---

# 0-9 Buttons

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The 0-9 and ENTER buttons located in the center of the remote are
replaced by the Amiga keyboard's numeric keypad.  The keycodes of the
remote represent those found on the keypad, the only difference being
the reversed physical layout of the keys:


                Remote              Numeric keypad

                1 2 3                   7 8 9
                4 5 6 0                 4 5 6
                7 8 9                   1 2 3
                                          0
Your code will probably not have to be modified to take this into
account, unless it displays 9 icons in a grid pattern, and wants the
user to type in a number corresponding to a certain position.  If you
support a jumping highlight (as suggested in the CDTV User Interface
Guidelines), this should not be a problem.

Your code should also support the 10 numeric keys on top of the
alphanumeric keyboard (just below the function keys) for input of
numbers.

