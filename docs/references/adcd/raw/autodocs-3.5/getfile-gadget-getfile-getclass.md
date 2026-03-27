# getfile.gadget/GETFILE_GetClass



   NAME

       GETFILE_GetClass -- Gets the pointer to the file requester class
   SYNOPSIS

```c
       getfile_class = GETFILE_GetClass();
       D0

       Class * GETFILE_GetClass( void );
```
   FUNCTION

```c
       Obtains the pointer to the getfile gadget class for use with
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

       getfile_class - Pointer to the getfile gadget class.
   EXAMPLE

   NOTES

```c
       The GFILE_REQUEST method will return 0 if no file is selected and
       the GETFILE_DrawersOnly tag is not used, even is the user selected
       the positive response in the requester. If a file is selected (the
       file gadget in the file requester is not empty), it will return 1.
```
   BUGS

   SEE ALSO

