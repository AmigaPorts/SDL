/* Source: ADCD 2.1
 * Section: commodities-library-cxobjerror
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/commodities-library-cxobjerror.md
 */

    When a function acting on an object fails, it records the failure
    in the object. This function returns the accumulated error value.
    The values are represented by flag bits defined in
    [<libraries/commodities.h>](../Includes_and_Autodocs_2._guide/node00F0.html). Several errors may be recorded by multiple
    bits in 'error'.

    The currently defined errors are:

    COERR_ISNULL
      The value of parameter 'co' was in fact NULL. This error
      means "the problem with the object you inquire about is
      that it failed to be created."

    COERR_NULLATTACH
      Using the commodities' list manipulation functions, an attempt was
      made to add a NULL object to the list belonging to 'co'. This allows
      a line of code as follows to exist in an error-tolerant program:

        AttachCxObj(filter,CxSender(myport,MY_ID));

    COERR_BADFILTER
      The most recent filter specification for a filter object
      was faulty. This happens if no sense can be made out of a
      description string, or if an input expression (IX) has an
      invalid format or version byte. When this bit is set in a
      filter's error field, the filter will match nothing, but this
      is not the proper way to "turn off" a filter, use [ActivateCxObj()](../Includes_and_Autodocs_2._guide/node019D.html).

    COERR_BADTYPE
      A type specific operation, such as [SetFilterIX()](../Includes_and_Autodocs_2._guide/node01B4.html), was called
      for object 'co', but 'co' isn't of the proper type.
