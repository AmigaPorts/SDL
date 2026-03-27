/* Source: ADCD 2.1
 * Section: commodities-library-cxbroker
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/commodities-library-cxbroker.md
 */

    This function creates a broker from the specification found in the
    [NewBroker](../Includes_and_Autodocs_2._guide/node00F0.html#line47) structure pointed to by 'nb'. The purpose and meaning of the
    fields of the [NewBroker](../Includes_and_Autodocs_2._guide/node00F0.html#line47) structure are described below. Also see
    [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html) for more info.

    struct [NewBroker](../Includes_and_Autodocs_2._guide/node00F0.html#line47)
    {
       BYTE            nb_Version;
       BYTE           *nb_Name;
       BYTE           *nb_Title;
       BYTE           *nb_Descr;
       SHORT           nb_Unique;
       BYTE            nb_Pri;
        struct [MsgPort](../Includes_and_Autodocs_2._guide/node0099.html#line29) *nb_Port;
        WORD            nb_ReservedChannel;
    };

    nb_Version
    This is the way that future versions of commodities.library
    can identify which version of the [NewBroker](../Includes_and_Autodocs_2._guide/node00F0.html#line47) structure you are using.
    This should be set to NB_VERSION, defined in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html)

    nb_Name
    This is the name of the broker. This name is used to find the broker
    in the Commodities Object [List](../Includes_and_Autodocs_2._guide/node007D.html#line21) and is the name shown in the list
    gadget of the Exchange program. The name string is copied in the
    broker object upon creation, so this string can be discarded right
    after CxBroker() returns. The maximum length of the name string is
    defined by a constant in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).

    nb_Title, nb_Descr
    These are two strings which appear to the user in the Exchange
    program and describe the application the broker is representing.
    Note that these strings are copied into the broker object.
    The maximum length of these strings that will be recognized are
    defined by constants in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html).

    nb_Unique
    This field indicates what should happen if a broker of the same name
    (nb_Name) already exists in the Commodities Object [List](../Includes_and_Autodocs_2._guide/node007D.html#line21). Constants
    in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html) allow the caller to specify whether
    another broker is to be created, and whether any existing broker of
    the same name should be notified that an attempt at creating a
    duplicate has been made.

    nb_Pri
    This specifies with what priority the new broker is to be inserted
    within the Commodities Object [List](../Includes_and_Autodocs_2._guide/node007D.html#line21). Higher priority nodes appear
    earlier in a list. See [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html) for guidelines for
    priorities of different types of applications. It is strongly
    recommended that the ToolTypes environment of an application be used
    to allow the end-user to set the priority of the broker.
