---
title: 10 / / Writing An Alphanumeric Printer Driver / Extended Character Table
manual: devices
chapter: devices
section: 10-writing-an-alphanumeric-printer-driver-extended
functions: []
libraries: []
---

# 10 / / Writing An Alphanumeric Printer Driver / Extended Character Table

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The 8BitChars field could contain a pointer to a table of characters for
the ASCII codes $A0 to $FF. The symbols for these codes are shown in the
[IFF Appendix](devices/ftxt-iff-formatted-appendix-a-character-code-table.md) of this manual. If this field contains a NULL, it means
no specific table is provided for the driver, and the default table is to
be used instead.

Care should be taken when generating this table because of the way the
table is parsed by the printer device. Valid expressions in the table
include \011 where 011 is an octal number, \\000 for null and \\n
where n is a 1 to 3 digit decimal number. To enter an actual backslash in
the table requires the somewhat awkward \\\\. As an example, here is a
list of the first entries of the EpsonxX[CBM_MPS-1250] table:

   char *ExtendedCharTable[] =
```c
        {
        " ",                       /* NBSP */
        "\033R\007[\033R\\0",      /* i */
        "c\010|",                  /* c| */
        "\033R\003#\033R\\0",      /* L- */
        "\033R\005$\033R\\0",      /* o */
        "\033R\010\\\\\033R\\0",   /* Y- */
        "|",                       /* | */
        "\033R\002@\033R\\0",      /* SS */
        "\033R\001~\033R\\0",      /* " */
        "c",                       /* copyright */
        "\033S\\0a\010_\033T",     /* a_ */
        "<",                       /* << */
        "~",                       /* - */
        "-",                       /* SHY */
        "r",                       /* registered trademark */
        "-",                       /* - */
        /* more entries go here */
```
   };

