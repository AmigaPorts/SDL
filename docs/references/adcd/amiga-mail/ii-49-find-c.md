---
title: II-49/Find.c
manual: amiga-mail
chapter: amiga-mail
section: ii-49-find-c
functions: [IoErr, Output]
libraries: [dos.library]
---

# II-49/Find.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* Find.c - Amiga Mail ExAll() example.
sc NMINC STRMERGE NOSTKCHK NODEBUG DATA=FAR IGNORE=73 Find.c
slink from Find.o to Find lib lib:amiga.lib; if you don't have pragmas
quit
 *
 * Pure code if pragmas are used.
 * Tuesday, 16-Jul-91 16:21:14, Ewout
 *
 * Compiled with SAS/C 6.56
 */
/*
Copyright (c) 1991-1999 Amiga, Inc.

This example is provided in electronic form by Amiga, Inc.
for use with the Amiga Mail Volume II technical publication.
Amiga Mail Volume II contains additional information on the correct
usage of the techniques and operating system functions presented in
these examples.  The source and executable code of these examples may
only be distributed in free electronic form, via bulletin board or
as part of a fully non-commercial and freely redistributable
diskette.  Both the source and executable code (including comments)
must be included, without modification, in any copy.  This example
may not be published in printed form or distributed with any
commercial product. However, the programming techniques and support
routines set forth in these examples may be used in the development
of original executable software products for Amiga
computers.

All other rights reserved.

This example is provided "as-is" and is subject to change; no
warranties are made.  All use is at your own risk. No liability or
responsibility is assumed.
*/

#include <exec/memory.h>
#include <dos/dosextens.h>
#include <dos/rdargs.h>
#include <dos/exall.h>

#include <clib/exec_protos.h>
#include <clib/dos_protos.h>
#include <clib/utility_protos.h>

/* undef PRAGMAS if you don't have them */
/* #define PRAGMAS */
#undef PRAGMAS
#ifdef PRAGMAS
#include <pragmas/exec_pragmas.h>
#include <pragmas/dos_pragmas.h>
#include <pragmas/utility_pragmas.h>
#else
struct ExecBase *SysBase;
struct DosLibrary *DOSBase;
struct Library *UtilityBase;

#endif

/* ExAll buffersize to receive data in */
#define BUFFERSIZE 512
/* Default buffersize for hold fully qualified filenames */
#define NAMEBUFFERSIZE 512

/* Used to pass data around to functions */
struct FindControl
{
  struct DosLibrary *fc_DOSBase;
  UBYTE          *fc_Parsebuffer;       /* Buffer which contains the parsed pattern */
  ULONG           fc_Parselength;       /* The length of this buffer */
  UBYTE          *fc_Namebuffer;        /* Buffer to hold the filename */
  ULONG           fc_Namelength;        /* The length of that buffer */
  BOOL            fc_Files;  /* BOOLEAN which tells if we should only look for files */
  BOOL            fc_Dirs;   /* BOOLEAN which tells if we should only look for dirs */
  BOOL            fc_All;    /* ALL keyword? */
};

static UBYTE   *VersTag = "\0$VER: Find 37.1 (16.07.91)";

LONG            main(VOID);
LONG            ScanDirectory(struct FindControl *, UBYTE *);
BOOL            IsAssign(struct FindControl *, UBYTE *);
LONG            MultiScanDirectory(struct FindControl *, UBYTE *);
UWORD           StrLen(UBYTE *);

