---
title: AIFF.doc / AIFF / Data Types
manual: devices
chapter: devices
section: aiff-doc-aiff-data-types
functions: []
libraries: []
---

# AIFF.doc / AIFF / Data Types

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

A C-like language will be used to describe the data structures in this
document The data types used are listed below.

char:          8 bits signed.  A char can contain more than just ASCII
```c
               characters.  It can contain any number from -128 to 127
               (inclusive).
```
unsigned char: 8 bits signed. Contains numbers from 0 to 255 (inclusive).
short:         16 bits signed.  Contains any number from -32,768 to 32,767
```c
               (inclusive).
```
unsigned short:16 bits unsigned.  Contains any number from 0 to 65,535
```c
               (inclusive).
```
long:          32 bits signed. Contains any number from -2,147,483,648
```c
               to 2,147,483,647 (inclusive).
```
unsigned long: 32 bits unsigned. Contains any number from 0 to
```c
               4,294,967,295 (inclusive).
```
extended:      80 bit IEEE Standard 754 floating point number (Standard
```c
               Apple Numeric Environment [SANE] data type Extended)
```
pstring:       Pascal-style string, a one-byte count followed by text
               bytes.  The total number of bytes in this data type should
               be even.  A pad byte can be added to the end of the text to
               accomplish this.  This pad byte is not reflected in the
               count.
ID:            32 bits,the concatenation of four printable ASCII characters

```c
               in the range ' ' (space, 0x20) through '~' (tilde, 0x7E).
               Leading spaces are not allowed in the ID but trailing spaces
               are OK.  Control characters are forbidden.
```
