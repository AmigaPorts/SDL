---
title: Installing a Broker
manual: amiga-mail
chapter: amiga-mail
section: installing-a-broker
functions: [CxBroker]
libraries: [commodities.library]
---

# Installing a Broker

> *Source: Amiga Developer CD v2.1. (C) Commodore-Amiga / Amiga Inc.*

The Commodities Exchange input handler maintains a master list of
CxObjects to which it diverts input events using CxMessages.  The
CxObjects in this master list are a special type of CxObject called a
broker.  The only thing a broker CxObject does is div ert CxMessages
to its own personal list of CxObjects.  A commodity creates a broker
and attaches other CxObjects to it.  These attached objects take care
of the actual input handler related work of the commodity and make up
the broker's personal list.

Program listing 1, [Broker.c](amiga-mail/xi-1-broker-c.md), (located at the end of this article) is a
very simple example of a working commodity.  It serves only to
illustrate the basics of a commodity, not to actually perform any
useful function.  It shows how to set up a broker and p rocess
commands from the controller program.

Besides opening commodities.library and creating an Exec message
port, setting up a commodity requires creating a broker.  The
function CxBroker() creates a broker and adds it to the master list.


```c
    CxObj *CxBroker(struct NewBroker *nb, long *error);
```
CxBroker()'s first argument is a pointer to a NewBroker structure:


```c
    struct NewBroker {
       BYTE     nb_Version;  /* There's an implicit pad byte after */
       BYTE     *nb_Name;    /*     this BYTE */
       BYTE     *nb_Title;
       BYTE     *nb_Descr;
       SHORT    nb_Unique;
       SHORT    nb_Flags;
       BYTE     nb_Pri; /* There's an implicit pad byte after this BYTE */
       struct   MsgPort   *nb_Port;
       WORD     nb_ReservedChannel;
    };
```
Commodities Exchange gets all the information it needs about the
broker from this structure.  NewBroker's nb_Version field contains
the version number of the NewBroker structure.  This should be set to
NB_VERSION which is defined in <libraries/commodities .h>.  The
nb_Name, nb_Title, and nb_Descr point to strings which hold the name,
title, and description of the broker.  The two bit fields, nb_Unique
and nb_Flags, toggle certain features of Commodities Exchange based
on their values.  They are discussed in detail later in this article.

The nb_Pri field contains the broker's priority.  Commodities Exchange
inserts the broker into the master list based on this number.  Higher
priority brokers get CxMessages before lower priority brokers.

CxBroker()'s second argument is a pointer to a LONG.  If this pointer
is not NULL, CxBroker() fills in this field with one of the following
codes from <libraries/commodities.h>:


    CBERR_OK        0        /* No error                         */
    CBERR_SYSERR    1        /* System error , no memory, etc    */
    CBERR_DUP       2        /* uniqueness violation             */
    CBERR_VERSION   3        /* didn't understand nb_VERSION     */

---

## See Also

- [CxBroker — commodities.library](../autodocs/commodities.library.md#cxbroker)
