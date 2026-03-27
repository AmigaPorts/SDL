---
title: 18 / What is a Library? / Using a Library to Reference Data
manual: libraries
chapter: libraries
section: 18-what-is-a-library-using-a-library-to-reference-data
functions: []
libraries: []
---

# 18 / What is a Library? / Using a Library to Reference Data

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Most libraries (such as Intuition, graphics and Exec) have other data that
follows the [Library](libraries/18-exec-libraries-what-is-a-library.md) data structure in memory.  Although it is not normally
necessary, a program can use the library base pointer to access the
Library structure and any custom library data.

In general, the system's library base data is read-only, and should be
directly accessed as little as possible, primarily because the format of
the data may change in future revisions of the library.  If the library
provides functions to allow access to library data, use those instead.