LONG
main(VOID)
{
#ifdef PRAGMAS
  struct DosLibrary *DOSBase;
  struct Library *UtilityBase;

#endif
  struct RDArgs  *readargs;
  LONG            rargs[6];
  struct FindControl *fc;
  UBYTE          *pattern, **directories;
  struct Process *process;
  APTR            windowptr;
  COUNT           i;
  LONG            rc = 0, error = 0, fatalerror = 0;

#ifndef PRAGMAS
  /* set up SysBase */
  SysBase = (*((struct Library **) 4));
#endif

  /* Fail silently if < 37 */
  if (DOSBase = (struct DosLibrary *) OpenLibrary("dos.library", 37))
  {

```c
    UtilityBase = DOSBase->dl_UtilityBase;

    rargs[0] = 0L;
    rargs[1] = 0L;
    rargs[2] = 0L;
    rargs[3] = 0L;
    rargs[4] = 0L;
    rargs[5] = 0L;

    if (readargs =
        ReadArgs("PATTERN/A,DIRECTORY/A/M,FILES/S,DIRS/S,ALL/S,BUFFER/K/N",
                 rargs,
                 NULL))
    {

      if (fc = AllocMem(sizeof(struct FindControl), MEMF_CLEAR))
      {
```
#ifdef PRAGMAS
```c
        fc->fc_DOSBase = DOSBase;
```
#endif

```c
        pattern = (UBYTE *) rargs[0];

        fc->fc_Parselength = StrLen(pattern) * 3;
        if (fc->fc_Parsebuffer = AllocMem(fc->fc_Parselength, MEMF_CLEAR))
        {

          /* Make pattern uppercase for possible character classes */
          i = 0;
          while (pattern[i])
            pattern[i] = ToUpper(pattern[i++]);

          if ((ParsePatternNoCase(pattern,
                                  fc->fc_Parsebuffer,
                                  fc->fc_Parselength)) != -1)
          {

            directories = (UBYTE **) rargs[1];

            fc->fc_Files = (BOOL) rargs[2];
            fc->fc_Dirs = (BOOL) rargs[3];
            fc->fc_All = (BOOL) rargs[4];

            /*
             * Both set or cleared, clear both anyway. Easier checking later on.
             */
            if (fc->fc_Files == fc->fc_Dirs)
              fc->fc_Files = fc->fc_Dirs = FALSE;

            if (rargs[5])
              fc->fc_Namelength = *((LONG *) rargs[5]);

            if (fc->fc_Namelength < NAMEBUFFERSIZE || fc->fc_Namelength > 4096)
              fc->fc_Namelength = NAMEBUFFERSIZE;

            if (fc->fc_Namebuffer = AllocMem(fc->fc_Namelength, MEMF_CLEAR))
            {
              process = (struct Process *) FindTask(NULL);
              windowptr = process->pr_WindowPtr;
              process->pr_WindowPtr = (APTR) - 1L;

              while (*directories)
              {

                /*
                 * Check if this is a standalone assign which appears in the assign
                 * list?
                 */
                if (IsAssign(fc, *directories))
                  error = MultiScanDirectory(fc, *directories++);
                else
                  error = ScanDirectory(fc, *directories++);

                if (error != 0)
                  break;
              }

              process->pr_WindowPtr = windowptr;

              FreeMem(fc->fc_Namebuffer, fc->fc_Namelength);
            }
            else
              fatalerror = ERROR_NO_FREE_STORE;
          }
          else
            fatalerror = ERROR_BAD_TEMPLATE;

          FreeMem(fc->fc_Parsebuffer, fc->fc_Parselength);
        }
        else
          fatalerror = ERROR_NO_FREE_STORE;
        FreeMem(fc, sizeof(struct FindControl));
      }
      else
        fatalerror = ERROR_NO_FREE_STORE;

      FreeArgs(readargs);

    }
    else
      fatalerror = IoErr();

    /*
     * Error handling: To be informative, errors are shown while scanning, so the
     * file name which caused the error can be displayed. Other errors are shown
     * here. Errors which occured in the main loop are considered fatal, others
     * (except BREAK) just error.
     */

    if (fatalerror)
    {
      error = fatalerror;
      PrintFault(fatalerror, NULL);
    }

    SetIoErr(error);
    if (error != 0)
    {
      if (fatalerror)
        rc = RETURN_FAIL;
      else if (error == ERROR_BREAK)
        rc = RETURN_WARN;
      else
        rc = RETURN_ERROR;
    }

    CloseLibrary((struct Library *) DOSBase);
```
  }
  else
```c
    rc = RETURN_FAIL;
```
  return (rc);
}


