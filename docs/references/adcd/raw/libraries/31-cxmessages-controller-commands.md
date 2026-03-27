# 31 / CxMessages / Controller Commands


The commands that a commodity can receive from the controller program (as
defined in <libraries/[commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line121)>) are:


    CXCMD_DISABLE     /* please disable yourself       */
    CXCMD_ENABLE      /* please enable yourself        */
    CXCMD_KILL        /* go away for good              */
    CXCMD_APPEAR      /* open your window, if you can  */
    CXCMD_DISAPPEAR   /* hide your window              */
The CXCMD_DISABLE, CXCMD_ENABLE, and CXCMD_KILL commands correspond to the
similarly named controller program gadgets, Disable, Enable, and Kill;
CXCMD_APPEAR and CXCMD_DISAPPEAR correspond to the controller program
gadgets, Show and Hide.  These gadgets are ghosted in [Broker.c](../Libraries_Manual_guide/node0586.html) because it
has no window (It doesn't make much sense to give the user a chance to
click the Show and Hide gadgets).  In order to do this, Broker.c  has to
tell Commodities Exchange to ghost these gadgets.  When [CxBroker()](../Libraries_Manual_guide/node0402.html#line14) sets up
a [broker](../Libraries_Manual_guide/node0402.html), it looks at the [NewBroker.nb_Flags](../Libraries_Manual_guide/node0402.html#line28) field to see if the
COF_SHOW_HIDE bit (from <libraries/[commodities.h](../Includes_and_Autodocs_2._guide/node00F0.html#line64)>) is set.  If it is, the
"Show" and "Hide" gadgets for this broker will be selectable.  Otherwise
they are ghosted and disabled.

