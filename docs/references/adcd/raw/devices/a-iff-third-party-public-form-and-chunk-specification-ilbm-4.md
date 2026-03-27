# A / IFF Third Party Public Form and Chunk Specification / ILBM.EPSF.doc


Encapsulated Postscript chunk

ILBM EPSF Chunk
---------------

Pixelations   Kevin Saltzman   617-277-5414

Chunk to hold encapsulated postscript

Used by PixelScript in their clip art.  Holds a postscript representation
of the ILBM's graphic image.

EPSF length
   ; Bounding box
   WORD lowerleftx;
   WORD lowerlefty;
   WORD upperrightx;
   WORD upperrighty;
   CHAR []    ; ascii postscript file

