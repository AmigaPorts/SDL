# 16 / Creating a File Requester / The Directory Requester


Sometimes a program may only require a directory name from the user. There
is another variation on asl.library's file requester that allows this.
The ASL_ExtFlags1 tag contains a flag bit to toggle this option. If the
FIL1F_NOFILES flag of ASL_ExtFlags1 is set, the requester will appear
without a string gadget for file names and will display only directory
names in the scrolling list gadget. When [AslRequest()](../Libraries_Manual_guide/node027B.html#line43) (or [AslRequestTags()](../Libraries_Manual_guide/node027D.html#line44)
) returns successfully, the rf_Dir field of the [FileRequester](../Libraries_Manual_guide/node027B.html#line15) structure
contains the name of the directory the user selected.

Another flag defined for ASL_ExtFlags1 is FIL1F_MATCHDIRS. If file pattern
matching is on (see the [FILF_PATGAD](../Libraries_Manual_guide/node027D.html#line8) flag for ASL_FuncFlags, setting
FIL1F_MATCHDIRS tells the file requester to pattern match directory names
as well as file names.  Of course, if both of these ASL_ExtFlags1 flags
are set, the requester will only pattern match directory names.

