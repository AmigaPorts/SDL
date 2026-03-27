---
title: Devices/Dev_examples/Clipdemo.c
manual: devices
chapter: devices
section: devices-dev-examples-clipdemo-c
functions: []
libraries: []
---

# Devices/Dev_examples/Clipdemo.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/*
 * Clipdemo.c
 *
 * Demonstrate use of clipboard I/O.  Uses general functions
 * provided in cbio.c
 *
 * Compile with SAS C 5.10: LC -b1 -cfistq -v -y -L+cbio.o
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/ports.h>
#include <exec/io.h>
#include <exec/memory.h>
#include <devices/clipboard.h>
#include <libraries/dosextens.h>
#include <libraries/dos.h>

#include "cb.h"

#include <clib/exec_protos.h>
#include <clib/alib_protos.h>

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable SAS CTRL/C handling */
int chkabort(void) { return(0); }  /* really */
#endif

#define FORGETIT 0
#define READIT   1
#define WRITEIT  2
#define POSTIT   3

/* prototypes */

int ReadClip( void );           /* Demonstrate reading clipboard data    */
int WriteClip( char * );        /* Demonstrate write to clipboard        */
int PostClip( char * );         /* Demonstrate posting data to clipboard */

void main( USHORT, char **);

char message[] = "\
\nPossible switches are:\n\n\
-r            Read, and output contents of clipboard.\n\
-w [string]   Write string to clipboard.\n\n\
-p [string]   Write string to clipboard using the clipboard POST mechanism.\n\n\


```c
              The Post can be satisfied by reading data from\n\
              the clipboard.  Note that the message may never\n\
              be received if some other application posts, or\n\
              performs an immediate write to the clipboard.\n\n\
              To run this test you must run two copies of this example.\n\
              Use the -p switch with one to post data, and the -r switch\n\
              with another to read the data.\n\n\
              The process can be stopped by using the BREAK command,\n\
              in which case this example checks the CLIP write ID\n\
              to determine if it should write to the clipboard before\n\
              exiting.\n\n";
```
void main(argc,argv)
USHORT argc;
char **argv;
{

int todo;
char *string;

todo = FORGETIT;

if (argc)     /* from CLI ? */
```c
    {

    /* Very simple code to parse for arguments - will suffice for
     * the sake of this example
     */

    if (argc > 1)
       {
       if (!(strcmp(argv[1],"-r")))
           todo = READIT;
       if (!(strcmp(argv[1],"-w")))
           todo = WRITEIT;
       if (!(strcmp(argv[1],"-p")))
           todo = POSTIT;

       string = NULL;

       if (argc > 2)
           string=argv[2];

       }

    switch (todo)
            {

            case READIT:

                 ReadClip();
                 break;

            case POSTIT:

                 PostClip(string);
                 break;

            case WRITEIT:

                 WriteClip(string);
                 break;

            default:

                 printf("%s",message);
                 break;

            }
    }
```
}

/*
 * Read, and output FTXT in the clipboard.
 *
 */

ReadClip()
{
struct IOClipReq *ior;
struct cbbuf *buf;


/* Open clipboard.device unit 0 */

if (ior=CBOpen(0L))

```c
    {

    /* Look for FTXT in clipboard */

    if (CBQueryFTXT(ior))
        {

        /* Obtain a copy of the contents of each CHRS chunk */

        while (buf=CBReadCHRS(ior))
              {
              /* Process data */

              printf("%s\n",buf->mem);

              /* Free buffer allocated by CBReadCHRS() */

              CBFreeBuf(buf);
              }

        /* The next call is not really needed if you are sure */
        /* you read to the end of the clip.                   */

        CBReadDone(ior);
        }
    else
        {
        puts("No FTXT in clipboard");
        }

    CBClose(ior);
    }
```
else

```c
    {
    puts("Error opening clipboard unit 0");
    }
```
return(0L);
}

/*
 * Write a string to the clipboard
 *
 */

WriteClip(string)
char *string;
{

struct IOClipReq *ior;

if (string == NULL)

```c
    {
    puts("No string argument given");
    return(0L);
    }
```
/* Open clipboard.device unit 0 */

if (ior = CBOpen(0L))
```c
    {
    if (!(CBWriteFTXT(ior,string)))
        {
        printf("Error writing to clipboard: io_Error = %ld\n",ior->io_Error);
        }
    CBClose(ior);
    }
```
else

```c
    {
    puts("Error opening clipboard.device");
    }
```
return(0);
}


/*
 * Write a string to the clipboard using the POST mechanism
 *
 * The POST mechanism can be used by applications which want to
 * defer writing text to the clipboard until another application
 * needs it (by attempting to read it via CMD_READ).  However
 * note that you still need to keep a copy of the data until you
 * receive a SatisfyMsg from the clipboard.device, or your program
 * exits.
 *
 * In most cases it is easier to write the data immediately.
 *
 * If your program receives the SatisfyMsg from the clipboard.device,
 * you MUST write some data.  This is also how you reply to the message.
 *
 * If your program wants to exit before it has received the SatisfyMsg,
 * you must check the io_ClipID field at the time of the post against
 * the current post ID which is obtained by sending the CBD_CURRENTWRITEID
 * command.
 *
 * If the value in io_ClipID (returned by CBD_CURRENTWRITEID) is greater
 * than your post ID, it means that some other application has performed
 * a post, or immediate write after your post, and that you're application
 * will never receive the SatisfyMsg.
 *
 * If the value in io_ClipID (returned by CBD_CURRENTWRITEID) is equal
 * to your post ID, then you must write your data, and send CMD_UPDATE
 * before exiting.
 *
 */

