---
title: The Debugging Setup
manual: amiga-mail
chapter: amiga-mail
section: the-debugging-setup
functions: []
libraries: []
---

# The Debugging Setup

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Enforcer and Mungwall both output their debugging information to the
serial port at the baud rate to which the Amiga's serial hardware is
currently set.  After powerup, the serial hardware is set to 9600 baud.
You can use a terminal package to alter the current baud rate setting.
To set up an Amiga for serial debugging, connect your Amiga's serial
port via a NULL-modem serial cable to a terminal.

The best debugging setup is to connect your Amiga to another computer
running a terminal package.  Ideally the terminal package should have
an ASCII capture mode so it can capture all the serial debugging output
and save it to a file for examination.  The terminal package should
also beep when it receives a CTRL-G, as both Enforcer and Mungwall send
a CTRL-G beep with each Enforcer/Mungwall hit. There are several less
effective alternatives to using Enforcer and Mungwall with a remote
terminal.  Both can send their output to a serial printer.  There are
special versions of both Enforcer and Mungwall that send their output
to the parallel port (Enforcer.par and Mungwall.par) for output to a
parallel printer.  In a pinch, attach a modem to the serial port and
run a terminal package set to the modem's baud rate.  As long as the
modem has not made any telephone connection, the modem will bounce back
any Enforcer or Mungwall hits that come through the serial port, which
the terminal package can capture.  Because the debugging information
has to move at modem's baud rate, the modem method tends to lose data,
especially when there is a lot Enforcer/Mungwall hits.

