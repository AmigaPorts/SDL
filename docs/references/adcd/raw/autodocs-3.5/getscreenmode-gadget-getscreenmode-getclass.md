# getscreenmode.gadget/GETSCREENMODE_GetClass



   NAME

       GETSCREENMODE_GetClass -- Gets the pointer to the screenmode
                                 requester class
   SYNOPSIS

```c
       getscreenmode_class = GETSCREENMODE_GetClass();
       D0

       Class * GETSCREENMODE_GetClass( void );
```
   FUNCTION

```c
       Obtains the pointer to the getscreenmode gadget class for use with
       [NewObject()](../Includes_and_Autodocs_3._guide/node03CB.html).  This function always returns a valid pointer so
       you do not need to check it.  The reason is that if the library
       opens fine, then the pointer returned is already setup.  (Of course
       this implies that if opening the library fails, you shouldn't be
       calling this.)

       Note that this function does not create the class, that is done
       when the class library is opened.
```
   INPUTS

   RESULT

       getscreenmode_class - Pointer to the getscreenmode gadget class.
   EXAMPLE

   NOTES

   BUGS

   SEE ALSO

