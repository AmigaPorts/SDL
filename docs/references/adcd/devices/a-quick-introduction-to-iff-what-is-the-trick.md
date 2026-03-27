---
title: A Quick Introduction to IFF / What is the trick?
manual: devices
chapter: devices
section: a-quick-introduction-to-iff-what-is-the-trick
functions: []
libraries: []
---

# A Quick Introduction to IFF / What is the trick?

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

File compatibility is easy to achieve if programmers let go of one
notion - dumping internal data structures to disk.  A program's internal
data structures should really be suited to what the program does and how
it works.  What's "best" changes as the program evolves new functions and
methods.  But a disk format should be suited to storage and interchange.

Once we design internal formats and disk formats for their own separate
purposes, the rest is easy.  Reading and writing become behind-the-scenes
conversions.  But two conversions hidden in each program is much better
than a pile of conversion programs.

Does this seem strange?  It's what ASCII text programs do!  Text editors
use line tables, piece tables, gaps, and other structures for fast editing
and searching.  Text generators and consumers construct and parse files.
That's why the ASCII standard works so well.

Also, every file must be self-sufficient.  E.g., a picture file has to
include its size and number of bits/pixel.