PostClip(string)
char *string;
{

struct MsgPort *satisfy;
struct SatisfyMsg *sm;
struct IOClipReq *ior;
int mustwrite;
ULONG postID;

if (string == NULL)

```c
    {
    puts("No string argument given");
    return(0L);
    }
```
if (satisfy = CreatePort(0L,0L))
```c
    {

    /* Open clipboard.device unit 0 */

    if (ior = CBOpen(0L))
        {
        mustwrite = FALSE;

        /* Notify clipboard we have data */

        ior->io_Data    = (STRPTR)satisfy;
        ior->io_ClipID  = 0L;
        ior->io_Command = CBD_POST;
        DoIO( (struct IORequest *) ior);

        postID = ior->io_ClipID;

        printf("\nClipID = %ld\n",postID);

        /* Wait for CTRL-C break, or message from clipboard */
        Wait(SIGBREAKF_CTRL_C|(1L << satisfy->mp_SigBit));

        /* see if we got a message, or a break */
        puts("Woke up");


        if (sm = (struct SatisfyMsg *)GetMsg(satisfy))
            {
            puts("Got a message from the clipboard\n");

            /* We got a message - we MUST write some data */
            mustwrite = TRUE;
            }
        else
            {
            /* Determine if we must write before exiting by
             * checking to see if our POST is still valid
             */

            ior->io_Command = CBD_CURRENTWRITEID;
            DoIO( (struct IORequest *) ior);

            printf("CURRENTWRITEID = %ld\n",ior->io_ClipID);

            if (postID >= ior->io_ClipID)
                mustwrite = TRUE;

            }

        /* Write the string of text */

        if (mustwrite)
            {
            if (!(CBWriteFTXT(ior,string)))
                puts("Error writing to clipboard");
            }
        else
            {
            puts("No need to write to clipboard");
            }

        CBClose(ior);
        }
    else
        {
        puts("Error opening clipboard.device");
        }

    DeletePort(satisfy);
    }
```
else

```c
    {
    puts("Error creating message port");
    }
```
return(0);
}


/*
 * Changehook_Test.c
 *
 * Demonstrate the use of CBD_CHANGEHOOK command.
 * The program will set a hook and wait for the clipboard data to change.
 * You must put something in the clipboard in order for it to return.
 *
 * Compile with SAS C 5.10: LC -cfist -v -y -L+Hookface.o+cbio.o
 *
 * Requires Kickstart 36 or greater.
 *
 * Run from CLI only
 */

#include <exec/types.h>
#include <exec/memory.h>
#include <exec/ports.h>
#include <exec/tasks.h>
#include <exec/io.h>
#include <devices/clipboard.h>
#include <dos/dos.h>
#include <utility/hooks.h>
#include "cb.h"

#include <clib/macros.h>
#include <clib/alib_protos.h>
#include <clib/exec_protos.h>

#include <stdio.h>
#include <string.h>


LONG version = 1L;

extern ULONG SysBase, DOSBase;

/* Data to pass around with the clipHook */
struct CHData
{
```c
    struct Task *ch_Task;
    LONG ch_ClipID;
```
};

struct MsgPort *clip_port;
struct Hook hook;
struct CHData ch;

ULONG clipHook (struct Hook * h, VOID * o, struct ClipHookMsg * msg)
{
struct CHData *ch = (struct CHData *) h->h_Data;

if (ch)
   {
   /* Remember the ID of clip */
   ch->ch_ClipID = msg->chm_ClipID;

   /* Signal the task that started the hook */
   Signal (ch->ch_Task, SIGBREAKF_CTRL_E);
   }

return (0);
}

struct IOClipReq *OpenCB (LONG unit)
{
struct IOClipReq *clipIO;

/* Open clipboard unit 0 */

if (clipIO = CBOpen( 0L ))

```c
    {
    ULONG hookEntry ();

    /* Fill out the IORequest */
    clipIO->io_Data = (char *) &hook;
    clipIO->io_Length = 1;
    clipIO->io_Command = CBD_CHANGEHOOK;

    /* Set up the hook data */
    ch.ch_Task = FindTask (NULL);

    /* Prepare the hook */
    hook.h_Entry = hookEntry;
    hook.h_SubEntry = clipHook;
    hook.h_Data = &ch;

    /* Start the hook */
    if (DoIO (clipIO))
        printf ("unable to set hook\n");
    else
        printf ("hook set\n");

    /* Return success */
    return ( clipIO );
    }
```
/* return failure */
return (NULL);
}

void CloseCB (struct IOClipReq *clipIO)
{

/* Fill out the IO request */
clipIO->io_Data = (char *) &hook;
clipIO->io_Length = 0;
clipIO->io_Command = CBD_CHANGEHOOK;

    /* Stop the hook */
if (DoIO (clipIO))
```c
    printf ("unable to stop hook\n");
```
else

```c
    /* Indicate success */
    printf ("hook is stopped\n");
```
CBClose(clipIO);
}

main (int argc, char **argv)
{
struct IOClipReq *clipIO;

ULONG sig_rcvd;

printf ("Test v%ld\n", version);

if (clipIO=OpenCB (0L))
```c
    {
    sig_rcvd = Wait ((SIGBREAKF_CTRL_C | SIGBREAKF_CTRL_E));

    if (sig_rcvd & SIGBREAKF_CTRL_C)
        printf ("^C received\n");

    if (sig_rcvd & SIGBREAKF_CTRL_E)
        printf ("clipboard change, current ID is %ld\n", ch.ch_ClipID);

    CloseCB(clipIO);
    }
```
}

