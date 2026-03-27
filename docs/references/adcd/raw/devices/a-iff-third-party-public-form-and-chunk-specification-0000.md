# A / IFF Third Party Public Form and Chunk Specification / 0000.CSET.doc


Chunk for specifying character set

Registered by Martin Taillefer.

A chunk for use in any FORM, to specify character set used for text in
FORM.

   struct CSet {

```c
           LONG    CodeSet;       /* 0=ECMA Latin 1 (std Amiga charset) */
           LONG    Reserved[7];   /* CBM will define additional values  */
           }
```
