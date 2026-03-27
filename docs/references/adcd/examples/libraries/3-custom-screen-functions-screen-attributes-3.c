/* Source: ADCD 2.1
 * Section: 3-custom-screen-functions-screen-attributes
 * Library: libraries
 * ADCD reference: libraries/3-custom-screen-functions-screen-attributes.md
 */

    Task ID (returned by [FindTask()](../Libraries_Manual_guide/node02D0.html#line5)) and signal for notification that the
    last window has closed on a [public screen](../Libraries_Manual_guide/node00E6.html). Data for SA_PubSig is a
    long, unsigned value. Data for SA_PubTask is a pointer to a [Task](../Libraries_Manual_guide/node02BB.html)
    structure. These two tags are order dependent, and must be specified
    after the tag SA_PubName.
