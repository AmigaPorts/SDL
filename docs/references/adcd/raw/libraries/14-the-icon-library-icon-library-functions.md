# 14 / The Icon Library / Icon Library Functions


The icon library functions do all the work needed to read, write and
examine an icon's [.info](../Libraries_Manual_guide/node0238.html) file and corresponding [DiskObject](../Libraries_Manual_guide/node0241.html) structure:


struct DiskObject *GetDiskObject(UBYTE *name);
struct DiskObject *GetDiskObjectNew(UBYTE *name);                     (V36)
BOOL               PutDiskObject(UBYTE *name, struct DiskObject *diskobj);
void               FreeDiskObject(struct DiskObject *diskobj);
BOOL               DeleteDiskObject(UBYTE *);                         (V37)

UBYTE             *FindToolType(UBYTE **toolTypeArray, UBYTE *typeName);
BOOL               MatchToolValue(UBYTE *typeString, UBYTE *value);

struct DiskObject *GetDefDiskObjectNew(LONG type);                    (V36)
BOOL               PutDefDiskObject(struct DiskObject *diskobj);      (V36)

UBYTE             *BumpRevision(UBYTE *newbuf, UBYTE *oldname);


The icon library routine [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html) reads an icon's [.info](../Libraries_Manual_guide/node0238.html) file from
disk into a [DiskObject](../Libraries_Manual_guide/node0241.html) structure it creates in memory where it can be
examined or altered.  [PutDiskObject()](../Includes_and_Autodocs_2._guide/node018E.html) writes the DiskObject out to disk
and [FreeDiskObject()](../Includes_and_Autodocs_2._guide/node0187.html) frees the memory it used. If you modify any pointers
in a DiskObject acquired via GetDiskObject(), replace the old pointers
before calling FreeDiskObject() so that the proper memory will be freed.

Release 2 includes a new function named [GetDiskObjectNew()](../Includes_and_Autodocs_2._guide/node018B.html) that works the
same as [GetDiskObject()](../Includes_and_Autodocs_2._guide/node018A.html), except that if no [.info](../Libraries_Manual_guide/node0238.html) file is found, a default
[DiskObject](../Libraries_Manual_guide/node0241.html) will be created for you.  Also new for Release 2 is
[DeleteDiskObject()](../Includes_and_Autodocs_2._guide/node0185.html) for removing .info files from disk, and the functions
[GetDefDiskObject()](../Includes_and_Autodocs_2._guide/node0189.html) and [PutDefDiskObject()](../Includes_and_Autodocs_2._guide/node018D.html) which allow the default icons in
ROM to be copied or replaced with new defaults in RAM.

Once an icon's [.info](../Libraries_Manual_guide/node0238.html) file has been read into a [DiskObject](../Libraries_Manual_guide/node0241.html) structure, the
functions [FindToolType()](../Libraries_Manual_guide/node0244.html#line44) and [MatchToolValue()](../Libraries_Manual_guide/node0244.html#line44) can be used to examine the
icon's Tool Types array.

