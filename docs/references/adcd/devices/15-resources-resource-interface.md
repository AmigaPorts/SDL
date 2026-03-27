---
title: 15 Resources / Resource Interface
manual: devices
chapter: devices
section: 15-resources-resource-interface
functions: [OpenResource]
libraries: [exec.library]
---

# 15 Resources / Resource Interface

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

Resources provide functions that you call to do low-level operations with
the hardware they access.  In order to use the functions of a resource,
you must obtain a pointer to the resource.  This is done by calling the
[OpenResource()](autodocs-2.0/exec-library-openresource.md) function with the resource name as its argument.

[OpenResource()](autodocs-2.0/exec-library-openresource.md) returns a pointer to the resource you request or NULL
if it does not exist.


```c
    #include <resources/filesysres.h>

    struct FileSysResource *FileSysResBase = NULL;

    if (!(FileSysResBase = OpenResource(FSRNAME)))
        printf("Cannot open %s\n",FSRNAME);
```
There is no CloseResource() function.  When you are done with a resource,
you are done with it.  However, as you will see later in this chapter,
some resources provide functions to allocate parts of the hardware they
access. In those cases, you will have to free those parts for anyone else
to use them.

Each resource has at least one include file in the resources subdirectory
of the include directory.  Some of the include files contain only the name
of the resource; others list structures and bit definitions used by the
resource.  The include files will be listed at the end of this chapter.

Calling a resource function is the same as calling any other function on
the Amiga.  You have to know what parameters it accepts and the return
value, if any.  The Autodocs for each resource lists the functions and
their requirements.


```c
    #include <hardware/cia.h>
    #include <resources/cia.h>

    struct Library *CIAResource = NULL;

    void main()
    {

    WORD mask = 0;

    if (!(CIAResource = OpenResource(CIABNAME)))
        printf("Cannot open %s\n",CIABNAME);
    else
       {
        /* What is the interrupt enable mask? */
         mask = AbleICR(CIAResource,0);

        printf("\nThe CIA interrupt enable mask: %x \n",mask);
       }
    }
```
   Looks Can Be Deceiving.
   -----------------------
   Some resources may look like libraries and act like libraries, but be
   assured they are not libraries.

---

## See Also

- [OpenResource — exec.library](../autodocs/exec.library.md#openresource)