LONG
ScanDirectory(struct FindControl * fc, UBYTE * source)
{
#ifdef PRAGMAS
  struct DosLibrary *DOSBase = fc->fc_DOSBase;

#endif
  LONG            vargs[1];
  struct ExAllControl *excontrol;
  struct ExAllData *ead, *buffer;
  BPTR            sourcelock, namelock, olddirlock;
  BOOL            exmore;
  LONG            error;

  /*
   * Because this function may be recursively, get a fresh buffer per function call.
   */
  if (buffer = AllocMem(BUFFERSIZE, MEMF_CLEAR))
  {

```c
    /* Get a lock on the start directory and make it the current directory */
    if (sourcelock = Lock(source, SHARED_LOCK))
    {
      olddirlock = CurrentDir(sourcelock);

      if (excontrol = AllocDosObject(DOS_EXALLCONTROL, NULL))
      {

        do
        {
          /* Get both file name and type to support FILES/DIRS kewords */
          exmore = ExAll(sourcelock, buffer, BUFFERSIZE, ED_TYPE, excontrol);
          error = IoErr();
          if ((exmore == NULL && (error != ERROR_NO_MORE_ENTRIES)))
          {
            PrintFault(error, source);
            break;
          }
          if (excontrol->eac_Entries == 0)
            continue;

          ead = buffer;
          do
          {

            /* Check for CTRL-C */
            if (SetSignal(0L, SIGBREAKF_CTRL_C) & SIGBREAKF_CTRL_C)
            {
              error = ERROR_BREAK;
              PrintFault(error, NULL);
              exmore = FALSE;
              break;
            }

            /*
             * Check if this one matches. If it does see if it is of the right type.
             */
            if (MatchPatternNoCase(fc->fc_Parsebuffer, ead->ed_Name))
            {
              if ((ead->ed_Type < 0 && fc->fc_Dirs == FALSE)
                  || (ead->ed_Type > 0 && fc->fc_Files == FALSE))
              {
                /* It is. Lock it and get the fully qualified file name */
                if (namelock = Lock(ead->ed_Name, SHARED_LOCK))
                {
                  if ((NameFromLock(namelock,
                                    fc->fc_Namebuffer,
                                    fc->fc_Namelength)) == DOSTRUE)
                  {
                    vargs[0] = (LONG) fc->fc_Namebuffer;
                    VFPrintf(Output(), "%s\n", vargs);
                  }
                  else
                  {
                    error = IoErr();
                    PrintFault(error, ead->ed_Name);
                  }
                  UnLock(namelock);
                }
                else
                {
                  error = IoErr();
                  PrintFault(error, ead->ed_Name);
                }
              }
            }

            /*
             * If the ALL keyword is used and this is a directory, step in it by
             * calling this function recursively.
             */
            if (ead->ed_Type > 0 && fc->fc_All)
            {
              error = ScanDirectory(fc, ead->ed_Name);
              if (error != 0)
              {
                exmore = FALSE;
                break;
              }
            }
            ead = ead->ed_Next;
          } while (ead);
        } while (exmore);

        FreeDosObject(DOS_EXALLCONTROL, excontrol);

      }
      else
        error = ERROR_NO_FREE_STORE;

      CurrentDir(olddirlock);
      UnLock(sourcelock);
    }
    else
    {
      error = IoErr();
      PrintFault(error, source);
    }
    FreeMem(buffer, BUFFERSIZE);
```
  }
  else

```c
    error = ERROR_NO_FREE_STORE;
```
  if (error == ERROR_NO_MORE_ENTRIES)
```c
    error = 0;
```
  else if (error == ERROR_NO_FREE_STORE)

```c
    PrintFault(error, NULL);
```
  return (error);
}

BOOL
IsAssign(struct FindControl * fc, UBYTE * name)
{
#ifdef PRAGMAS
  struct DosLibrary *DOSBase = fc->fc_DOSBase;
  struct Library *UtilityBase = DOSBase->dl_UtilityBase;

#endif
  struct DosList *doslist;
  UBYTE          *assignname;
  UCOUNT          assignlength;
  LONG            position;
  BOOL            result = FALSE;

  /* First lets check if this resembles a devicename. */
  position = SplitName(name, ':', fc->fc_Namebuffer, 0, fc->fc_Namelength);

  if (position != -1)
  {
```c
    /* Hmmm. */
    if (name[position] == '\0')
    {

      /*
       * I guess it does. Lets see if we can find it in the assign list. Keep the
       * DoSList locked as briefly as possible. This shouldn't take long.
       */
      if (doslist = AttemptLockDosList(LDF_ASSIGNS | LDF_READ))
      {
        while (doslist = NextDosEntry(doslist, LDF_ASSIGNS))
        {

          /* It's a BPTR */
          assignname = (UBYTE *) BADDR(doslist->dol_Name);
          assignlength = assignname[0];

          if ((Strnicmp(assignname + 1, fc->fc_Namebuffer, assignlength)) == 0)
          {
            /* Yup, it is. */
            result = TRUE;
            break;
          }
        }
        UnLockDosList(LDF_ASSIGNS | LDF_READ);
      }    /* Can't lock DosList, don't bother */
    }
```
  }
  return (result);
}

LONG
MultiScanDirectory(struct FindControl * fc, UBYTE * source)
{
#ifdef PRAGMAS
  struct DosLibrary *DOSBase = fc->fc_DOSBase;

#endif
  struct DevProc *cproc = NULL;
  struct MsgPort *filesystemtask;
  LONG            error;

  filesystemtask = GetFileSysTask();

  do
  {
```c
    /* Find handler */
    if (cproc = GetDeviceProc(source, cproc))
    {
      SetFileSysTask(cproc->dvp_Port);
      if ((NameFromLock(cproc->dvp_Lock,
           fc->fc_Namebuffer,
           fc->fc_Namelength)) == DOSTRUE)
      {
        error = ScanDirectory(fc, fc->fc_Namebuffer);
      }
      else
      {
        error = IoErr();
        PrintFault(error, source);
      }

      if (error != 0)
        break;
    }
    else
    {
      error = IoErr();
      PrintFault(error, source);
    }

    /* Handle multi-assign */
```
  } while (cproc && (cproc->dvp_Flags & DVPF_ASSIGN));

  SetFileSysTask(filesystemtask);
  if (cproc)

```c
    FreeDeviceProc(cproc);
```
  return (error);
}

UWORD
StrLen(UBYTE * string)
{
  UBYTE          *length = string + 1;

  while (*string++ != '\0');
  return ((UWORD) (string - length));
}

---

## See Also

- [IoErr — dos.library](../autodocs/dos.library.md#ioerr)
- [Output — dos.library](../autodocs/dos.library.md#output)
