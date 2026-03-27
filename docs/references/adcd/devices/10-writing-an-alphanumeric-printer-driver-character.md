---
title: 10 / / Writing An Alphanumeric Printer Driver / Character Conversion
manual: devices
chapter: devices
section: 10-writing-an-alphanumeric-printer-driver-character
functions: []
libraries: []
---

# 10 / / Writing An Alphanumeric Printer Driver / Character Conversion

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The ConvFunc field contains a pointer to a character conversion function
that allows you to selectively translate any character to a combination of
other characters. If no translation conversion is necessary (for most
printers it isn't), the field should contain a null.

ConvFunc() arguments are a pointer to a buffer, the character currently
processed, and a CR/LF flag. The ConvFunc() function should return a -1 if
no conversion has been done. If the character is not to be added to the
buffer, a 0 can be returned. If any translation is done, the number of
characters added to the buffer must be returned.

Besides simple character translation, the ConvFunc() function can be used
to add features like underlining to a printer which doesn't support them
automatically. A global flag could be introduced that could be set or
cleared by the [DoSpecial()](devices/10-writing-an-alphanumeric-printer-driver-dospecial.md) function. Depending on the status of the flag
the ConvFunc() routine could, for example, put the character, a backspace
and an underline character in the buffer and return 3, the number of
characters added to the buffer.

The ConvFunc() function for this could look like the following example:

   #define DO_UNDERLINE   0x01
   #define DO_BOLD        0x02
   /* etc */

   external short myflags;

   int ConvFunc(buffer, c, crlf_flag)
   char *buffer, c;
   int crlf_flag
   {
   int nr_of_chars_added = 0;

   /* for this example we only do this for chars in the 0x20-0x7e range */
   /* Conversion of ESC (0x1b) and CSI (0x9b) is NOT recommended */

   if (c > 0x1f && c < 0x7f)
```c
       {             /* within space - ~ range ? */
       if (myflags & DO_UNDERLINE)
           {
           *buffer++ = c;                /* the character itself */
           *buffer++ = 0x08;             /* a backspace */
           *buffer++ = '_';              /* an underline char */
           nr_of_chars_added = 3;        /* added three chars to buffer */
           }
       if (myflags & DO_BOLD)
           {
           if (nr_of_chars_added)
               {      /* already have added something */
               *buffer++ = 0x08;         /* so we start with backspace */
               ++nr_of_chars_added;      /* and increment the counter */
               }
           *buffer++ = c;
           *buffer++ = 0x08;
           *buffer++ = c;
           ++nr_of_chars_added;
           if (myflags & DO_UNDERLINE)
               {      /* did we do underline too? */
               *buffer++ = 0x08;         /* then backspace again */
               *buffer++ = '_';          /* (printer goes crazy by now) */
               nr_of_chars_added += 2;   /* two more chars */
               }
           }
       }
```
   if (nr_of_chars_added)
```c
       return(nr_of_chars_added);        /* total nr of chars we added */
```
   else
```c
       return(-1);                       /* we didn't do anything */
```
   }

In [DoSpecial()](devices/10-writing-an-alphanumeric-printer-driver-dospecial.md) the flagbits could be set or cleared, with code like the
following:

   if (*command == aRIS)             /* reset  command */

```c
       myflags = 0;                  /* clear all flags */
```
   if (*command == aRIN)             /* initialize command */

```c
       myflags = 0;
```
   if (*command == aSGR0)            /* 'PLAIN' command */

```c
       myflags = 0;
```
   if (*command == aSGR4)            /* underline on */

```c
       myflags |= DO_UNDERLINE;      /* set underline bit */
```
   if (*command == aSGR24)           /* underline off */

```c
       myflags &= ~DO_UNDERLINE;     /* clear underline bit */
```
   if (*command == aSGR1)            /* bold on */

```c
       myflags |= DO_BOLD;           /* set bold bit */
```
   if (*command == aSGR22)           /* bold off */

```c
       myflags &= ~DO_BOLD;          /* clear bold bit */
```
Try to keep the expansions to a minimum so that the throughput will not be
slowed down too much, and to reduce the possibility of data overrunning
the printer device buffer.

