---
title: 34 Keymap Library
manual: libraries
chapter: libraries
section: 34-keymap-library
functions: []
libraries: []
---

# 34 Keymap Library

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Amiga computers are sold internationally with a variety of local keyboards
which match the standards of particular countries. All Amigas have
keyboards which are physically similar, and keys which output the same
low-level raw key code for any particular physical key.  However, in
different countries, the keycaps of the keys may contain different letters
or symbols.  Since the physical position of a key determines the raw key
code that it generates, raw key codes are not internationally compatible.
For instance, on the German keyboard, the Y and Z keys are swapped when
compared to the USA keyboard.  The second key on the fifth row will
generate the same raw key code on all Amiga keyboards, but should be
decoded as a Z on a US keyboard and as a Y on a German keyboard.

The Amiga uses the ECMA-94 Latin1 International 8-bit character set, and
can map raw key codes to any desired ANSI character value, string, or
escape sequence.  This allows national keyboards to be supported by using
keymaps.  A keymap is a file which describes what character or string is
tied to what key code.  Generally, the user's startup-sequence will set a
system default keymap that is correct for the user's keyboard.  The
console.device translates the raw key codes into the correct characters
based on the installed keymap.  This includes the translation of special
[deadkey](libraries/34-keymap-functions-dead-class-keys.md) sequential key combinations to produce accented international
characters.

Programs which perform keyboard input using the console.device, CON:,
RAW:, or Intuition VANILLAKEY, will receive the correct ASCII values for a
user's keycaps, based on their keymap.  But some applications may require
custom keymaps, or may need to perform their own translation between raw
key codes and ANSI characters. In this chapter, the term ANSI refers to
standard 8-bit character definitions which include printable ASCII
characters, special characters, and escape sequences.

Until V37, keymapping commands were only available in the console.device.
Keymap.library is a new library in Release 2 (V37).  It offers the some of
the keymap commands of the console.device, enabling applications to
inquire after the default keymap and map key codes to ANSI characters. It
also provides the ability to map ANSI characters back into raw codes.
Unlike the console.device however, it can not be used to select a keymap
for only one application, i.e., one console window.

As a prelude to the following material, note that the Amiga keyboard
transmits raw key information to the computer in the form of a key
position and a transition.  Raw key positions range from hexadecimal 00 to
7F.  When a key is released, its raw key position, plus hexadecimal 80, is
transmitted.

 [Keymap Functions](libraries/34-keymap-library-keymap-functions.md)    [Keyboard Layout](libraries/34-keymap-library-keyboard-layout.md)    [Function Reference](libraries/34-keymap-library-function-reference.md) 

