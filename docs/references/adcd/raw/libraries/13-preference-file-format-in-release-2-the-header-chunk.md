# 13 / / Preference File Format in Release 2 / The Header Chunk


The PRHD header chunk, contains a PrefHeader structure:


```c
    struct PrefHeader
    {
        UBYTE ph_Version;
        UBYTE ph_Type;
        ULONG ph_Flags;
    };
```
Currently all the fields are set to NULL.  In future revisions these
fields may be used to indicate a particular version and contents of a PREF
chunk.

