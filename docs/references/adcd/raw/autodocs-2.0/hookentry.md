# HookEntry



NAME

```c
    HookEntry -- call-back stub vector (LANGUAGE SPECIFIC LINK ROUTINE)
```
SYNOPSIS

    This function is never called directly by the client.
FUNCTION

```c
    HookEntry's purpose is to do language-specific setup and conversion
    of parameters passed from a library to a client call-back routine.
    Under Kickstart 2.0, a standard for call-backs has been established.
    The registers will contain the following items:

            A0:     pointer to hook that enabled us to get here.
            A2:     pointer to "object."
            A1:     pointer to "message packet."

    In iffparse, the "object" will vary from routine to routine.  The
    "message packet" is also specific to the operation involved (RTFM!).

    THIS ROUTINE IS NOT PART OF IFFPARSE.  It, or something similar, is
    part of the compiler vendor's link library.  (If it's not there,
    cobbling up your own isn't too hard.)
```
SEE ALSO

```c
    [EntryHandler()](../Includes_and_Autodocs_2._guide/node01BF.html), [ExitHandler()](../Includes_and_Autodocs_2._guide/node01C0.html), [InitIFF()](../Includes_and_Autodocs_2._guide/node01CA.html), [SetLocalItemPurge()](../Includes_and_Autodocs_2._guide/node01D8.html),
    [utility/hooks.h](../Includes_and_Autodocs_2._guide/node012D.html) (A must-read;  LOTS of details in there)
```
