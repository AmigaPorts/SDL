---
title: I-3: 2.0 Version Strings
manual: amiga-mail
chapter: amiga-mail
section: i-3-2-0-version-strings
functions: []
libraries: []
---

# I-3: 2.0 Version Strings

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

By Carolyn Scheppner


Unlike the 1.3 version command, the 2.0 version command has the ability
to search Amiga files for a version string.  If you try the 2.0 version
command on any of the 2.0 Workbench commands, you will find that almost
all Workbench commands now contain these special version strings.  For
example, running version on the current version of  SYS:Utilities/More
will output More 37.2.

This embedded version string provides a simple way for a user to
determine the specific version of a command.  This is extremely useful
for bug reports and phone support.  You may enter these strings in your
code yourself and update them by hand when required, or you may
automate updates by using the bumprev tool (provided on a variety of
DevCon disk sets and also in the Preliminary Software Toolkit II).

 [Hand-Coded Version Strings](amiga-mail/hand-coded-version-strings.md) 
 [Automating Version Numbering with Bumprev](amiga-mail/automating-version-numbering-with-bumprev.md) 

