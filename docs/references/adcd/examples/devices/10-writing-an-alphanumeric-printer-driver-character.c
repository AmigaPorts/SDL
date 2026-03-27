/* Source: ADCD 2.1
 * Section: 10-writing-an-alphanumeric-printer-driver-character
 * Library: devices
 * ADCD reference: devices/10-writing-an-alphanumeric-printer-driver-character.md
 */

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
