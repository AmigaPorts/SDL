---
title: VIII-31/SendNote.c
manual: amiga-mail
chapter: amiga-mail
section: viii-31-sendnote-c
functions: [ReadArgs]
libraries: [dos.library]
---

# VIII-31/SendNote.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

;/* sendnote.c - Execute to compile with SAS/C 6.56
sc DATA=FAR NMINC STRMERGE STREQ NOSTKCHK SAVEDS IGNORE=73 sendnote.c
slink FROM LIB:c.o sendnote.o TO sendnote LIBRARY LIB:sc.lib LIB:amiga.lib
quit
*/

/* (c)  Copyright 1992-1999 Amiga, Inc.   All rights reserved. */
/* The information contained herein is subject to change without    */
/* notice, and is provided "as is" without warranty of any kind,    */
/* either expressed or implied.  The entire risk as to the use of   */
/* this information is assumed by the user.                         */

/*
** Our Application Prototypes (specific to notes.c file)
*/

void    main( int, char ** );
void    FinalExit( int );

/*
** Application-specific defines and globals
*/

char Version[] = "\0$VER: SendNote 1.2 (1.12.91)";

#define TEMPLATE    "Host/A,Text,Button"
#define OPT_HOST    0
#define OPT_TEXT    1
#define OPT_BUTTON  2
#define OPT_COUNT   3

/*
** The library bases...we need em later...
*/

struct Library *IntuitionBase, *SockBase;

/*
** All other includes and protos are indexed off our catch-all file
** note.h which both the client (sendnote.c) and server (shownote.c)
** include.
*/

#include    "note.h"


void    main(int argc, char **argv)
{

```c
    struct RDArgs *rdargs;      /* ReadArgs() return information */

    struct sockaddr_in serv;    /* Server's Internet Address */

    struct hostent *host;       /* The located host info */

    struct NetNote out;         /* Message packet for send/recv */

    long opts[OPT_COUNT] =  {
                            0L,
                            (long)"== PING! ==",
                            (long)"OK"
                            };

    int sock;                   /* The working socket */

    char *hostnam,                  /* Arg of hostname */
         *text,                 /* Arg of text to be sent */
         *button;               /* Arg of button text */

    /*
    ** Process arguments using new (2.0) dos calls.
    */

    rdargs = (struct RDArgs *)ReadArgs( (UBYTE *)TEMPLATE, opts, NULL );
    if(rdargs == NULL)
    {
        puts("Command line not accepted!");
        FinalExit( RETURN_ERROR );
    }

    hostnam = (char *)opts[OPT_HOST];
    text = (char *)opts[OPT_TEXT];
    button  = (char *)opts[OPT_BUTTON];

    /*
    **  Open socket.library and intialize socket space
    */

    if (SockBase = OpenLibrary("inet:libs/socket.library", 0L))
    {
        setup_sockets( 1, &errno );
    }
    else
    {
        puts("Can't open socket.library!");
        FinalExit( RETURN_ERROR );
    }

    /*
    ** First we need to try and resolve the host machine as a
    ** normal IP/Internet address.  If that fails, fall back to seaching
    ** the hosts file for it.  Before anything, we need to clear out
    ** the buffer (serv) where the information will be placed, using
    ** the bzero() call (actually a macro in sys/types.h).
    */

    bzero( &serv, sizeof(struct sockaddr_in) );
    if ( (serv.sin_addr.s_addr = inet_addr(hostnam)) == INADDR_NONE )
    {
        /*
        ** Okay, the program wasnt handed a dotted decimal address,
        ** so we check and see if it was handed a machine name.
        **
        ** NOTE:  Grab the information you need before you use the
        **        gethostbyname() call again.  Subsequent calls
        **        will overwrite the buffer it hands back.
        */

        if ( (host = gethostbyname(hostnam)) == NULL )
        {
            printf("Host not found: %s\n",host);
            FinalExit( RETURN_ERROR );
        }

        /*
        ** It does indeed have a name, so copy the addr field from the
        ** hostent structure into the sockaddr structure.
        */

        bcopy( host->h_addr, (char *)&serv.sin_addr, host->h_length );
    }
```
/*
**  Following is commented out for ease of testing purposes!  Normally, apps
**  should obtain server numbers using this type of code and a matching entry
**  in the inet:db/services file.
**
**  {
**      struct servent *servptr;
**      char *servnam = APPNAME;
**
**      *
**      ** Open the INET:DB/SERVICES file and locate the server info
**      ** by matching the name and service.
**      *
**
**      if ((servptr = getservbyname( servnam, "tcp" )) == NULL)
**      {
**          printf("%s not in inet:db/services list!",servnam);
**          FinalExit( RETURN_ERROR );
**      }
**      serv.sin_port = servptr->s_port;
**  }
**
*/


```c
    /*
    ** If you used the above code, you would remove this line:
    */

    serv.sin_port = 8769;

    /*
    ** This tells the system the socket in question is an Internet socket
    */

    serv.sin_family = AF_INET;

    /*
    ** Initialize the socket
    */

    if ( (sock = socket( AF_INET, SOCK_STREAM, 0 )) < 0 )
    {
        printf("socket gen: %s\n", strerror(errno));
        FinalExit( RETURN_ERROR );
    }

    /*
    ** Connect the socket to the remote socket, which belongs to the
    ** server, and which will "wake up" the server.
    */

    if ( connect( sock,
                  (struct sockaddr *)&serv,
                  sizeof(struct sockaddr) ) < 0 )
    {
        printf("connect: %s\n", strerror(errno));
        s_close( sock );
        FinalExit( RETURN_ERROR );
    }

    /*
    ** Compose the message packet for transmission
    */

    out.nn_Code = NN_MSG;
    strcpy( (char *)&out.nn_Text, text );
    strcpy( (char *)&out.nn_Button, button );

    /*
    ** Send the packet to the remote system
    */

    send( sock, (char *)&out, sizeof(struct NetNote), 0 );

    printf("\nMessage sent to %s...waiting for answer...\n", hostnam );

    /*
    ** Wait for either acknowledge or error.  This is a potential hang
    ** location if the server is mortally wounded.
    */

    recv( sock, (char *)&out, sizeof(struct NetNote), 0 );

    /*
    ** Evaluate the packet returned to us
    */

    if (out.nn_Code == NN_ACK)
    {
        printf("Response:  Button %ld pressed.\n\n", out.nn_Retval );
    }
    else
    {
        puts("Error during message send...please try again later!");
        FinalExit( RETURN_ERROR );
    }

    /*
    ** Since ReadArgs() was called inside the main() function, the pointer
    ** to the buffer it created needs to be deallocated inside main().
    */

    if (rdargs)
    {
        FreeArgs( rdargs );
    }

    FinalExit( RETURN_OK );
```
}

/*
**  FinalExit() - Non-returning routine which handles exits and cleanups.
**
**
*/

void    FinalExit( int retcode )
{

	/*
	** If SockBase is non-null, it means that socket.library was opened,
	** and a socket environment was initialized.  Remove the environment
	** and close the library.
	*/


```c
    if (SockBase)
    {
        cleanup_sockets();
        CloseLibrary(SockBase);
    }
```
	/*
	** Terminate program, handing return code out to the shell handler
	*/

```c
    exit( retcode );
```
}

---

## See Also

- [ReadArgs — dos.library](../autodocs/dos.library.md#readargs)
