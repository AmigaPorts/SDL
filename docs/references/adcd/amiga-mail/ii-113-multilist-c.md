---
title: II-113/multilist.c
manual: amiga-mail
chapter: amiga-mail
section: ii-113-multilist-c
functions: [IoErr, Lock, UnLock]
libraries: [dos.library]
---

# II-113/multilist.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* multilist.c -- execute me to compile me
sc data=near nominc strmer streq nostkchk saveds ign=73 multilist
slink FROM LIB:c.o multilist.o TO multilist LIB LIB:sc.lib LIB:amiga.lib
quit
*/

/* This example illustrates how to scan DOS file names without      */
/* having to make a special case for assigns and multiassigns.      */
/* The DoAllAssigns() routine accepts an arbitrary dos path and     */
/* a pointer to a function.  DoAllAssigns() will call this function */
/* passing it a lock to the object named in the path.               */

#define BUFSIZE 1024

#include <exec/types.h>
#include <exec/memory.h>
#include <dos/dosextens.h>
#include <dos/exall.h>

#include <clib/dos_protos.h>
#include <clib/exec_protos.h>
#include <stdio.h>
#include <strings.h>

BOOL DoAllAssigns(char *, BOOL (*)());
BOOL ListContents(BPTR);

extern struct DosLibrary *DOSBase;


void main(int argc, char **argv)
{
```c
    if (DOSBase->dl_lib.lib_Version >= 37)
    {
        if (argc > 1)
        {
            (void) DoAllAssigns(argv[1], &ListContents);
        }
    }
```
}

       /* Pass this routine a directory lock and it prints the names of the  */
       /* files and directories in that directory.  If you pass this routine */
       /* a file lock, it just prints the file's name.                       */
BOOL ListContents(BPTR lock)
{
```c
    struct ExAllControl  *myeac;
    struct ExAllData     *myead;
    APTR                 buffer;
    BOOL                 done;
    struct FileInfoBlock *myfib;

    if (myfib = AllocDosObject(DOS_FIB, NULL))
    {
        if (Examine(lock, myfib) == DOSTRUE)
        {
            if (myfib->fib_DirEntryType > 0)
            {
                if (buffer = AllocVec(BUFSIZE, MEMF_PUBLIC))
                {
                    if (myeac = AllocDosObject(DOS_EXALLCONTROL, NULL))
                    {
                        myeac->eac_LastKey = 0;

                        do
                        {
                            done = ExAll(lock, buffer, BUFSIZE, ED_NAME, myeac);
                            myead = buffer;
                            while (myead)
                            {
                                printf("%s\n", myead->ed_Name);
                                myead = myead->ed_Next;
                            }
                        } while (done != 0);
                        FreeDosObject(DOS_EXALLCONTROL, myeac);
                    }
                    FreeVec(buffer);
                }
            }
            else printf("%s\n", myfib->fib_FileName);
        }
        FreeDosObject(DOS_FIB, myfib);
    }
    return TRUE;
```
}



/* This routine accepts a path string that may include a device name. From   */
/* that string, this routine locks the object named in the path and calls    */
/* the function passback_func() on the lock.  DoAllAssigns() should work on  */
/* paths with assigns and multiassigns, as well as a filesystem-based device */
/* (i.e. df0:, work:, ram:, etc.)                                            */

BOOL DoAllAssigns(char *dos_path, BOOL (*passback_func)(BPTR lock))
{
```c
    struct DevProc *dp=NULL;
    struct MsgPort *old_fsport;
    BPTR           lock, old_curdir;
    char           *rest_of_path;


    while(dp = GetDeviceProc(dos_path, dp))
    {                                        /* I need to cut the device name from  */
        rest_of_path = strchr(dos_path,':'); /* the front of dos_path so I can give */
                                             /* that substring to Lock().           */
        if (rest_of_path == NULL)                 /* There was no device name to    */
            rest_of_path = dos_path;              /* cut off, use the whole string. */
        else
            rest_of_path++;     /* Increment string pointer to just past the colon. */



        old_fsport = SetFileSysTask(dp->dvp_Port); /* in case dp->dvp_Lock is NULL. */
        old_curdir = CurrentDir(dp->dvp_Lock);     /* Lock() locks relative to the  */
                                /* current directory and falls back to the root of  */
                                /* the current file system if dp->dvp_Lock is NULL. */

        lock = Lock(rest_of_path,SHARED_LOCK);

        (void) SetFileSysTask(old_fsport); /* reset the process' default filesystem */
        (void) CurrentDir(old_curdir);     /* port and current dir to their initial */
                                           /* values for clean up later.            */

        if (lock)
        {
            if (!(*passback_func)(lock))
            {
                printf("function returned false\n");
                UnLock(lock);         /* UnLock() will ignore NULL lock */
                FreeDeviceProc(dp);
                return FALSE;
            }
            UnLock(lock);
        }
    }
    if (IoErr() == ERROR_NO_MORE_ENTRIES)
        return TRUE;               /* At present, a bug in DOS prevents this case, */
    else                           /* so DoAllAssigns() always returns FALSE.      */
        return FALSE;
```
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Lock — dos.library](../autodocs/dos.library.md#lock)
- [UnLock — dos.library](../autodocs/dos.library.md#unlock)
