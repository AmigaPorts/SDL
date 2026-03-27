---
title: IX-1: Four Can Play-Supporting Parallel Port Joysticks
manual: amiga-mail
chapter: amiga-mail
section: ix-1-four-can-play-supporting-parallel-port-joysticks
functions: []
libraries: []
---

# IX-1: Four Can Play-Supporting Parallel Port Joysticks

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Chris Ludwig


One of the many reasons people buy computer-based products is to use
them as an "entertainment box".  Amiga users are no exception in this
regard.  The Amiga has all the ingredients needed to be a great game
machine; fast high-quality graphics, high-fidelity stereo sound, fast
processor, and built-in joystick ports.

With this level of hardware support, it's no wonder that some of the
industry's best games continue to be written for the Amiga first.

The only kind of games that don't currently lend themselves to the
Amiga's built-in hardware are those that are meant to be played by more
than two players simultaneously.  Several types of games fall into this
category, the most notable being the scrolling cooperative.  This type
of game, where up to four players control on-screen versions of
themselves, is quite popular in video arcades.  Another format that
lends itself to having more than two joysticks is the board game
simulation.  It's simply easier to play a four player board game if
each player has his or her own control.

Because the Amiga has only two joystick ports, there are currently only
a small number of "greater than two" player games available.  So how
do these games get around the two port limitation?  The developers of
these games have worked up a little bit of external hardware that
remaps some parallel port input lines as two more joystick ports for
single button joysticks.

Fortunately, these developers are all using the same wiring in their
interfaces.  Unfortunately, neither the interface nor its
specifications have been widely available.

This article explains the construction of these parallel port joystick
adapters (this article refers to them "+2" adapters), and
demonstrates a coding strategy which will allow your software to access
these two new ports.  Though the instructions are fairly simple, if not
done properly, it is possible to damage your computer, so Commodore
does not recommend that you build these yourself.  This information is
provided for your convenience and is expressly subject to the
disclaimer and warnings found at the beginning of this publication.

 [Building the +2 Interface](amiga-mail/building-the-2-interface.md) 
 [Housing the Interface](amiga-mail/housing-the-interface.md) 
 [Supporting the Interface in Software](amiga-mail/supporting-the-interface-in-software.md) 

