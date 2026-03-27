/* Source: ADCD 2.1
 * Section: commodities-library-createcxobj
 * Library: autodocs-2.0
 * ADCD reference: autodocs-2.0/commodities-library-createcxobj.md
 */

    co - a pointer to the new object or NULL if it could not be created.
         A NULL return indicates typically a lack of system memory. Minor
         problems in creating an object, such as providing a bad filter
         description to [cx_lib/CxFilter()](../Includes_and_Autodocs_2._guide/node014D.html), typically don't cause failure,
         but are recorded in an internal error field in the new object
         which can be accessed via [CxObjError()](../Includes_and_Autodocs_2._guide/node01A6.html).
