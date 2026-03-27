/* Source: ADCD 2.1
 * Section: commodities-library-createcxobj
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/commodities-library-createcxobj.md
 */

    This function creates a commodity object of type 'type'. It is not
    proper to call this function directly. Each object creation routine
    except [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html) is defined as a macro in [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html)
    These are independently documented.

    All functions which operate on a commodity object are made with
    a reference to the thirty-two bit value returned by this function
    (or by [CxBroker()](../Includes_and_Autodocs_2._guide/node01A2.html)).
