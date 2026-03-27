---
title: II-95/InOutCTRL-C.c
manual: amiga-mail
chapter: amiga-mail
section: ii-95-inoutctrl-c-c
functions: [AllocDosObject, CreateMsgPort, Input, Output]
libraries: [dos.library, exec.library]
---

# II-95/InOutCTRL-C.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* InOutCTRL-C.c - Execute me to compile me with SAS/C 6.56
sc DATA=FAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 InOutCTRL-C.c
slink FROM LIB:c.o,InOutCTRL-C.o TO InOutCTRL-C LIBRARY LIB:sc.lib,LIB:amiga.lib,lib:debug.lib
quit ;*/

/* (c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved.       */
/* The information contained herein is subject to change without notice,  */
/* and is provided "as is" without warranty of any kind, either expressed */
/* or implied.  The entire risk as to the use of this information is      */
/* assumed by the user.                                                   */


/* InOutCTRL-C.c uses packets to copy the standard input channel to the        */
/* standard output channel using asynchronous I/O.  This example does a better */
/* job checking for a user break than the accompanying example, CompareIO.c.   */

#include <exec/types.h>
#include <dos/dosextens.h>

#include <clib/dos_protos.h>
#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/alib_stdio_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }                    /* Disable Lattice CTRL/C handling */
void chkabort(void) { return; }
#endif


#define BUFSIZE 8192

UBYTE *vers = "\0$VER: InOutCTRL-C 37.9 Nov-12-92";

void MainLoop(void);

extern struct Library *DOSBase;

struct MsgPort  *myport;
ULONG portsignal, signals, sigmask;

struct FileHandle *in, *out;
struct DosPacket *sp_read, *sp_write;

UBYTE buf1[BUFSIZE], buf2[BUFSIZE];

void main(void)
{
  if (DOSBase->lib_Version >= 37)                                        /* 2.0 only */
  {
```c
    if (myport = CreateMsgPort())
    {
      if (in = (struct FileHandle *)BADDR(Input()))        /* Need file handle to    */
      {                                                    /* get to Handler process */
        if (out = (struct FileHandle *)BADDR(Output()))
        {
          if (sp_read = AllocDosObject(DOS_STDPKT, NULL))    /* Allocate two         */
          {                                                  /* StandardPackets: one */
            if (sp_write = AllocDosObject(DOS_STDPKT, NULL)) /* for reading, and one */
            {                                                /* for writing. */

              sp_read->dp_Type = ACTION_READ;    /* Fill out the ACTION_READ packet. */
              sp_read->dp_Arg1 = in->fh_Arg1;
              sp_read->dp_Arg2 = (LONG)buf1;     /* The buffer to fill in.           */
              sp_read->dp_Arg3 = BUFSIZE;        /* The size of the Arg2 buffer.     */

                       /* When AllocDosObject() allocates a StandardPacket, it takes */
                       /* care of linking together the Message and DosPacket.        */
                       /* AllocDosObject() points the DosPacket's dp_Link field at   */
                       /* the StandardPacket's Message structure.  It also points    */
                       /* the Message's mn_Node.ln_Name field at the DosPacket:      */
                       /*                 sp_read->dp_Link = sp_Msg;                 */
                       /*                 sp_Msg->mn_Node.ln_Name = (STRPTR)sp_read; */


              if (!((out->fh_Arg1) && (in->fh_Arg1)))     /* Don't bother if in or   */
                return;                                   /*          out uses NIL:  */

              SendPkt(sp_read, in->fh_Type, myport);   /* Send initial read request. */

              portsignal = 1L<<myport->mp_SigBit;          /* Record the signal bits */
              sigmask    = SIGBREAKF_CTRL_C | portsignal;  /*         for later use. */

              sp_write->dp_Type = ACTION_WRITE; /* Fill out the ACTION_WRITE packet. */
              sp_write->dp_Arg1 = out->fh_Arg1;
              sp_write->dp_Arg2 = (LONG)buf2;  /* Arg2 points to the buffer to write */
              sp_write->dp_Arg3 = 0L;          /* out.  At first glance, it might    */
              sp_write->dp_Res1 = 0L;          /* seem odd to bother setting Arg2    */
                                      /* when the program hasn't read anything yet.  */
                                      /* This is to set up for the main loop.  The   */
                                      /* main loop swaps the ACTION_READ buffer with */
                                      /* the ACTION_WRITE buffer when it receives    */
                                      /* a completed read.  Likewise, dp_Arg3 and    */
                                      /* dp_Res1 are set to make the ACTION_READ     */
                                      /* look like it has a valid return value so    */
                                      /* main loop won't fail the first time through */
                                      /* the loop.                                   */
              MainLoop();
              FreeDosObject(DOS_STDPKT, sp_write);
            }
            FreeDosObject(DOS_STDPKT, sp_read);
          }
        }
      }
      DeleteMsgPort(myport);
    }
```
  }
}


