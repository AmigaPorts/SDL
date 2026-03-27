---
title: 31 Commodities Exchange Library / Installing A Broker Object
manual: libraries
chapter: libraries
section: 31-commodities-exchange-library-installing-a-broker-object
functions: [ActivateCxObj, CxBroker]
libraries: [commodities.library]
---

# 31 Commodities Exchange Library / Installing A Broker Object

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Commodities Exchange input handler maintains a master list of
[CxObjects](libraries/31-commodities-exchange-library-cxobjects.md) to which it diverts input events using [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md).  The
CxObjects in this master list are a special type of CxObject called
brokers.  The only thing a broker CxObject does is divert CxMessages to
its own personal list of CxObjects.  A commodity creates a broker and
attaches other CxObjects to it.  These attached objects take care of the
actual input handler related work of the commodity and make up the
broker's personal list.

The first program listing, [Broker.c](libraries/lib-examples-broker-c.md), is a very simple example of a working
commodity.  It serves only to illustrate the basics of a commodity, not to
actually perform any useful function.  It shows how to set up a broker and
process commands from the controller program.

Besides opening commodities.library and creating an Exec message port,
setting up a commodity requires creating a broker.  The function
[CxBroker()](autodocs-2.0/commodities-library-cxbroker.md) creates a broker and adds it to the master list.


```c
    CxObj *CxBroker(struct NewBroker *nb, long *error);
```
[CxBroker()](autodocs-2.0/commodities-library-cxbroker.md)'s first argument is a pointer to a [NewBroker](autodocs-2.0/includes-libraries-commodities-h.md) structure:


```c
    struct NewBroker {
        BYTE    nb_Version;
                    /* There is an implicit pad byte after this BYTE */
        BYTE    *nb_Name;
        BYTE    *nb_Title;
        BYTE    *nb_Descr;
        SHORT   nb_Unique;
        SHORT   nb_Flags;
        BYTE    nb_Pri;
                    /* There is an implicit pad byte after this BYTE */
        struct  MsgPort   *nb_Port;
        WORD    nb_ReservedChannel;
                    /* Unused, make zero for future compatibility */
    };
```
Commodities Exchange gets all the information it needs about the broker
from this structure.  NewBroker's nb_Version field contains the version
number of the NewBroker structure.  This should be set to NB_VERSION which
is defined in <libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>.  The nb_Name, nb_Title, and
nb_Descr point to strings which hold the name, title, and description of
the broker.  The two bit fields, [nb_Unique](libraries/31-commodities-exchange-library-uniqueness.md) and [nb_Flags](libraries/31-cxmessages-controller-commands.md), toggle certain
features of Commodities Exchange based on their values.  They are
discussed in detail later in this chapter.

The nb_Pri field contains the broker's priority.  Commodities Exchange
inserts the broker into the master list based on this number.  Higher
priority brokers get [CxMessages](libraries/31-commodities-exchange-library-cxmessages.md) before lower priority brokers.

[CxBroker()](autodocs-2.0/commodities-library-cxbroker.md)'s second argument is a pointer to a LONG.  If this pointer is
not NULL, CxBroker() fills in this field with one of the following error
return codes from <libraries/[commodities.h](autodocs-2.0/includes-libraries-commodities-h.md)>:


    CBERR_OK        0        /* No error                         */
    CBERR_SYSERR    1        /* System error , no memory, etc    */
    CBERR_DUP       2        /* uniqueness violation             */
    CBERR_VERSION   3        /* didn't understand nb_VERSION     */
Once the broker object is created with [CxBroker()](autodocs-2.0/commodities-library-cxbroker.md), it must be activated
with [ActivateCxObj()](autodocs-2.0/commodities-library-activatecxobj.md).


```c
    oldactivationvalue = LONG ActivateCxObj(CxObj *co,
                                            long newactivationvalue);
```
After successfully completing the initial set up and activating the
broker, a commodity can begin its input processing loop waiting for
[CxMessages](libraries/31-commodities-exchange-library-cxmessages.md) to arrive.

---

## See Also

- [ActivateCxObj — commodities.library](../autodocs/commodities.library.md#activatecxobj)
- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
