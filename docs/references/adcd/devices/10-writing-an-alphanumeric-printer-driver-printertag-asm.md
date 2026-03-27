---
title: 10 / / Writing An Alphanumeric Printer Driver / Printertag.asm
manual: devices
chapter: devices
section: 10-writing-an-alphanumeric-printer-driver-printertag-asm
functions: []
libraries: []
---

# 10 / / Writing An Alphanumeric Printer Driver / Printertag.asm

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

For an alphanumeric printer the printer-specific values that need to be
filled in printertag.asm are as follows:

   MaxColumns

      the maximum number of columns the printer can print across the page.
   NumCharSets

      the number of character sets which can be selected.
   8BitChars

      a pointer to an extended character table. If the field is null, the
      default table will be used.
   ConvFunc

      a pointer to a character conversion routine. If the field is null,no
      conversion routine will be used.