void MainLoop()
{
struct StandardPacket *mysp;
UBYTE *buf;

LONG amount_read;

BOOL sp_read_busy  = TRUE,                    /*    Is the ACTION_READ packet busy?  */
```c
     sp_write_busy = FALSE,                   /*    Is the ACTION_WRITE packet busy? */
     done           = FALSE;                  /*    Is the program finished?         */

                /* main() has already taken care of sending the initial read to the  */
                /* handler.  Because we need the data from that read before we can   */
```
  while (!done) /* do anything, the first thing to do is wait for its return.        */
  {
```c
    do                                   /*      Wait for the ACTION_READ to return. */
    {
      signals = Wait(sigmask);           /*          Wait for port signal or CTRL-C. */

      if (signals & portsignal)          /* If a message arrived at the port, ...    */
      {
        while (mysp = (struct StandardPacket *)GetMsg(myport)) /* ...empty the port. */
        {
                          /* If this message is the ACTION_READ packet, mark it as   */
                          /* no longer busy so we can use it to start another read.  */
          if (mysp->sp_Pkt.dp_Type == ACTION_READ)    sp_read_busy  = FALSE;

                          /* If this message is instead the ACTION_WRITE packet,     */
                          /* mark it as not busy.  We need to check for this because */
                          /* the WRITE_PACKET from the previous interation through   */
                          /* the loop might have come back before the ACTION_WRITE   */
                          /* from the previous interation.                           */
          else
            if (mysp->sp_Pkt.dp_Type == ACTION_WRITE) sp_write_busy = FALSE;
        }
      }

      if (signals & SIGBREAKF_CTRL_C) /* If someone hit CTRL-C, start to quit. */
      {
        done = TRUE;                      /* If the ACTION_READ is still out, try to */
        if (sp_read_busy)                 /* abort it.  As of V39, AbortPkt() does   */
          AbortPkt(in->fh_Type, sp_read); /* not do anything, so this function has   */
      }                                   /* no effect. Maybe a later release of the */
                                          /* OS will support packet aborting.        */


    } while (sp_read_busy);                   /* End of "wait for ACTION_READ" loop. */

                                          /* Get ready to send the next ACTION_READ. */
    buf = (UBYTE *)(sp_read->dp_Arg2);    /* Hold on to the important stuff from the */
    amount_read = sp_read->dp_Res1;       /* ACTION_READ we just got back so we can  */
                                          /* reuse the packet to start a new read    */
                                          /* while processing the last read's data.  */

    while (sp_write_busy)          /* Because this example only uses two buffers and */
    {                              /* the ACTION_WRITE might be using one of them,   */
                                   /* this example has to wait for an outstanding    */
                                   /* ACTION_WRITE to return before reusing the      */
                                   /* ACTION_WRITE packet's buffer.                  */
      signals = Wait(sigmask);

      if (signals & portsignal)           /*  If a message arrived at the port, ...  */
      {                                              /*          ... empty the port. */
        while (mysp = (struct StandardPacket *)GetMsg(myport))
          if (mysp->sp_Pkt.dp_Type == ACTION_WRITE) sp_write_busy = FALSE;
      }

      if (signals & SIGBREAKF_CTRL_C)     /*   If someone hit CTRL-C, start to quit. */
      {
        done = TRUE;                      /* If the ACTION_READ is still out, try to */
        if (sp_write_busy) AbortPkt(out->fh_Type, sp_write);            /* abort it. */
      }
    }

               /* Make sure the user didn't hit CTRL-C.  If the user hit CTRL-C dur- */
    if (!done) /* ing one of the "wait for packet" loops, done == TRUE.  Notice that */
    {          /* this example does not actually break for the CTRL-C until after it */
               /* gets back both packets.                                            */

               /* This tests the return values from the ACTION_READ and ACTION_WRITE */
               /* packets.  The ACTION_READ packet returns the number of bytes it    */
               /* read in dp_Res1, which was copied earlier into amount_read. If it  */
               /* is 0, the read packet found the EOF.  If it is negative, there was */
               /* an error.  In the case of ACTION_WRITE, an error occurs if the     */
               /* number of bytes that ACTION_WRITE was supposed to write (Arg3)     */
               /* does not match the actual number it wrote, which ACTION_WRITE re-  */
               /* turns in Res1.  This test is the reason dp_Res1 and dp_Arg3 were   */
               /* set to zero when the ACTION_WRITE packet was set up in main().     */
      if ((amount_read > 0) && (sp_write->dp_Res1 == sp_write->dp_Arg3))
      {
        sp_read->dp_Arg2 = sp_write->dp_Arg2;  /* ACTION_WRITE is finished with its  */
                                               /* buffer, use it in the next read.   */

        SendPkt(sp_read, in->fh_Type, myport); /* Send the next ACTION_READ and mark */
        sp_read_busy = TRUE;                   /* the ACTION_READ as busy.           */

        /* Process Buffer.  This example doesn't do anything with the data from the  */
        /* last ACTION_READ, it just passes it on to the STDOUT handler.             */


        sp_write->dp_Arg2 = (LONG)buf;         /*    Set up the ACTION_WRITE packet. */
        sp_write->dp_Arg3 = amount_read;
        SendPkt(sp_write, out->fh_Type, myport);   /* Send the next ACTION_WRITE and */
        sp_write_busy = TRUE;                      /* mark the ACTION_WRITE as busy. */
      }
      else                             /* A packet returned with a failure, so quit. */
        done = TRUE;
    }
```
  }
}

---

## See Also

- [AllocDosObject — dos.library](../autodocs/dos.library.md#allocdosobject)
- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [Input — dos.library](../autodocs/dos.library.md#input)
- [Output — dos.library](../autodocs/dos.library.md#output)
