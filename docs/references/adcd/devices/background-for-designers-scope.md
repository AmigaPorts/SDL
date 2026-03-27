---
title: Background for Designers / Scope
manual: devices
chapter: devices
section: background-for-designers-scope
functions: []
libraries: []
---

# Background for Designers / Scope

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

IFF addresses these needs by defining a standard file structure, some
initial data object types, ways to define new types, and rules for
accessing these files.  We can accomplish a great deal by writing programs
according to this standard, but do not expect direct compatibility with
existing software. We'll need conversion programs to bridge the gap from
the old world.

IFF is geared for computers that readily process information in 8-bit
bytes. It assumes a "physical layer" of data storage and transmission that
reliably maintains "files" as sequences of 8-bit bytes.  The standard
treats a "file" as a container of data bytes and is independent of how to
find a file and whether it has a byte count.

This standard does not by itself implement a clipboard for cutting and
pasting data between programs.  A clipboard needs software to mediate
access, and provide a notification mechanism so updates and requests for
data can be detected.

