---
title: II-37: Using the AmigaDOS Pattern Matching Functions
manual: amiga-mail
chapter: amiga-mail
section: ii-37-using-the-amigados-pattern-matching-functions
functions: []
libraries: []
---

# II-37: Using the AmigaDOS Pattern Matching Functions

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

by Ewout Walraven


One of the additions made to dos.library for release 2.0 is a series of
functions to do standard pattern matching.  Using a set of standard string
matching tokens, any application can use these functions to test if a
particular string matches a pattern.  The Amiga OS uses these functions
for processing file name strings for its new directory scanning functions.

These functions can be used in every circumstance where you would like to
enable the user to enter a pattern to indicate more than one target
string.  Using these functions not only makes it unnecessary to implement
your own pattern matching routines, but by using the familiar DOS pattern
tokens in your application, it is easier for the user to learn how to use
your application.

 [Patterns](amiga-mail/patterns.md)      [Parsing](amiga-mail/parsing.md)      [Matching](amiga-mail/matching.md) 

