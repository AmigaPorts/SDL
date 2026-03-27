/* Source: ADCD 2.1
 * Section: window-cl-window-getclass
 * Library: autodocs-3.5
 * ADCD reference: autodocs-3.5/window-cl-window-getclass.md
 */

       This function is only available in runtime linked version of the
       class, window.class and is not in the compiler linker library
       window_cl.lib.

       Obtains the pointer to the [Window](../Includes_and_Autodocs_3._guide/node05E0.html#line908) class for use with [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).
       This function always returns a valid pointer so you do not
       need to check it.  The reason is that if the library opens
       fine, then the pointer returned is already setup.  (Of course
       this implies that if opening the library fails, you shouldn't be
       calling this.)

       Note that this function does not create the class, that is done
       when the class library is opened.
