---
title: Lib_examples/broker.c
manual: libraries
chapter: libraries
section: lib-examples-broker-c
functions: [CreateMsgPort, CxBroker, CxMsgID, DeleteCxObjAll]
libraries: [commodities.library, exec.library]
---

# Lib_examples/broker.c

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

/* The example below, Broker.c, receives input from one source, the
 * controller program.  The controller program sends a CxMessage each
 * time the user clicks its Enable, Disable, or Kill gadgets.  Using the
 * CxMsgID() function, the commodity finds out what the command is and
 * executes it.
 *
 * broker.c - Simple skeletal example of opening a broker
 *
 * compiled with SASC 5.10
 * LC -b0 -cfist -v broker.c
 * Blink FROM LIB:c.o,broker.o TO broker LIBRARY LIB:LC.lib,LIB:Amiga.lib
 */
#include <exec/libraries.h>
#include <libraries/commodities.h>
#include <dos/dos.h>
#include <clib/exec_protos.h>
#include <clib/alib_protos.h>
#include <clib/alib_stdio_protos.h>
#include <clib/commodities_protos.h>

#ifdef LATTICE
int CXBRK(void) { return(0); }  /* Disable Lattice CTRL/C handling */
int chkabort(void) { return(0); }
#endif

void main(void);
void ProcessMsg(void);

struct Library *CxBase;

CxObj *broker;
struct MsgPort *broker_mp;
ULONG cxsigflag;

struct NewBroker newbroker = {
    NB_VERSION,   /* nb_Version - Version of the NewBroker structure */
    "RKM broker", /* nb_Name - Name Commodities uses to identify this commodity */
    "Broker",     /* nb_Title - Title of commodity that appears in CXExchange */
    "A simple example of a broker",  /* nb_Descr - Description of the commodity */
    0,            /* nb_Unique - Tells CX not to launch another commodity with same name */
    0,            /* nb_Flags - Tells CX if this commodity has a window */
    0,            /* nb_Pri - This commodity's priority */
    0,            /* nb_Port - MsgPort CX talks to */
    0             /* nb_ReservedChannel - reserved for later use */
};


void main(void)
{
```c
    CxMsg *msg;

    /* Before bothering with anything else, open the library */
    if (CxBase = OpenLibrary("commodities.library", 37L))
    {
        /* Commodities talks to a Commodities application through */
        /* an Exec Message port, which the application provides   */
        if (broker_mp = CreateMsgPort())
        {
            newbroker.nb_Port = broker_mp;

            /* The commodities.library function CxBroker() adds a borker to the
             * master list.  It takes two arguments, a pointer to a NewBroker
             * structure and a pointer to a LONG.  The NewBroker structure contains
             * information to set up the broker.  If the second argument is not
             * NULL, CxBroker will fill it in with an error code.
             */
            if (broker = CxBroker(&newbroker, NULL))
            {
                cxsigflag = 1L << broker_mp->mp_SigBit;

                /* After it's set up correctly, the broker has to be activated */
                ActivateCxObj(broker, 1L);

                /* the main processing loop */
                ProcessMsg();

                /* It's time to clean up.  Start by removing the broker from the
                 * Commodities master list.  The DeleteCxObjAll() function will
                 * take care of removing a CxObject and all those connected
                 * to it from the Commodities network
                 */
                DeleteCxObj(broker);

                /* Empty the port of CxMsgs */
                while(msg = (CxMsg *)GetMsg(broker_mp))
                	ReplyMsg((struct Message *)msg);
            }
            DeletePort(broker_mp);
        }
        CloseLibrary(CxBase);
    }
```
}


void ProcessMsg(void)
{
```c
    CxMsg *msg;

    ULONG sigrcvd, msgid, msgtype;
    LONG returnvalue = 1L;

    while (returnvalue)
    {
        /* wait for something to happen */
        sigrcvd = Wait(SIGBREAKF_CTRL_C | cxsigflag);

        /* process any messages */
        while(msg = (CxMsg *)GetMsg(broker_mp))
        {
            /* Extract necessary information from the CxMessage and return it */
            msgid = CxMsgID(msg);
            msgtype = CxMsgType(msg);
            ReplyMsg((struct Message *)msg);

            switch(msgtype)
            {
                case CXM_IEVENT:
                    /* Shouldn't get any of these in this example */
                    break;
                case CXM_COMMAND:
                    /* Commodities has sent a command */
                    printf("A command: ");
                    switch(msgid)
                    {
                        case CXCMD_DISABLE:
                            printf("CXCMD_DISABLE\n");
                            /* The user clicked Commodities Exchange disable
                             * gadget better disable
                             */
                            ActivateCxObj(broker, 0L);
                            break;
                        case CXCMD_ENABLE:
                            /* user clicked enable gadget */
                            printf("CXCMD_ENABLE\n");
                            ActivateCxObj(broker, 1L);
                            break;
                        case CXCMD_KILL:
                            /* user clicked kill gadget, better quit */
                            printf("CXCMD_KILL\n");
                            returnvalue = 0L;
                            break;
                    }
                    break;
                default:
                    printf("Unknown msgtype\n");
                    break;
            }
        }
        /* Test to see if user tried to break */
        if (sigrcvd & SIGBREAKF_CTRL_C)
        {
            returnvalue = 0L;
            printf("CTRL C signal break\n");
        }
    }
```
}


/* Notice that Broker.c uses Ctrl-C as a break key.  The break key for
** any commodity should be Ctrl-C.
*/

---

## See Also

- [CreateMsgPort — exec.library](../autodocs/exec.library.md#createmsgport)
- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
- [CxMsgID — commodities.library](../autodocs/commodities.library.md#cxmsgid)
- [DeleteCxObjAll — commodities.library](../autodocs/commodities.library.md#deletecxobjall)
