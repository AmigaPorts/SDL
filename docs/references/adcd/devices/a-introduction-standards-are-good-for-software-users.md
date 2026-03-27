---
title: A / Introduction / Standards are Good for Software Users
manual: devices
chapter: devices
section: a-introduction-standards-are-good-for-software-users
functions: []
libraries: []
---

# A / Introduction / Standards are Good for Software Users

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Customers should be able to move their own data between independently
developed software products.  And they should be able to buy data
libraries usable across many such products.  The types of data objects to
exchange are open-ended and include plain and formatted text, raster and
structured graphics, fonts, music, sound effects, musical instrument
descriptions, and animation.

The problem with expedient file formats - typically memory dumps is that
they're too provincial.  By designing data for one particular use (such as
a screen snapshot), they preclude future expansion (would you like a full
page picture?  a multi-page document?).  In neglecting the possibility
that other programs might read their data, they fail to save contextual
information (how many bit planes?  what resolution?).  Ignoring that other
programs might create such files, they're intolerant of extra data (a
different picture editor may want to save a texture palette with the
image), missing data (such as no color map), or minor variations (perhaps
a smaller image).  In practice, a filed representation should rarely
mirror an in-memory representation.  The former should be designed for
longevity; the latter to optimize the manipulations of a particular
program.  The same filed data will be read into different memory formats
by different programs.

The IFF philosophy: "A little behind-the-scenes conversion when programs
read and write files is far better than NxM explicit conversion utilities
for highly specialized formats".

So we need some standardization for data interchange among development
tools and products.  The more developers that adopt a standard, the better
for all of us and our customers.

