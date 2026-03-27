/* Source: ADCD 2.1
 * Section: getfont-gadget-getfont-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/getfont-gadget-getfont-getclass.md
 */

       Obtains the pointer to the getfont gadget class for use with
       [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).  This function always returns a valid pointer so
       you do not need to check it.  The reason is that if the library
       opens fine, then the pointer returned is already setup.  (Of course
       this implies that if opening the library fails, you shouldn't be
       calling this.)

       Note that this function does not create the class, that is done
       when the class library is opened.
