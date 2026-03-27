# 31 Commodities Exchange Library / Installing A Broker Object


The Commodities Exchange input handler maintains a master list of
[CxObjects](../Libraries_Manual_guide/node0401.html) to which it diverts input events using [CxMessages](../Libraries_Manual_guide/node0403.html).  The
CxObjects in this master list are a special type of CxObject called
brokers.  The only thing a broker CxObject does is divert CxMessages to
its own personal list of CxObjects.  A commodity creates a broker and
attaches other CxObjects to it.  These attached objects take care of the
actual input handler related work of the commodity and make up the
broker's personal list.

The first program listing, [Broker.c](../Libraries_Manual_guide/node0586.html), is a very simple example of a working
commodity.  It serves only to illustrate the basics of a commodity, not to
actually perform any useful function.  It shows how to set up a broker and
process commands from the controller program.

Besides opening commodities.library and creating an Exec message port,
setting up a commodity requires creating a broker.  The function
[CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html) creates a broker and adds it to the master list.


```c
    CxObj *CxBroker(struct NewBroker *nb, long *error);
```
[CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html)'s first argument is a pointer to a [NewBroker](../Includes_and_Autodocs_2._guide/node00F0.html#line47) structure:


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
is defined in <libraries/[commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line45)>.  The nb_Name, nb_Title, and
nb_Descr point to strings which hold the name, title, and description of
the broker.  The two bit fields, [nb_Unique](../Libraries_Manual_guide/node040C.html#line7) and [nb_Flags](../Libraries_Manual_guide/node0404.html#line9), toggle certain
features of Commodities Exchange based on their values.  They are
discussed in detail later in this chapter.

The nb_Pri field contains the broker's priority.  Commodities Exchange
inserts the broker into the master list based on this number.  Higher
priority brokers get [CxMessages](../Libraries_Manual_guide/node0403.html) before lower priority brokers.

[CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html)'s second argument is a pointer to a LONG.  If this pointer is
not NULL, CxBroker() fills in this field with one of the following error
return codes from <libraries/[commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line39)>:


    CBERR_OK        0        /* No error                         */
    CBERR_SYSERR    1        /* System error , no memory, etc    */
    CBERR_DUP       2        /* uniqueness violation             */
    CBERR_VERSION   3        /* didn't understand nb_VERSION     */
Once the broker object is created with [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html), it must be activated
with [ActivateCxObj()](../Includes_and_Autodocs_2._guide/node019D.html).


```c
    oldactivationvalue = LONG ActivateCxObj(CxObj *co,
                                            long newactivationvalue);
```
After successfully completing the initial set up and activating the
broker, a commodity can begin its input processing loop waiting for
[CxMessages](../Libraries_Manual_guide/node0403.html) to arrive.

